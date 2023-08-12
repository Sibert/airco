#include <TemperatureInputImpl.hpp>

TemperatureInputLinuxImpl::TemperatureInputLinuxImpl(float initialValue) : m_value(initialValue)
{

}

float TemperatureInputLinuxImpl::read()
{
    return m_value;
}

void TemperatureInputLinuxImpl::setValue(float value)
{
    m_value = value;
}