#pragma once
#include <cstdint>

namespace RISCV
{
    class Register
    {
    private:
        uint64_t m_value{0};

    public:
        Register(/* args */);
        ~Register();
        uint64_t read();
        void write(uint64_t t_value);
    };

} // namespace RISCV
