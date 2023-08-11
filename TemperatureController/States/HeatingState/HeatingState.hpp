#pragma once
#include <State.hpp>

class HeatingState : public State
{
public:
    HeatingState(TemperatureControllerContext * ctx);

    virtual ~HeatingState() = default;

    void onEntry();
    void onExit();

    State::StateEnum process();
};