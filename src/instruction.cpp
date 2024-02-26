#include "instruction.hpp"

#define BITMASK0_6 0b1111111

namespace RISCV
{

    uint8_t Instruction::get_opcode()
    {
        return (this->m_instruction_word & BITMASK0_6);
    }

    uint
}