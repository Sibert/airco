#include <TemperatureInputImpl.hpp>

TemperatureInputImpl::TemperatureInputImpl(float initialValue) : m_value(initialValue)
{

}

float TemperatureInputImpl::read() 
{
    return m_value;
}

void TemperatureInputImpl::setValue(float value)
{
    m_value = value;
}