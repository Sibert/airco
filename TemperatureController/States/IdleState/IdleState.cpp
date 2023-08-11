#include <IdleState.hpp>

IdleState::IdleState(TemperatureControllerContext * ctx) : State(State::IDLE, ctx)
{
    assert(ctx != nullptr);
}

void IdleState::onEntry()
{
    m_pCtx->disableHeating();
    m_pCtx->disableCooling();
}

void IdleState::onExit()
{
    // do nothing
}

State::StateEnum IdleState::process()
{
    float currentTemp = m_pCtx->getCurrentTemp();

    if(currentTemp < m_pCtx->getMinTemp())
    {
        return State::HEATING;
    }

    if(currentTemp > m_pCtx->getMaxTemp())
    {
        return State::COOLING;
    }

    return State::IDLE;
}