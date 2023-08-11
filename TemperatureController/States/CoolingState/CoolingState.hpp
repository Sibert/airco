#pragma once
#include <State.hpp>

class CoolingState : public State
{
public:
    CoolingState(TemperatureControllerContext * ctx);

    virtual ~CoolingState() = default;

    void onEntry();
    void onExit();

    State::StateEnum process();
};