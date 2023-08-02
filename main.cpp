#include <iostream>
#include <thread>
#include <Menu.hpp>
#include <TemperatureController.hpp>

using namespace std;

float currTemp = 20.0;
float minTemp = 18.0;
float maxTemp = 25.0;

void inputThread();

int main(int, char**)
{
    std::thread inputTask(inputThread);

    TemperatureController controller(currTemp, maxTemp, minTemp);

    while(true)
    {
        controller.run();

        this_thread::sleep_for(100ms);
    }
}

void inputThread()
{
    Menu menu(currTemp, maxTemp, minTemp);

    while(true)
    {
        cout << "Current temperature: " << currTemp << "°C" << endl;
        cout << "Minimum temperature: " << minTemp << "°C" << endl;
        cout << "Maximum temperature: " << maxTemp << "°C" << endl;
        
        menu.printMenu();
        menu.run();

        this_thread::sleep_for(100ms);
    }
}

