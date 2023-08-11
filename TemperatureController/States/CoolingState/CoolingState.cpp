#include <CoolingState.hpp>

CoolingState::CoolingState(TemperatureControllerContext *ctx) : State(State::COOLING, ctx)
{
}

void CoolingState::onEntry()
{
    m_pCtx->enableCooling();
}

void CoolingState::onExit()
{
    m_pCtx->disableCooling();
}

State::StateEnum CoolingState::process()
{
    float currentTemp = m_pCtx->getCurrentTemp();

    if(currentTemp > m_pCtx->getMinTemp() && currentTemp < m_pCtx->getMaxTemp())
    {
        return State::IDLE;
    }

    if(currentTemp < m_pCtx->getMinTemp())
    {
        return State::HEATING;
    }

    return m_stateIdentity;
}