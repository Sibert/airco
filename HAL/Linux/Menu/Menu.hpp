#pragma once

#include <string>
#include <map>
#include <iostream>
#include <limits>
#include <TemperatureInputImpl/TemperatureInputImpl.hpp>

class Menu 
{
public:
    enum Option
    {
        SET_CURRENT_TEMP = 1,
        SET_MIN_TEMP,
        SET_MAX_TEMP
    };

    Menu(TemperatureInputLinuxImpl * minInput, TemperatureInputLinuxImpl * maxInput, TemperatureInputLinuxImpl * currInput);

    void printMenu();

    void run();

private:
    inline static std::map<Menu::Option, std::string> MENU_ITEMS = {
        { SET_CURRENT_TEMP, "Set current temperature" },
        { SET_MIN_TEMP, "Set minimum temperature" },
        { SET_MAX_TEMP, "Set maximum temperature" }
    };

    TemperatureInputLinuxImpl * m_pLowerLimit;
    TemperatureInputLinuxImpl * m_pUpperLimit;
    TemperatureInputLinuxImpl * m_pInput;

    template<typename T>
    bool readInput(T & input);
};