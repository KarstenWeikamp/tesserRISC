#pragma once
#include <cstdint>

namespace RISCV
{
    class Memory
    {
    public:
        uint64_t read(uint64_t address);
        void write(uint64_t address, uint64_t data);

    private:
    };
}