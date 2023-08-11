#include <gtest/gtest.h>
#include <StateTest.hpp>
#include <IdleState.hpp>
#include <gmock/gmock.h>

class IdleStateTest : public TemperatureControllerStateTest
{
protected:
    void SetUp() override
    {
        m_pState = new IdleState(&m_ctx);
    }
};


TEST_F(IdleStateTest, keepIdling_not_equal)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(25);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::IDLE);
}

TEST_F(IdleStateTest, keepIdling_equal)
{
    m_ctx.setMinTemp(25);
    m_ctx.setCurrentTemp(25);
    m_ctx.setMaxTemp(25);

    EXPECT_EQ(m_pState->process(), State::IDLE);
}

TEST_F(IdleStateTest, startHeating)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(19);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::HEATING);
}

TEST_F(IdleStateTest, startCooling)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(50);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::COOLING);
}

