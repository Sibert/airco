#include <HALImpl.hpp>


HALImpl::~HALImpl()
{
    delete m_pMinTempIn;
    delete m_pMaxTempIn;
    delete m_pcurrTemp;

    delete m_pCoolingOut;
    delete m_pHeatingOut;
}

void HALImpl::initializeHAL()
{
    m_pMinTempIn = new TemperatureInputSTMImpl(0);
    m_pMaxTempIn = new TemperatureInputSTMImpl(1);
    m_pcurrTemp = new TemperatureInputSTMImpl(2);

    m_pCoolingOut = new OutputSTMImpl(4);
    m_pHeatingOut = new OutputSTMImpl(5);
}