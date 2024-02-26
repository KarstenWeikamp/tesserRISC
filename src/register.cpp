#include "register.hpp"

namespace RISCV
{
    uint64_t Register::read()
    {
        return this->m_value;
    }
    void Register::write(uint64_t t_value)
    {
        this->m_value = t_value;
    }
}