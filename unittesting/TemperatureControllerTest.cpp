#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <TemperatureController.hpp>
#include <Output.hpp>
#include <TemperatureInput.hpp>

using ::testing::Return;
using ::testing::NiceMock;

class MockTemperatureInput : public TemperatureInput
{
public:
    MOCK_METHOD(float, read, (), (override));
};

class MockOutput : public Output
{
public:
    MOCK_METHOD(void, write, (bool), (override));
    MOCK_METHOD(bool, read, (), (override));
};

class TemperatureControllerTestFixture : public ::testing::Test
{
public:
protected:
    // Explicitly NiceMock => the read function will be flagged as uninteresting otherwise, but it's also the only function
    NiceMock<MockTemperatureInput> m_pMinTempIn;
    NiceMock<MockTemperatureInput> m_pMaxTempIn;
    NiceMock<MockTemperatureInput> m_pCurrTempIn;

    // Explicitly NiceMock => the write function will be flagged as uninteresting otherwise, read function is unused
    NiceMock<MockOutput> m_pHeatingOut;
    NiceMock<MockOutput> m_pCoolingOut;

    TemperatureController * m_pTempController = nullptr;

    void SetUp() override
    {
        m_pTempController = new TemperatureController(&m_pMinTempIn, &m_pMaxTempIn, &m_pCurrTempIn, &m_pCoolingOut, &m_pHeatingOut);
    }

    void TearDown() override
    {
        delete m_pTempController;
    }
};

TEST_F(TemperatureControllerTestFixture, START_COOLING)
{
    ON_CALL(m_pCurrTempIn, read()).WillByDefault(Return(35));
    ON_CALL(m_pMinTempIn, read()).WillByDefault(Return(20));
    ON_CALL(m_pMaxTempIn, read()).WillByDefault(Return(30));

    EXPECT_CALL(m_pCoolingOut, write(true));
    EXPECT_CALL(m_pHeatingOut, write(false));

    m_pTempController->run();
}

TEST_F(TemperatureControllerTestFixture, IDLE)
{
    ON_CALL(m_pCurrTempIn, read()).WillByDefault(Return(25));
    ON_CALL(m_pMinTempIn, read()).WillByDefault(Return(20));
    ON_CALL(m_pMaxTempIn, read()).WillByDefault(Return(30));

    EXPECT_CALL(m_pCoolingOut, write(false));
    EXPECT_CALL(m_pHeatingOut, write(false));

    m_pTempController->run();
}

TEST_F(TemperatureControllerTestFixture, IDLE_EQ_TO_MIN)
{
    ON_CALL(m_pCurrTempIn, read()).WillByDefault(Return(20));
    ON_CALL(m_pMinTempIn, read()).WillByDefault(Return(20));
    ON_CALL(m_pMaxTempIn, read()).WillByDefault(Return(30));

    EXPECT_CALL(m_pCoolingOut, write(false));
    EXPECT_CALL(m_pHeatingOut, write(false));

    m_pTempController->run();
}

TEST_F(TemperatureControllerTestFixture, IDLE_EQ_TO_MAX)
{
    ON_CALL(m_pCurrTempIn, read()).WillByDefault(Return(30));
    ON_CALL(m_pMinTempIn, read()).WillByDefault(Return(20));
    ON_CALL(m_pMaxTempIn, read()).WillByDefault(Return(30));

    EXPECT_CALL(m_pCoolingOut, write(false));
    EXPECT_CALL(m_pHeatingOut, write(false));

    m_pTempController->run();
}


TEST_F(TemperatureControllerTestFixture, START_HEATING)
{
    ON_CALL(m_pCurrTempIn, read()).WillByDefault(Return(15));
    ON_CALL(m_pMinTempIn, read()).WillByDefault(Return(20));
    ON_CALL(m_pMaxTempIn, read()).WillByDefault(Return(30));

    EXPECT_CALL(m_pCoolingOut, write(false));
    EXPECT_CALL(m_pHeatingOut, write(true));

    m_pTempController->run();
}