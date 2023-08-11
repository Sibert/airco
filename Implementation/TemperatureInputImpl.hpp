#pragma once

#include <TemperatureInput.hpp>

class TemperatureInputImpl : public TemperatureInput
{
public:
    TemperatureInputImpl(float initialValue);

    float read() override;

    void setValue(float value);
private:
    float m_value = 0;
};