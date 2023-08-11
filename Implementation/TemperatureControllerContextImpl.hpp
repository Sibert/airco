#pragma once

#include <TemperatureControllerContext.hpp>
#include <TemperatureInput.hpp>
#include <Output.hpp>
#include <iostream>

class TemperatureControllerContextImpl : public TemperatureControllerContext
{
public:
    TemperatureControllerContextImpl(
        TemperatureInput * minTemp, TemperatureInput * maxTemp, TemperatureInput * currentTemp, 
        Output * outCooling, Output * outHeating
    );

    float getMinTemp() override;
    float getCurrentTemp() override;
    float getMaxTemp() override;

    void enableCooling() override;
    void disableCooling() override;

    void enableHeating() override;
    void disableHeating() override;

    void refreshContext();

private:

    TemperatureInput * m_pMinTempIn = nullptr;
    TemperatureInput * m_pMaxTempIn = nullptr;
    TemperatureInput * m_pCurrentTempIn = nullptr;

    float m_lastMinTemp = 0;
    float m_lastMaxTemp = 0;
    float m_lastCurrentTemp = 0;

    Output * m_pOutCooling = nullptr;
    Output * m_pOutHeating = nullptr;
};