#include <OutputImpl.hpp>

OutputImpl::OutputImpl(bool initialValue) : m_value(initialValue)
{

}

void OutputImpl::write(bool value)
{
    m_value = value;
}

bool OutputImpl::read()
{
    return m_value;
}