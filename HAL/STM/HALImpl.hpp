#pragma once

#include <HALInterface.hpp>
#include <OutputSTMImpl.hpp>
#include <TemperatureInputSTMImpl.hpp>

class HALImpl : public HALInterface
{
public:
    HALImpl() = default;
    ~HALImpl();

    void initializeHAL();
private:
    TemperatureInputSTMImpl * m_pMinTempIn;
    TemperatureInputSTMImpl * m_pMaxTempIn;
    TemperatureInputSTMImpl * m_pcurrTemp;

    OutputSTMImpl * m_pCoolingOut;
    OutputSTMImpl * m_pHeatingOut;
};