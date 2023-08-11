#pragma once
#include <State.hpp>

class IdleState : public State
{
public:
    IdleState(TemperatureControllerContext * ctx);

    virtual ~IdleState() = default;

    void onEntry();
    void onExit();

    State::StateEnum process();
};