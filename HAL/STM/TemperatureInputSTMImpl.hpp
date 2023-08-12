#pragma once

#include <TemperatureInput.hpp>

class TemperatureInputSTMImpl : public TemperatureInput
{
public:
    TemperatureInputSTMImpl(int pin);
    float read() override;
};