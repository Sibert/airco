#include <TemperatureController.hpp>

TemperatureController::TemperatureController(float & input, float & upperLimit, float & lowerLimit)
    : m_input(input),
    m_upperLimit(upperLimit),
    m_lowerLimit(lowerLimit)
{
    
}

TemperatureController::State TemperatureController::run()
{
    
    if(m_input < m_lowerLimit)
    {
        if(m_currentState != HEATING)
        {
            printChange("Start heating");
        }
        
        m_currentState = HEATING;
    }
    else if(m_input > m_upperLimit)
    {
        if(m_currentState != COOLING)
        {
            printChange("Start cooling");
        }
        
        m_currentState = COOLING;
    }
    else
    {
        if(m_currentState != IDLE)
        {
            printChange("No heating or cooling required");
        }
        m_currentState = IDLE;
    }
    
    return m_currentState;
}

void TemperatureController::printChange(std::string msg)
{
    std::cout << std::endl << "****************** TEMPERATURE CONTROLLER ******************" << std::endl;
    std::cout << msg << std::endl;
    std::cout << "**************** TEMPERATURE CONTROLLER DONE ***************" << std::endl << std::endl;
}