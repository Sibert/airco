#include <iostream>
#include <TemperatureController.hpp>
#include <TemperatureInput.hpp>
#include <Output.hpp>
#include <thread>
#include <chrono>
#include <HALImpl.hpp>

HALInterface * hal;

int main(int, char**)
{ 
    hal = (HALInterface*)new HALImpl();
    hal->initializeHAL();

    TemperatureInput * current = hal->getTemperatureInput(HALInterface::CURRENT);
    TemperatureInput * min = hal->getTemperatureInput(HALInterface::MINIMUM);
    TemperatureInput * max = hal->getTemperatureInput(HALInterface::MAXIMUM);

    Output * coolingOut = hal->getOutput(HALInterface::COOLING);
    Output * heatingOut = hal->getOutput(HALInterface::HEATING);

    TemperatureController controller(min, max, current, coolingOut, heatingOut);

    while(1)
    {
        controller.run();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    delete hal;
}