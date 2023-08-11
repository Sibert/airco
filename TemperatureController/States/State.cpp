#include <State.hpp>

State::State(State::StateEnum stateIdentity, TemperatureControllerContext * ctx) : m_stateIdentity(stateIdentity), m_pCtx(ctx)
{

}