#include <HALImpl.hpp>

HALImpl::HALImpl()
{

}

HALImpl::~HALImpl()
{
    delete m_temperatureInputs[CURRENT];
    delete m_temperatureInputs[MINIMUM];
    delete m_temperatureInputs[MAXIMUM];

    delete m_outputs[COOLING];
    delete m_outputs[HEATING];
}

void HALImpl::initializeHAL()
{
    m_pMinInput = new TemperatureInputLinuxImpl(20.0);
    m_pMaxInput = new TemperatureInputLinuxImpl(30.0);
    m_pCurrentInput = new TemperatureInputLinuxImpl(25.0);

    m_temperatureInputs[CURRENT] = m_pCurrentInput;
    m_temperatureInputs[MINIMUM] = m_pMinInput;
    m_temperatureInputs[MAXIMUM] = m_pMaxInput;

    m_outputs[COOLING] = new OutputLinuxImpl("cooling");
    m_outputs[HEATING] = new OutputLinuxImpl("heating");

    m_pInputThread = new std::thread([this]() { inputThread(); });
}

void HALImpl::inputThread()
{
    Menu menu(m_pMinInput, m_pMaxInput, m_pCurrentInput);

    while(true)
    {
        std::cout << "Current temperature: " << m_temperatureInputs[CURRENT]->read() << "°C" << std::endl;
        std::cout << "Minimum temperature: " << m_temperatureInputs[MINIMUM]->read() << "°C" << std::endl;
        std::cout << "Maximum temperature: " << m_temperatureInputs[MAXIMUM]->read() << "°C" << std::endl;
        
        menu.printMenu();
        menu.run();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}