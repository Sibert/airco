#pragma once

#include <string>
#include <map>

class Menu 
{
public:
    enum Option
    {
        SET_CURRENT_TEMP = 1,
        SET_MIN_TEMP,
        SET_MAX_TEMP
    };

    static void printMenu();

private:
    inline static std::map<Menu::Option, std::string> MENU_ITEMS = {
        { SET_CURRENT_TEMP, "Set current temperature" },
        { SET_MIN_TEMP, "Set minimum temperature" },
        { SET_MAX_TEMP, "Set maximum temperature" }
    };
};