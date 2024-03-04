#pragma once
#include "memory.hpp"
#include "register.hpp"

namespace RISCV
{
    const int NUM_REGISTERS = 32;
    enum class RegisterAlias : uint8_t
    {
        zero = 0,
        ra,
        sp,
        gp,
        tp,
        t0,
        t1,
        t2,
        s0,
        s1,
        a0,
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        s2,
        s3,
        s4,
        s5,
        s6,
        s7,
        s8,
        s9,
        s10,
        s11,
        t3,
        t4,
        t5,
        t6
    };
    class CPU
    {
    private:
        // Program counter
        Register m_pc;
        // Instruction register
        Register m_ir;
        // General purpose registers
        Register m_registers[NUM_REGISTERS];

        Memory m_instruction_memory;
        Memory m_memory;

        // ALU
        // CONTROL UNIT
        // HAZARD DETECTION UNIT
        // FLOATING POINT UNIT
    public:
    };
}