#include "instruction.hpp"
#include "processor.hpp"

#define BITMASK0_2 0b00000011
#define BITMASK0_5 0b00111111
#define BITMASK0_6 0b01111111
#define BITMASK0_11 0b0000111111111111 


namespace RISCV
{
    /**
     * @brief Get the destination register from the given instruction.
     *
     * This function extracts the destination register (rd) from the instruction word.
     * The destination register occupies bits 7 to 11 in every instruction type that contains rd.
     *
     * @param t_iword The instruction word from which to extract the destination register.
     * @return The destination operand from the instruction word.
     */
    RegisterAlias get_rd(iword t_iword)
    {
        return (RegisterAlias)((t_iword >> 7) & BITMASK0_5);
    }

    /**
     *  @brief Get the source register 1 operand of an instruction word
     *
     * This function extracts the source register 1 (rs1) from the instruction word.
     * The source register 1 occupies bits 15 to 19 in every instruction type that contains rs1.
     *
     * @param t_iword The instruction word from which to extract the source register 1.
     * @return source register 1 of an instruction word
     */
    RegisterAlias get_rs1(iword t_iword)
    {
        return (RegisterAlias)((t_iword >> 15) & BITMASK0_5);
    }

    /**
     *  @brief Get the source register 2 operand of an instruction word
     *
     * This function extracts the source register 2 (rs2) from the instruction word.
     * The source register 2 occupies bits 20 to 24 in every instruction type that contains rs2.
     *
     * @param t_iword The instruction word from which to extract the source register 2.
     * @return source register 2 of an instruction word
     */
    RegisterAlias get_rs2(iword t_iword)
    {
        return (RegisterAlias)((t_iword >> 20) & BITMASK0_5);
    }

    /**
     * Retrieves the funct3 field from the given instruction word.
     *
     * @param t_iword The instruction word.
     * @return The funct3 field.
     */
    uint8_t get_funct3(iword t_iword)
    {
        return (t_iword >> 12) & BITMASK0_2;
    }

    /**
     * @brief Get the opcode of the instruction.
     *
     * The opcode of an RISC-V instruction is always the first 7 MSB of the instruction word.
     *
     * @return The opcode of the instruction.
     */
    opcode Instruction::get_opcode()
    {
        return (opcode)(this->m_instruction_word & BITMASK0_6);
    }



    RegisterAlias RTypeInstruction::get_rd()
    {
        return RISCV::get_rd((this->m_instruction_word));
    }

    RegisterAlias RTypeInstruction::get_rs1()
    {
        return RISCV::get_rs1(this->m_instruction_word);
    }

    RegisterAlias RTypeInstruction::get_rs2()
    {
        return RISCV::get_rs2(this->m_instruction_word);
    }

    uint8_t RTypeInstruction::get_funct3()
    {
        return RISCV::get_funct3(this->m_instruction_word);
    }

    uint8_t RTypeInstruction::get_funct7()
    {
        return (this->m_instruction_word >> 25) & BITMASK0_6;
    }

    RegisterAlias ITypeInstruction::get_rd()
    {
        return RISCV::get_rd((this->m_instruction_word));
    }

    RegisterAlias ITypeInstruction::get_rs1()
    {
        return RISCV::get_rs1(this->m_instruction_word);
    }

    uint8_t ITypeInstruction::get_funct3()
    {
        return RISCV::get_funct3(this->m_instruction_word);
    }

    uint16_t ITypeInstruction::get_imm()
    {
        return (this->m_instruction_word >> 20) & BITMASK0_11;
    }
}