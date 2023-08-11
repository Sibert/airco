#include <gtest/gtest.h>
#include <TemperatureControllerContext.hpp>
#include <State.hpp>
#include <gmock/gmock.h>

class MockTemperatureControllerContext : public TemperatureControllerContext 
{
public:
    void setMinTemp(float value) { m_minTemp = value; }
    void setCurrentTemp(float value) { m_currentTemp = value; }
    void setMaxTemp(float value) { m_maxTemp = value; }

    float getMinTemp() override { return m_minTemp; }
    float getCurrentTemp() override { return m_currentTemp; }
    float getMaxTemp() override { return m_maxTemp; }

    MOCK_METHOD(void, enableCooling, (), (override));
    MOCK_METHOD(void, disableCooling, (), (override));

    MOCK_METHOD(void, enableHeating, (), (override));
    MOCK_METHOD(void, disableHeating, (), (override));

private:
    float m_minTemp;
    float m_currentTemp;
    float m_maxTemp;
};

class TemperatureControllerStateTest : public ::testing::Test
{
public:
    TemperatureControllerStateTest() : m_ctx() {}
protected:
    MockTemperatureControllerContext m_ctx;
    State * m_pState = nullptr;

    void TearDown() override
    {
        delete m_pState;
    }
};