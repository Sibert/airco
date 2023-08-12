#pragma once

#include <HALInterface.hpp>
#include <TemperatureInputImpl/TemperatureInputImpl.hpp>
#include <OutputImpl/OutputLinuxImpl.hpp>
#include <thread>
#include <chrono>
#include <Menu.hpp>

class HALImpl : public HALInterface
{
public:
    HALImpl();
    ~HALImpl();

    void initializeHAL();
private:
    TemperatureInputLinuxImpl * m_pMinInput = nullptr;
    TemperatureInputLinuxImpl * m_pMaxInput = nullptr;
    TemperatureInputLinuxImpl * m_pCurrentInput = nullptr;

    std::thread * m_pInputThread;

    void inputThread();
};