#include <HALInterface.hpp>

Output * HALInterface::getOutput(HALInterface::HALOutput out)
{
    if(m_outputs.count(out) > 0)
    {
        return m_outputs[out];
    }

    return nullptr;
}

TemperatureInput * HALInterface::getTemperatureInput(HALInterface::HALTemperatureInput in)
{
    if(m_temperatureInputs.count(in) > 0)
    {
        return m_temperatureInputs[in];
    }

    return nullptr;
}