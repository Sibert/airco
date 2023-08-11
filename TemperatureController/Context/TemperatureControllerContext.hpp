#pragma once
class TemperatureControllerContext
{
public:
    virtual float getMinTemp() = 0;
    virtual float getCurrentTemp() = 0;
    virtual float getMaxTemp() = 0;

    virtual void enableCooling() = 0;
    virtual void disableCooling() = 0;

    virtual void enableHeating() = 0;
    virtual void disableHeating() = 0;
};