#include "instruction.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test get_rd function", "[instructions]")
{
    RISCV::iword instruction1 = 0x12345678;

    REQUIRE(std::is_same<decltype(RISCV::get_rd(instruction1)), RISCV::RegisterAlias>::value);

    RISCV::RegisterAlias expected_rd_1 = static_cast<RISCV::RegisterAlias>(0x0C);
    REQUIRE(RISCV::get_rd(instruction1) == expected_rd_1);

    RISCV::iword instruction2 = 0x87654321;
    RISCV::RegisterAlias expected_rd_2 = static_cast<RISCV::RegisterAlias>(0x06);
    REQUIRE(RISCV::get_rd(instruction2) == expected_rd_2);

    RISCV::RegisterAlias false_rd2 = static_cast<RISCV::RegisterAlias>(0x00);
    REQUIRE_FALSE(RISCV::get_rd(instruction2) == false_rd2);
}

TEST_CASE("Test get_rs1 function", "[instructions]")
{
    RISCV::iword instruction1 = 0x12345678;

    REQUIRE(std::is_same<decltype(RISCV::get_rs1(instruction1)), RISCV::RegisterAlias>::value);

    RISCV::RegisterAlias expected_rs1_1 = static_cast<RISCV::RegisterAlias>(0x08);
    REQUIRE(RISCV::get_rs1(instruction1) == expected_rs1_1);

    RISCV::iword instruction2 = 0x87654321;
    RISCV::RegisterAlias expected_rs1_2 = static_cast<RISCV::RegisterAlias>(0x0A);
    REQUIRE(RISCV::get_rs1(instruction2) == expected_rs1_2);

    RISCV::RegisterAlias false_rs1 = static_cast<RISCV::RegisterAlias>(0x00);
    REQUIRE_FALSE(RISCV::get_rs1(instruction2) == false_rs1);
}

TEST_CASE("Test Instruction base class", "[instructions]")
{
    RISCV::Instruction instruction1(0x12345678);

    REQUIRE(std::is_same<decltype(instruction1.get_opcode()), RISCV::opcode>::value);
    RISCV::opcode test_opcode = static_cast<RISCV::opcode>(0x78);
    REQUIRE(instruction1.get_opcode() == test_opcode);
}

TEST_CASE("Test RTypeInstruction class", "[instructions]")
{
    RISCV::RTypeInstruction instruction(0x12345678);
    RISCV::RegisterAlias expected_rd = static_cast<RISCV::RegisterAlias>(0x0C);
    RISCV::RegisterAlias expected_rs1 = static_cast<RISCV::RegisterAlias>(0x08);
    RISCV::RegisterAlias expected_rs2 = static_cast<RISCV::RegisterAlias>(0x3);
    uint8_t expected_func3 = 0x05;
    uint8_t expected_func7 = 0x09;
    REQUIRE(instruction.get_rd() == expected_rd);
    REQUIRE(instruction.get_rs1() == expected_rs1);
    REQUIRE(instruction.get_rs2() == expected_rs2);
    REQUIRE(instruction.get_funct3() == expected_func3);
    REQUIRE(instruction.get_funct7() == expected_func7);
}

TEST_CASE("Test ITypeInstruction class", "[instructions]")
{
    RISCV::ITypeInstruction instruction(0x12345678);
    RISCV::RegisterAlias expected_rd = static_cast<RISCV::RegisterAlias>(0x0C);
    RISCV::RegisterAlias expected_rs1 = static_cast<RISCV::RegisterAlias>(0x08);
    uint8_t expected_func3 = 0x05;
    uint16_t expected_imm = 0x0123;
    REQUIRE(instruction.get_rd() == expected_rd);
    REQUIRE(instruction.get_rs1() == expected_rs1);
    REQUIRE(instruction.get_funct3() == expected_func3);
    REQUIRE(instruction.get_imm() == expected_imm);
}

TEST_CASE("Test STypeInstruction class", "[instructions]")
{
    RISCV::STypeInstruction instruction(0x12345678);
    RISCV::RegisterAlias expected_rs1 = static_cast<RISCV::RegisterAlias>(0x08);
    RISCV::RegisterAlias expected_rs2 = static_cast<RISCV::RegisterAlias>(0x03);
    uint8_t expected_func3 = 0x05;
    uint16_t expected_imm = 0x0123;
    REQUIRE(instruction.get_rs1() == expected_rs1);
    REQUIRE(instruction.get_rs2() == expected_rs2);
    REQUIRE(instruction.get_funct3() == expected_func3);
    REQUIRE(instruction.get_imm() == expected_imm);
}

TEST_CASE("Test BTypeInstruction class", "[instructions]")
{
    RISCV::BTypeInstruction instruction(0x12345678);
    RISCV::RegisterAlias expected_rs1 = static_cast<RISCV::RegisterAlias>(0x08);
    RISCV::RegisterAlias expected_rs2 = static_cast<RISCV::RegisterAlias>(0x03);
    uint8_t expected_func3 = 0x05;
    uint16_t expected_imm = 0x0123;
    REQUIRE(instruction.get_rs1() == expected_rs1);
    REQUIRE(instruction.get_rs2() == expected_rs2);
    REQUIRE(instruction.get_funct3() == expected_func3);
    REQUIRE(instruction.get_imm() == expected_imm);
}