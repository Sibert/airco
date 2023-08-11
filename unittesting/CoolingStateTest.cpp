#include <gtest/gtest.h>
#include <StateTest.hpp>
#include <CoolingState.hpp>
#include <gmock/gmock.h>

class CoolingStateTest : public TemperatureControllerStateTest
{
protected:
    void SetUp() override
    {
        m_pState = new CoolingState(&m_ctx);
    }
};

TEST_F(CoolingStateTest, onEntry)
{
    EXPECT_CALL(m_ctx, enableCooling());
    m_pState->onEntry();
}

TEST_F(CoolingStateTest, onExit)
{
    EXPECT_CALL(m_ctx, disableCooling());
    m_pState->onExit();
}

TEST_F(CoolingStateTest, keepCooling_notEqual)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(50);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::COOLING);
}

TEST_F(CoolingStateTest, keepCooling_equal)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(30);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::COOLING);
}

TEST_F(CoolingStateTest, startIdle)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(25);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::IDLE);
}

TEST_F(CoolingStateTest, startHeating)
{
    m_ctx.setMinTemp(20);
    m_ctx.setCurrentTemp(15);
    m_ctx.setMaxTemp(30);

    EXPECT_EQ(m_pState->process(), State::HEATING);
}