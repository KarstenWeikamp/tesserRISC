#pragma once

#include <cstdint>

#include "processor.hpp"
#include "register.hpp"

namespace RISCV
{
    typedef uint32_t iword;
    typedef uint8_t opcode;

    RegisterAlias get_rd(iword t_iword);
    RegisterAlias get_rs1(iword t_iword);
    RegisterAlias get_rs2(iword t_iword);
    uint8_t get_funct3(iword t_iword);

    /**
     * @brief Represents an instruction in the TesserRISC architecture.
     */
    class Instruction
    {
    protected:
        iword m_instruction_word{0};

    public:
        Instruction(uint_least32_t t_instruction_word)
        {
            this->m_instruction_word = static_cast<RISCV::iword>(t_instruction_word);
        }
        /**
         * @brief Gets the opcode of the instruction.
         * @return The opcode of the instruction.
         */
        virtual opcode get_opcode(void);
    };

    /**
     * @brief Represents an R-type instruction.
     *
     * This class inherits from the Instruction class and provides methods to access
     * the fields of an R-type instruction, such as the first source register (rs1),
     * second source register (rs2),destination register (rd), 3bit opcode extension
     * (funct3) and 7 bit opcode extension (funct7).
     *
     * +--------+-----+-----+--------+------+-------+
     * | funct7 | rs2 | rs1 | funct3 |  rd  | opcode|
     * +--------+-----+-----+--------+------+-------+
     */
    class RTypeInstruction : Instruction
    {
    public:
        using Instruction::Instruction;
        /**
         * @brief Get the destination register (rd) of the R-type instruction.
         *
         * @return The destination register (rd).
         */
        RegisterAlias get_rd();

        /**
         * @brief Get the first source register (rs1) of the R-type instruction.
         *
         * @return The first source register (rs1).
         */
        RegisterAlias get_rs1();

        /**
         * @brief Get the second source register (rs2) of the R-type instruction.
         *
         * @return The first source register (rs2).
         */
        RegisterAlias get_rs2();

        /**
         * @brief Get the funct3 field opcode extension value of the R-type instruction.
         *
         * @return The funct3 field value.
         */
        uint8_t get_funct3();

        /**
         * @brief Get the funct7 field opcode extension value of the R-type instruction.
         *
         * @return The funct7 field value.
         */
        uint8_t get_funct7();
    };

    /**
     * @brief Represents an I-type instruction.
     *
     * This class inherits from the Instruction class and provides methods to access
     * the fields of an I-type instruction, such as the source register (rs1),
     * destination register (rd), 3 bit opcode extension (funct3), and immediate value (imm).
     *
     * +---------------+-----+--------+--------+------+
     * |   imm[11:0]   | rs1 | funct3 |   rd   |opcode|
     * +---------------+-----+--------+--------+------+
     */
    class ITypeInstruction : Instruction
    {
    private:
    public:
        using Instruction::Instruction;
        /**
         * @brief Get the source register (rs1) of the I-type instruction.
         *
         * @return The source register (rs1).
         */
        RegisterAlias get_rs1();

        /**
         * @brief Get the destination register (rd) of the I-type instruction.
         *
         * @return The destination register (rd).
         */
        RegisterAlias get_rd();

        /**
         * @brief Get the function code (funct3) of the I-type instruction.
         *
         * @return The function code (funct3).
         */
        uint8_t get_funct3();

        /**
         * @brief Get the immediate value (imm) of the I-type instruction.
         *
         * @return The immediate value (imm).
         */
        uint16_t get_imm();
    };

    /**
     * @brief Represents an S-Type instruction.
     *
     * This class inherits from the Instruction class and provides methods to access
     * the fields of an S-type instruction, such as the first source register (rs1),
     * second source register, destination register (rd) and immediate value (imm).
     *
     * +---------+-----+-----+--------+----------+-------+
     * |imm[11:5]| rs2 | rs1 | funct3 | imm[4:0] | opcode|
     * +---------+-----+-----+--------+----------+-------+
     *
     */
    class STypeInstruction : Instruction
    {
    public:
        using Instruction::Instruction;
        /**
         * @brief Get the first source register (rs1) of the S-type instruction.
         *
         * @return The first source register (rs1).
         */
        RegisterAlias get_rs1();

        /**
         * @brief Get the second source register (rs2) of the S-type instruction.
         *
         * @return The first source register (rs2).
         */
        RegisterAlias get_rs2();

        /**
         * @brief Get the destination register (rd) of the S-type instruction.
         *
         * @return The destination register (rd).
         */
        RegisterAlias get_rd();

        /**
         * @brief Get the immediate value of the S-type instruction.
         *
         * @return The immediate value.
         */
        uint16_t get_imm();
    };

    /**
     * @brief Represents a B-type instruction.
     *
     * This class inherits from the Instruction class and provides methods to access
     * the fields of an B-type instruction, such as the first source register (rs1),
     * second source register, and immediate value (imm).
     *
     * +---------+-----------+-----+-----+--------+----------+---------+--------+
     * | imm[12] | imm[10:5] | rs2 | rs1 | funct3 | imm[4:1] | imm[11] | opcode |
     * +---------+-----------+-----+-----+--------+----------+---------+--------+
     *
     */
    class BTypeInstruction : Instruction
    {
    public:
        using Instruction::Instruction;
        /**
         * @brief Get the first source register (rs1) of the B-type instruction.
         *
         * @return The first source register (rs1).
         */
        RegisterAlias get_rs1();

        /**
         * @brief Get the second source register (rs2) of the B-type instruction.
         *
         * @return The first source register (rs2).
         */
        RegisterAlias get_rs2();

        /**
         * @brief Get the func3 3 bit opcode extension of the B-type instruction.
         *
         * @return The func3 field.
         */
        uint8_t get_funct3();

        /**
         * @brief Get the immediate value of the B-type instruction.
         *
         * @return The immediate value.
         */
        uint16_t get_imm();
    };

    /**
     * @brief Represents a U-type instruction.
     *
     * This class inherits from the Instruction class and provides methods to access
     * the fields of an U-type instruction, such as the destination register (rd),
     * and immediate value (imm).
     *
     * +------------------------------------+--+------+
     * |               imm[31:12]           |rd|opcode|
     * +------------------------------------+--+------+
     *
     */
    class UTypeInstruction : Instruction
    {
    public:
        using Instruction::Instruction;
        /**
         * @brief Get the destination register (rd) of the U-type instruction.
         *
         * @return The destination register (rd).
         */
        RegisterAlias get_rd();

        /**
         * @brief Get the immediate value of the U-type instruction.
         *
         * @return The immediate value.
         */
        uint32_t get_imm();
    };

    /**
     * @brief Represents a J-type instruction.
     *
     * This class inherits from the Instruction class and provides methods to access
     * the fields of an J-type instruction, such as the destination register (rd),
     * and immediate value (imm).
     *
     * +-------+---------+-------+----------+--+------+
     * |imm[20]|imm[10:1]|imm[11]|imm[19:12]|rd|opcode|
     * +-------+---------+-------+----------+--+------+
     */
    class JTypeInstruction : Instruction
    {
        using Instruction::Instruction;
        /**
         * @brief Get the destination register (rd) of the J-type instruction.
         *
         * @return The destination register (rd).
         */
        RegisterAlias get_rd();

        /**
         * @brief Get the immediate value of the U-type instruction.
         *
         * @return The immediate value.
         */
        uint32_t get_imm();
    };

}