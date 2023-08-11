#pragma once
#include <TemperatureControllerContext.hpp>

class State
{
public:
    enum StateEnum {
        IDLE,
        COOLING,
        HEATING
    };

    virtual ~State() = default;

    virtual void onEntry() = 0;
    virtual void onExit() = 0;

    virtual StateEnum process() = 0;

protected:
    State(StateEnum stateIdentity, TemperatureControllerContext * ctx);

    StateEnum m_stateIdentity;

    TemperatureControllerContext * m_pCtx;

};