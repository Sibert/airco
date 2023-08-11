#pragma once

#include <Output.hpp>

class OutputImpl : public Output
{
public:
    OutputImpl(bool initialValue = false);

    void write(bool value) override;
    bool read() override;
private:
    bool m_value = false;
};