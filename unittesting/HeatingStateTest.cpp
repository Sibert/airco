#include <gtest/gtest.h>
#include <StateTest.hpp>
#include <HeatingState.hpp>
#include <gmock/gmock.h>

class HeatingStateTest : public TemperatureControllerStateTest
{
protected:
    void SetUp() override
    {
        m_pState = new HeatingState(&m_ctx);
    }
};

TEST_F(HeatingStateTest, onEntry)
{
    EXPECT_CALL(m_ctx, enableHeating());
    m_pState->onEntry();
}

TEST_F(HeatingStateTest, onExit)
{
    EXPECT_CALL(m_ctx, disableHeating());
    m_pState->onExit();
}

TEST_F(HeatingStateTest, keepHeating_notEqual)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(15);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::HEATING);
}

TEST_F(HeatingStateTest, keepHeating_equal)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(20);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::HEATING);
}

TEST_F(HeatingStateTest, startIdle)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(25);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::IDLE);
}

TEST_F(HeatingStateTest, startCooling)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(35);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::COOLING);
}