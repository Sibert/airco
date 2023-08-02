#include <Menu.hpp>
#include <iostream>

void Menu::printMenu()
{
    std::cout << "Menu options:" << std::endl;

    for(std::pair<Menu::Option, std::string> option : MENU_ITEMS)
    {
        std::cout << "\t" << (int)option.first << ". " << option.second << std::endl;
    }

    std::cout << "Please make a selection:" << std::endl;
}