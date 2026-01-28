#include <cstdint>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_all.hpp>
#define CATCH_CONFIG_MAIN

// include your CPU/Decoder/Executor headers
#include "TestInfra.hpp"
#include "ExecutorTestOnly.hpp"
#include "GeneralSimTypes.hpp"
using XReg = uint16_t;

TEST_CASE("ADD / SUB / ADDI / SLT edge cases") {
    GeneralSim::FakeExecContext ctx;
    ctx.setReg(XReg(1), 5);
    ctx.setReg(XReg(2), 10);

    // ADD
    TestSim::EXEC_ADD(ctx, XReg(3), XReg(1), XReg(2));
    REQUIRE(ctx.getReg(XReg(3)) == 15);

    // ADD with x0
    TestSim::EXEC_ADD(ctx, XReg(3), XReg(0), XReg(2));
    REQUIRE(ctx.getReg(XReg(3)) == 10);

    // SUB
    TestSim::EXEC_SUB(ctx, XReg(4), XReg(2), XReg(1));
    REQUIRE(ctx.getReg(XReg(4)) == 5);

    // ADDI positive/negative
    TestSim::EXEC_ADDI(ctx, XReg(5), XReg(1), GeneralSim::Immediate(100, 32, GeneralSim::ImmediateType::Unsigned));
    REQUIRE(ctx.getReg(XReg(5)) == 105);
    TestSim::EXEC_ADDI(ctx, XReg(6), XReg(1), GeneralSim::Immediate(-10, 32, GeneralSim::ImmediateType::Signed));
    REQUIRE(ctx.getReg(XReg(6)) == -5u); // uint32 wrap

    // SLT / SLTU
    TestSim::EXEC_SLT(ctx, XReg(7), XReg(1), XReg(2));
    REQUIRE(ctx.getReg(XReg(7)) == 1);
    TestSim::EXEC_SLT(ctx, XReg(8), XReg(2), XReg(1));
    REQUIRE(ctx.getReg(XReg(8)) == 0);
    TestSim::EXEC_SLTU(ctx, XReg(9), XReg(1), XReg(2));
    REQUIRE(ctx.getReg(XReg(9)) == 1);
    TestSim::EXEC_SLTU(ctx, XReg(10), XReg(2), XReg(1));
    REQUIRE(ctx.getReg(XReg(10)) == 0);
}

TEST_CASE("AND / OR / XOR / SLL / SRL / SRA edge cases") {
    GeneralSim::FakeExecContext ctx;
    ctx.setReg(XReg(1), 0b1100);
    ctx.setReg(XReg(2), 0b1010);

    TestSim::EXEC_AND(ctx, XReg(3), XReg(1), XReg(2));
    REQUIRE(ctx.getReg(XReg(3)) == 0b1000);

    TestSim::EXEC_OR(ctx, XReg(4), XReg(1), XReg(2));
    REQUIRE(ctx.getReg(XReg(4)) == 0b1110);

    TestSim::EXEC_XOR(ctx, XReg(5), XReg(1), XReg(2));
    REQUIRE(ctx.getReg(XReg(5)) == 0b0110);

    // Shifts
    ctx.setReg(XReg(6), 1);
    TestSim::EXEC_SLLI(ctx, XReg(7), XReg(6), GeneralSim::Immediate(31, 32, GeneralSim::ImmediateType::Unsigned));
    REQUIRE(ctx.getReg(XReg(7)) == 0x80000000);

    ctx.setReg(XReg(8), 0x80000000);
    TestSim::EXEC_SRLI(ctx, XReg(9), XReg(8), GeneralSim::Immediate(31, 32, GeneralSim::ImmediateType::Unsigned));
    REQUIRE(ctx.getReg(XReg(9)) == 1);

    ctx.setReg(XReg(10), 0x80000000);
    TestSim::EXEC_SRAI(ctx, XReg(11), XReg(10), GeneralSim::Immediate(31, 32, GeneralSim::ImmediateType::Unsigned));
    REQUIRE(ctx.getReg(XReg(11)) == 0xFFFFFFFF);
}

TEST_CASE("Load / Store with edge cases") {
    GeneralSim::FakeExecContext ctx;

    // store values
    TestSim::EXEC_SW(ctx, XReg(1), XReg(0), GeneralSim::Immediate(0, 32, GeneralSim::ImmediateType::Unsigned)); // store x1 @ addr=0
    ctx.setReg(XReg(1), 0x12345678);
    TestSim::EXEC_SW(ctx, XReg(1), XReg(0), GeneralSim::Immediate(0, 32, GeneralSim::ImmediateType::Unsigned));

    uint32_t val;
    TestSim::EXEC_LW(ctx, XReg(2), XReg(0), GeneralSim::Immediate(0, 32, GeneralSim::ImmediateType::Unsigned));
    val = ctx.getReg(XReg(2));
    REQUIRE(val == 0x12345678);

    // sign-extend loads
    ctx.write8(4, 0x80); // -128
    TestSim::EXEC_LB(ctx, XReg(3), XReg(0), GeneralSim::Immediate(4, 32, GeneralSim::ImmediateType::Unsigned));
    REQUIRE(ctx.getReg(XReg(3)) == 0xFFFFFF80);

    ctx.write8(5, 0xFF); // 255
    TestSim::EXEC_LBU(ctx, XReg(4), XReg(0), GeneralSim::Immediate(5, 32, GeneralSim::ImmediateType::Unsigned));
    REQUIRE(ctx.getReg(XReg(4)) == 0xFF);
}

TEST_CASE("x0 and PC behavior") {
    GeneralSim::FakeExecContext ctx;
    ctx.setReg(XReg(0), 123);
    REQUIRE(ctx.getReg(XReg(0)) == 0);

    ctx.setPC(0x1000);
    REQUIRE(ctx.getPC() == 0x1000);
    ctx.setPC(0x2000);
    REQUIRE(ctx.getPC() == 0x2000);
}
