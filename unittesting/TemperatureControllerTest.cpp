#include <gtest/gtest.h>
#include <TemperatureController.hpp>

class TemperatureControllerTest : public::testing::Test
{
public:
    inline static float TEST_RANGE_LOWER = -20.0;
    inline static float TEST_RANGE_UPPER = 50.0;

    void setCurrent(float current)
    {
        m_current = current;
    }

    void setMin(float min)
    {
        m_min = min;
    }

    void setMax(float max)
    {
        m_max = max;
    }

    TemperatureController::State runAndGetState()
    {
        return m_controller->run();
    }

protected:
    TemperatureController * m_controller;
    float m_current;
    float m_max;
    float m_min;
    
    void SetUp() override
    {
        m_controller = new TemperatureController(m_current, m_max, m_min);
    }

    void TearDown() override
    {
        delete m_controller;
    }
};

TEST_F(TemperatureControllerTest, TEST_RANGE)
{
    const float MIN = 18;
    const float MAX = 25;
    setMin(MIN);
    setMax(MAX);
    
    for(int temp = TEST_RANGE_LOWER; temp < TEST_RANGE_UPPER; temp++)
    {
        setCurrent(temp);

        if(temp >= MIN && temp <= MAX)
        {
            EXPECT_EQ(runAndGetState(), TemperatureController::IDLE);
        }
        else if(temp < MIN)
        {
            EXPECT_EQ(runAndGetState(), TemperatureController::HEATING);
        }
        else
        {
            EXPECT_EQ(runAndGetState(), TemperatureController::COOLING);
        }
    }
}