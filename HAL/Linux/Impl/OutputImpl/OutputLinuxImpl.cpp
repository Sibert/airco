#include <OutputLinuxImpl.hpp>

OutputLinuxImpl::OutputLinuxImpl(std::string outputName, bool initialValue) : m_name(outputName), m_value(initialValue)
{

}

void OutputLinuxImpl::write(bool value)
{
    if(value != m_value)
    {
        m_value = value;
        std::cout << "Output '" << m_name << "' set to " << m_value << std::endl;
    }
}

bool OutputLinuxImpl::read()
{
    return m_value;
}