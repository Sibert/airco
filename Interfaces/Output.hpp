#pragma once

class Output
{
public:
    virtual void write(bool value) = 0;
    virtual bool read() = 0;
};