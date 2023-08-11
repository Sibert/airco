#pragma once
#include <TemperatureControllerContext.hpp>
#include <assert.h>

class State
{
public:
    enum StateEnum {
        IDLE,
        COOLING,
        HEATING,
        NUM_OF_STATES
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