#include <Menu.hpp>
#include <iostream>

Menu::Menu(TemperatureInputImpl * minInput, TemperatureInputImpl * maxInput, TemperatureInputImpl * currInput) : 
    m_pLowerLimit(minInput),
    m_pUpperLimit(maxInput),
    m_pInput(currInput)
{

}

void Menu::printMenu()
{
    std::cout << "Menu options:" << std::endl;

    for(std::pair<Menu::Option, std::string> option : MENU_ITEMS)
    {
        std::cout << "\t" << (int)option.first << ". " << option.second << std::endl;
    }

    std::cout << "Please make a selection:" << std::endl;
}

void Menu::run()
{
    int input;
    if(!readInput(input))
    {
        return;
    }

    float inputValue;
    switch((Menu::Option)input)
    {
        case Menu::Option::SET_CURRENT_TEMP:
            std::cout << "Enter new current temperature: ";

            if (readInput(inputValue))
            {
                m_pInput->setValue(inputValue);    
            }
            
            break;
        case Menu::Option::SET_MIN_TEMP:
            std::cout << "Enter new min temperature: ";

            if (readInput(inputValue))
            {
                m_pLowerLimit->setValue(inputValue);    
            }

            break;
        case Menu::Option::SET_MAX_TEMP:
            std::cout << "Enter new min temperature: ";
            
            if (readInput(inputValue))
            {
                m_pUpperLimit->setValue(inputValue);    
            }

            break;
        default:
            std::cout << "Invalid option picked" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

template<typename T>
bool Menu::readInput(T & input)
{
    std::cin >> input;

    if(!std::cin.good())
    {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}