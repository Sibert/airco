#include <iostream>
#include <thread>
#include <Menu.hpp>
#include <TemperatureController.hpp>

using namespace std;

float currTemp = 20.0;
float minTemp = 18.0;
float maxTemp = 25.0;

void inputThread();

int main(int, char**)
{
    std::thread inputTask(inputThread);

    TemperatureController controller(currTemp, maxTemp, minTemp);

    while(true)
    {
        controller.run();

        this_thread::sleep_for(100ms);
    }
}

void inputThread()
{
    while(true)
    {
        cout << "Current temperature: " << currTemp << "°C" << endl;
        cout << "Minimum temperature: " << minTemp << "°C" << endl;
        cout << "Maximum temperature: " << maxTemp << "°C" << endl;
        Menu::printMenu();
        int input;
        cin >> input;

        switch((Menu::Option)input)
        {
            case Menu::Option::SET_CURRENT_TEMP:
                cout << "Enter new current temperature: ";
                cin >> currTemp;
                break;
            case Menu::Option::SET_MIN_TEMP:
                cout << "Enter new min temperature: ";
                cin >> minTemp;
                break;
            case Menu::Option::SET_MAX_TEMP:
                cout << "Enter new min temperature: ";
                cin >> minTemp;
                break;
            default:
                cout << "Invalid option picked" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        this_thread::sleep_for(100ms);
    }
}

