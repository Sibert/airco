#pragma once

#include <string>
#include <map>
#include <iostream>
#include <limits>

class Menu 
{
public:
    enum Option
    {
        SET_CURRENT_TEMP = 1,
        SET_MIN_TEMP,
        SET_MAX_TEMP
    };

    Menu(float & input, float & upperLimit, float & lowerLimit);

    void printMenu();

    void run();

private:
    inline static std::map<Menu::Option, std::string> MENU_ITEMS = {
        { SET_CURRENT_TEMP, "Set current temperature" },
        { SET_MIN_TEMP, "Set minimum temperature" },
        { SET_MAX_TEMP, "Set maximum temperature" }
    };

    float & m_input;
    float & m_upperLimit;
    float & m_lowerLimit;

    template<typename T>
    bool readInput(T & input);
};