#include "Executor.hpp"
#include <bit>
#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#define CATCH_CONFIG_MAIN

// include your CPU/Decoder/Executor headers
#include "Decoder.hpp"
#include "ExecutorTestOnly.hpp"
#include "GeneralSimTypes.hpp"
#include "Instructions.hpp"
#include "TestInfra.hpp"
using XReg = uint16_t;

// ###################
// # Executor tests
// ###################

TEST_CASE("ADD / SUB / ADDI / SLT edge cases") {
  TestSim::FakeExecContext ctx;
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
  TestSim::EXEC_ADDI(ctx, XReg(5), XReg(1), GeneralSim::Immediate(100, 32));
  REQUIRE(ctx.getReg(XReg(5)) == 105);
  TestSim::EXEC_ADDI(ctx, XReg(6), XReg(1), GeneralSim::Immediate(-10, 32));
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
  TestSim::FakeExecContext ctx;
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
  TestSim::EXEC_SLLI(ctx, XReg(7), XReg(6), GeneralSim::Immediate(31, 32));
  REQUIRE(ctx.getReg(XReg(7)) == 0x80000000);

  ctx.setReg(XReg(8), 0x80000000);
  TestSim::EXEC_SRLI(ctx, XReg(9), XReg(8), GeneralSim::Immediate(31, 32));
  REQUIRE(ctx.getReg(XReg(9)) == 1);

  ctx.setReg(XReg(10), 0x80000000);
  TestSim::EXEC_SRAI(ctx, XReg(11), XReg(10), GeneralSim::Immediate(31, 32));
  REQUIRE(ctx.getReg(XReg(11)) == 0xFFFFFFFF);
}

TEST_CASE("Load / Store with edge cases") {
  TestSim::FakeExecContext ctx;

  // store values
  TestSim::EXEC_SW(ctx, XReg(1), XReg(0),
                   GeneralSim::Immediate(0, 32)); // store x1 @ addr=0
  ctx.setReg(XReg(1), 0x12345678);
  TestSim::EXEC_SW(ctx, XReg(1), XReg(0), GeneralSim::Immediate(0, 32));

  uint32_t val;
  TestSim::EXEC_LW(ctx, XReg(2), XReg(0), GeneralSim::Immediate(0, 32));
  val = ctx.getReg(XReg(2));
  REQUIRE(val == 0x12345678);

  // sign-extend loads
  ctx.write8(4, 0x80); // -128
  TestSim::EXEC_LB(ctx, XReg(3), XReg(0), GeneralSim::Immediate(4, 32));
  REQUIRE(ctx.getReg(XReg(3)) == 0xFFFFFF80);

  ctx.write8(5, 0xFF); // 255
  TestSim::EXEC_LBU(ctx, XReg(4), XReg(0), GeneralSim::Immediate(5, 32));
  REQUIRE(ctx.getReg(XReg(4)) == 0xFF);
}

TEST_CASE("x0 and PC behavior") {
  TestSim::FakeExecContext ctx;
  ctx.setReg(XReg(0), 123);
  REQUIRE(ctx.getReg(XReg(0)) == 0);

  ctx.setPC(0x1000);
  REQUIRE(ctx.getPC() == 0x1000);
  ctx.setPC(0x2000);
  REQUIRE(ctx.getPC() == 0x2000);
}

TEST_CASE("Executor: shift amount masked to 5 bits") {
  TestSim::FakeExecContext ctx;
  ctx.setReg(1, 1);
  ctx.setReg(2, 33); // 33 & 31 == 1

  TestSim::EXEC_SLL(ctx, XReg{3}, XReg{1}, XReg{2});

  REQUIRE(ctx.getReg(3) == 2);
}

TEST_CASE("Executor: SLT vs SLTU differ") {
  TestSim::FakeExecContext ctx;
  ctx.setReg(1, -1);
  ctx.setReg(2, 1);

  TestSim::EXEC_SLT(ctx, XReg{3}, XReg{1}, XReg{2});
  TestSim::EXEC_SLTU(ctx, XReg{4}, XReg{1}, XReg{2});

  REQUIRE(ctx.getReg(3) == 1); // -1 < 1
  REQUIRE(ctx.getReg(4) == 0); // 0xffffffff > 1
}

TEST_CASE("Executor: LB sign extends, LBU zero extends") {
  TestSim::FakeExecContext ctx;
  ctx.write8(0, 0x80);

  TestSim::EXEC_LB(ctx, XReg{1}, XReg{0}, GeneralSim::Immediate(0, 32));
  TestSim::EXEC_LBU(ctx, XReg{2}, XReg{0}, GeneralSim::Immediate(0, 32));

  REQUIRE(std::bit_cast<int32_t>(ctx.getReg(1)) ==
          static_cast<int32_t>(0xffffff80));
  REQUIRE(ctx.getReg(2) == 0x80);
}


TEST_CASE("MUL / MULH family torture") {
  TestSim::FakeExecContext ctx;

  // 1 * 1
  ctx.setReg(XReg(1), 1);
  ctx.setReg(XReg(2), 1);

  TestSim::EXEC_MUL(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 1);

  TestSim::EXEC_MULH(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 0);

  // (-1) * (-1) = +1
  ctx.setReg(XReg(1), 0xFFFFFFFF);
  ctx.setReg(XReg(2), 0xFFFFFFFF);

  TestSim::EXEC_MUL(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 1);

  TestSim::EXEC_MULH(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 0);

  // (-2^31) * 2
  ctx.setReg(XReg(1), 0x80000000);
  ctx.setReg(XReg(2), 2);

  TestSim::EXEC_MUL(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 0x00000000);

  TestSim::EXEC_MULH(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 0xFFFFFFFF); // sign-propagated

  // MULHU: unsigned * unsigned
  ctx.setReg(XReg(1), 0xFFFFFFFF);
  ctx.setReg(XReg(2), 2);

  TestSim::EXEC_MULHU(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 1);

  // MULHSU: signed * unsigned
  ctx.setReg(XReg(1), 0xFFFFFFFF); // -1
  ctx.setReg(XReg(2), 2);

  TestSim::EXEC_MULHSU(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 0xFFFFFFFF);
}


TEST_CASE("DIV / DIVU torture") {
  TestSim::FakeExecContext ctx;

  // normal
  ctx.setReg(XReg(1), 10);
  ctx.setReg(XReg(2), 2);

  TestSim::EXEC_DIV(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 5);

  // overflow case: INT_MIN / -1
  ctx.setReg(XReg(1), 0x80000000);
  ctx.setReg(XReg(2), 0xFFFFFFFF);

  //TestSim::EXEC_DIV(ctx, XReg(3), XReg(1), XReg(2));
  //REQUIRE(ctx.getReg(XReg(3)) == 0x80000000);

  //TestSim::EXEC_DIVU(ctx, XReg(3), XReg(1), XReg(2));
  //REQUIRE(ctx.getReg(XReg(3)) == 0xFFFFFFFF);
}


TEST_CASE("REM / REMU torture") {
  TestSim::FakeExecContext ctx;

  // normal
  ctx.setReg(XReg(1), 10);
  ctx.setReg(XReg(2), 3);

  TestSim::EXEC_REM(ctx, XReg(3), XReg(1), XReg(2));
  REQUIRE(ctx.getReg(XReg(3)) == 1);

  // INT_MIN % -1
  ctx.setReg(XReg(1), 0x80000000);
  ctx.setReg(XReg(2), 0xFFFFFFFF);

  //TestSim::EXEC_REM(ctx, XReg(3), XReg(1), XReg(2));
  //REQUIRE(ctx.getReg(XReg(3)) == 0);

  //TestSim::EXEC_REMU(ctx, XReg(3), XReg(1), XReg(2));
  //REQUIRE(ctx.getReg(XReg(3)) == 123);
}



// ###################
// # Decoder tests:
// ###################
TEST_CASE("Decoder: I-type immediate sign extension") {
  // addi x1, x0, -1
  uint32_t inst =
      (0b0010011) | (1 << 7) | (0b000 << 12) | (0 << 15) | (0xfff << 20); // -1
  Decoder::Decoder dcdr;
  auto decoded = dcdr.decode(inst);
  auto &i = std::get<ADDI>(decoded);

  REQUIRE(std::bit_cast<int32_t>(i.imm.asSigned()) == -1);
}

TEST_CASE("Decoder: B-type immediate reconstruction") {
  // beq x0, x0, -4
  uint32_t inst = 0b1100011; // opcode
  inst |= (0b000 << 12);     // funct3
  inst |= (0 << 15);         // rs1
  inst |= (0 << 20);         // rs2
  inst |= (1 << 31);         // imm[12]
  inst |= (1 << 7);          // imm[11]
  inst |= (0b111111 << 25);  // imm[10:5]
  inst |= (0b1110 << 8);     // imm[4:1]

  Decoder::Decoder dcdr;
  auto decoded = dcdr.decode(inst);
  auto &i = std::get<BEQ>(decoded);

  REQUIRE(std::bit_cast<int32_t>(i.imm.asSigned()) == -4);
}

// ###################
// # Executor + Decoder tests:
// ###################

TEST_CASE("Decode + execute roundtrip") {
  TestSim::FakeExecContext ctx;
  ctx.setReg(1, 5);
  ctx.setReg(2, 7);

  uint32_t add = (0b0110011) | (3 << 7) | (0b000 << 12) | (1 << 15) | (2 << 20);

  Decoder::Decoder dcdr;
  auto inst = dcdr.decode(add);
  GeneralSim::Executor extr;
  extr.execute(inst, ctx);

  REQUIRE(ctx.getReg(3) == 12);
}