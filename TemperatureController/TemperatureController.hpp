#pragma once

#include <iostream>

class TemperatureController
{
public:
    enum State {
        IDLE,
        COOLING,
        HEATING
    };

    TemperatureController(float & input, float & upperLimit, float & lowerLimit);
    
    State run();
private:
    float & m_input;
    float & m_upperLimit;
    float & m_lowerLimit;

    State m_currentState = IDLE;

    void printChange(std::string msg);
};