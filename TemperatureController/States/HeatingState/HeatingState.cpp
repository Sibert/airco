#include <HeatingState.hpp>

HeatingState::HeatingState(TemperatureControllerContext *ctx) : State(State::HEATING, ctx)
{
    assert(ctx != nullptr);
}

void HeatingState::onEntry()
{
    m_pCtx->enableHeating();
}

void HeatingState::onExit()
{
    m_pCtx->disableHeating();
}

State::StateEnum HeatingState::process()
{
    float currentTemp = m_pCtx->getCurrentTemp();

    if(currentTemp > m_pCtx->getMinTemp() && currentTemp < m_pCtx->getMaxTemp())
    {
        return State::IDLE;
    }

    if(currentTemp > m_pCtx->getMaxTemp())
    {
        return State::COOLING;
    }

    return m_stateIdentity;
}