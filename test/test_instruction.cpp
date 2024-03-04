#include "instruction.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test get_rd function", "[instruction]")
{
    RISCV::iword instruction1 = 0x12345678;
    RISCV::RegisterAlias expected_rd1 = static_cast<RISCV::RegisterAlias>(0x2C);
    REQUIRE(RISCV::get_rd(instruction1) == expected_rd1);

    RISCV::iword instruction2 = 0x87654321;
    RISCV::RegisterAlias expected_rd2 = static_cast<RISCV::RegisterAlias>(0x06);
    REQUIRE(RISCV::get_rd(instruction2) == expected_rd2);
}


TEST_CASE("Test get_rs1 function", "[instruction]")
{
    RISCV::iword instruction1 = 0x12345678;
    RISCV::RegisterAlias expected_rs1 = static_cast<RISCV::RegisterAlias>(0x28);
    REQUIRE(RISCV::get_rs1(instruction1) == expected_rs1);

    // Test case 2
    RISCV::iword instruction2 = 0x87654321;
    RISCV::RegisterAlias expected_rs2 = static_cast<RISCV::RegisterAlias>(0x0A);
    REQUIRE(RISCV::get_rs1(instruction2) == expected_rs2);
}

// Add more test cases for other functions if needed

TEST_CASE("Test RTypeInstruction class", "[instruction]")
{
    RISCV::RTypeInstruction instruction1(0x12345678);
    RISCV::RegisterAlias expected_rd1 = static_cast<RISCV::RegisterAlias>(0x2C);
    REQUIRE(instruction1.get_rd() == expected_rd1);

    // Test case 2
    RISCV::RTypeInstruction instruction2(0x87654321);
    RISCV::RegisterAlias expected_rs1 = static_cast<RISCV::RegisterAlias>(0x0A);
    REQUIRE(instruction2.get_rs1() == expected_rs1);

}

TEST_CASE("Test ITypeInstruction class", "[instruction]")
{
    RISCV::ITypeInstruction instruction1(0x12345678);
    RISCV::RegisterAlias expected_rd1 = static_cast<RISCV::RegisterAlias>(0x2C);
    REQUIRE(instruction1.get_rd() == expected_rd1);

    RISCV::ITypeInstruction instruction2(0x87654321);
    RISCV::RegisterAlias expected_rs1 = static_cast<RISCV::RegisterAlias>(0x0A);
    REQUIRE(instruction2.get_rs1() == expected_rs1);

}
