#include <TemperatureController.hpp>

TemperatureController::TemperatureController(TemperatureInput * minTempIn, TemperatureInput * maxTempIn, TemperatureInput * currentTempIn, Output * coolingOut, Output * heatingOut) 
:   m_pMinTempIn(minTempIn),
    m_pMaxTempIn(maxTempIn),
    m_pCurrentTempIn(currentTempIn),
    m_pCoolingOut(coolingOut),
    m_pHeatingOut(heatingOut)
{
    assert(m_pMinTempIn != nullptr);
    assert(m_pMaxTempIn != nullptr);
    assert(m_pCurrentTempIn != nullptr);

    assert(m_pCoolingOut != nullptr);
    assert(m_pHeatingOut != nullptr);
}

void TemperatureController::run()
{    
    float currentTemp = m_pCurrentTempIn->read();
    float minTemp = m_pMinTempIn->read();
    float maxTemp = m_pMaxTempIn->read();

    if(currentTemp < minTemp)
    {
        m_pCoolingOut->write(false);
        m_pHeatingOut->write(true);
    }
    else if(currentTemp > maxTemp)
    {
        m_pCoolingOut->write(true);
        m_pHeatingOut->write(false);
    }
    else
    {
        m_pCoolingOut->write(false);
        m_pHeatingOut->write(false);
    }
}