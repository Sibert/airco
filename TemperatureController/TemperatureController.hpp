#pragma once

#include <assert.h>
#include <iostream>
#include <Output.hpp>
#include <TemperatureInput.hpp>

class TemperatureController
{
public:
    TemperatureController(TemperatureInput * minTempIn, TemperatureInput * maxTempIn, TemperatureInput * currentTempIn, Output * coolingOut, Output * heatingOut);

    void run();
private:
    TemperatureInput * m_pMinTempIn = nullptr;
    TemperatureInput * m_pMaxTempIn = nullptr;
    TemperatureInput * m_pCurrentTempIn = nullptr;
    Output * m_pCoolingOut = nullptr;
    Output * m_pHeatingOut = nullptr;
};