#include <iostream>
#include <thread>
#include <Menu.hpp>
#include <map>
#include <State.hpp>
#include <TemperatureControllerContextImpl.hpp>
#include <TemperatureInputImpl.hpp>
#include <OutputImpl.hpp>
#include <CoolingState.hpp>
#include <HeatingState.hpp>
#include <IdleState.hpp>
#include <assert.h>

using namespace std;

TemperatureInputImpl * minTemp = nullptr;
TemperatureInputImpl * maxTemp = nullptr;
TemperatureInputImpl * currentTemp = nullptr;

OutputImpl * coolingOutput = nullptr;
OutputImpl * heatingOutput = nullptr;

map<State::StateEnum, State*> STATE_MAP;

void inputThread();

int main(int, char**)
{
    std::thread inputTask(inputThread);

    minTemp = new TemperatureInputImpl(20.0);
    maxTemp = new TemperatureInputImpl(30.0);
    currentTemp = new TemperatureInputImpl(25.0);

    coolingOutput = new OutputImpl();
    heatingOutput = new OutputImpl();

    TemperatureControllerContextImpl ctx(minTemp, maxTemp, currentTemp, coolingOutput, heatingOutput);

    STATE_MAP = {
        { State::IDLE, new IdleState(&ctx) },
        { State::COOLING, new CoolingState(&ctx) },
        { State::HEATING, new HeatingState(&ctx) }
    };

    // Check if an instance of each state is present
    for (int i = 0; i < State::NUM_OF_STATES; i++)
    {
        assert(STATE_MAP.count((State::StateEnum)i) == 1);
    }

    State::StateEnum currentState = State::IDLE;

    while(true)
    {
        ctx.refreshContext();

        State::StateEnum nextState = STATE_MAP[currentState]->process();

        if(nextState != currentState)
        {
            STATE_MAP[currentState]->onExit();
            STATE_MAP[nextState]->onEntry();
            currentState = nextState;
        }

        this_thread::sleep_for(100ms);
    }

    delete minTemp;
    delete maxTemp;
    delete currentTemp;

    delete coolingOutput;
    delete heatingOutput;
}

void inputThread()
{
    Menu menu(minTemp, maxTemp, currentTemp);

    while(true)
    {
        cout << "Current temperature: " << currentTemp->read() << "°C" << endl;
        cout << "Minimum temperature: " << minTemp->read() << "°C" << endl;
        cout << "Maximum temperature: " << maxTemp->read() << "°C" << endl;
        
        menu.printMenu();
        menu.run();

        this_thread::sleep_for(100ms);
    }
}

