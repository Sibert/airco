#pragma once

#include <Output.hpp>

class OutputSTMImpl : public Output
{
public:
    OutputSTMImpl(int pin);
    
    void write(bool value) override;
    bool read() override;
};