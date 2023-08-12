#pragma once

#include <string>
#include <iostream>
#include <Output.hpp>

class OutputLinuxImpl : public Output
{
public:
    OutputLinuxImpl(std::string outputName, bool initialValue = false);

    void write(bool value);
    bool read();

private:
    std::string m_name;
    bool m_value;
};