#pragma once

#include <TemperatureInput.hpp>
#include <Output.hpp>
#include <map>

class HALInterface 
{
public:
    enum HALOutput {
        COOLING,
        HEATING
    };

    enum HALTemperatureInput
    {
        MINIMUM,
        MAXIMUM,
        CURRENT,
    };

    ~HALInterface() = default;


    Output * getOutput(HALOutput out);
    TemperatureInput * getTemperatureInput(HALTemperatureInput in);

    virtual void initializeHAL() = 0;

protected:
    std::map<HALOutput, Output *> m_outputs;
    std::map<HALTemperatureInput, TemperatureInput *> m_temperatureInputs;
};