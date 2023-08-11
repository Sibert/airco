#include <TemperatureControllerContextImpl.hpp>

TemperatureControllerContextImpl::TemperatureControllerContextImpl(
    TemperatureInput * minTemp, TemperatureInput * maxTemp, TemperatureInput * currentTemp, 
    Output * outCooling, Output * outHeating
) : m_pMinTempIn(minTemp),
    m_pMaxTempIn(maxTemp),
    m_pCurrentTempIn(currentTemp),
    m_pOutCooling(outCooling),
    m_pOutHeating(outHeating)

{
    assert(minTemp != nullptr);
    assert(maxTemp != nullptr);
    assert(currentTemp != nullptr);

    assert(outCooling != nullptr);
    assert(outHeating != nullptr);

}

void TemperatureControllerContextImpl::refreshContext()
{
    m_lastMinTemp = m_pMinTempIn->read();
    m_lastMaxTemp = m_pMaxTempIn->read();
    m_lastCurrentTemp = m_pCurrentTempIn->read();
}


float TemperatureControllerContextImpl::getMinTemp()
{
    return m_lastMinTemp;
}

float TemperatureControllerContextImpl::getCurrentTemp()
{
    return m_lastCurrentTemp;
}


float TemperatureControllerContextImpl::getMaxTemp()
{
    return m_lastMaxTemp;
}

void TemperatureControllerContextImpl::enableCooling()
{
    std::cout << "*************** ACTION ***************" << std::endl;
    std::cout << "Enable cooling" << std::endl << std::endl;
    m_pOutCooling->write(true);
}

void TemperatureControllerContextImpl::disableCooling()
{
    std::cout << "*************** ACTION ***************" << std::endl;
    std::cout << "Disable cooling" << std::endl << std::endl;
    m_pOutCooling->write(false);
}

void TemperatureControllerContextImpl::enableHeating()
{
    std::cout << "*************** ACTION ***************" << std::endl;
    std::cout << "Enable heating" << std::endl << std::endl;
    m_pOutHeating->write(true);
}

void TemperatureControllerContextImpl::disableHeating()
{
    std::cout << "*************** ACTION ***************" << std::endl;
    std::cout << "Disable heating" << std::endl << std::endl;
    m_pOutHeating->write(false);
}