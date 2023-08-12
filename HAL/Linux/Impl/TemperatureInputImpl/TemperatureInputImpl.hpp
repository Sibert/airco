#pragma once

#include <TemperatureInput.hpp>

class TemperatureInputLinuxImpl : public TemperatureInput
{
public:
    TemperatureInputLinuxImpl(float initialValue);

    float read();
    
    void setValue(float value);
private:
    float m_value;
};