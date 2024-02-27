#pragma once

#include <cstdint>

#include "processor.hpp"
#include "register.hpp"

namespace RISCV
{
    typedef uint32_t iword;
    typedef uint8_t opcode;
    class Instruction
    {
    protected:
        iword m_instruction_word{0};

    public:
        opcode get_opcode(void);
        uint8_t get_rs1();
        uint8_t get_rs2();
        uint8_t get_rd();
        uint8_t get_funct3();
        uint8_t get_funct7();
    };

    class RTypeInstruction : Instruction
    {
    private:
    public:


    };

    class ITypeInstruction : Instruction
    {
    private:
    public:
        uint8_t get_rs1();
        uint8_t get_rd();
        uint8_t get_funct3();
        uint16_t get_imm();
    };

    class STypeInstruction : Instruction
    {
    public:
        uint8_t get_rs1();
        uint8_t get_rs2();
        uint8_t get_rd();
        uint16_t get_imm();
    };

    class BTypeInstruction : Instruction
    {
    public:
        uint8_t get_rs1();
        uint8_t get_rs2();
        uint8_t get_rd();
        uint16_t get_imm();
    };

    class UTypeInstruction : Instruction
    {
    public:
        uint8_t get_rd();
        uint32_t get_imm();
    };

    class JTypeInstruction : Instruction
    {
        uint8_t get_rd();
        uint32_t get_imm();
    };

    class R4TypeInstruction : Instruction
    {
        uint8_t get_fd();
        uint8_t get_funct3();
        uint8_t get_fs1();
        uint8_t get_fs2();
        uint8_t get_funct2();
        uint8_t get_fs3();
    };

}