#pragma once
#include "ExecContext.hpp"
namespace TestSim {
using XReg = uint16_t;
using ExecContext = GeneralSim::ExecContext;
void EXEC_ADD(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction ADD
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp0 = 0;
  v__tmp0 = v_rs1 + v_rs2;
  v_rd = v__tmp0;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SUB(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SUB
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp1 = 0;
  v__tmp1 = v_rs1 - v_rs2;
  v_rd = v__tmp1;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLL(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SLL
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__c2 = 0;
  v__c2 = 31;
  uint32_t v__tmp3 = 0;
  v__tmp3 = v_rs2 & v__c2;
  uint32_t v__tmp4 = 0;
  v__tmp4 = v_rs1 << v__tmp3;
  v_rd = v__tmp4;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLT(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SLT
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp5 = 0;
  v__tmp5 = (static_cast<int32_t>(v_rs1) < static_cast<int32_t>(v_rs2));
  v_rd = v__tmp5;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLTU(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SLTU
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp6 = 0;
  v__tmp6 = (v_rs1 < v_rs2);
  v_rd = v__tmp6;
  Ctx.setReg(rd, v_rd);
}


void EXEC_XOR(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction XOR
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp7 = 0;
  v__tmp7 = v_rs1 ^ v_rs2;
  v_rd = v__tmp7;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SRL(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SRL
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp8 = 0;
  v__tmp8 = static_cast<uint32_t>(v_rs1);
  uint32_t v__c9 = 0;
  v__c9 = 31;
  uint32_t v__tmp10 = 0;
  v__tmp10 = v_rs2 & v__c9;
  uint32_t v__tmp11 = 0;
  v__tmp11 = v__tmp8 >> v__tmp10;
  v_rd = v__tmp11;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SRA(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SRA
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  int32_t v__tmp12 = 0;
  v__tmp12 = static_cast<int32_t>(v_rs1);
  uint32_t v__c13 = 0;
  v__c13 = 31;
  uint32_t v__tmp14 = 0;
  v__tmp14 = v_rs2 & v__c13;
  uint32_t v__tmp15 = 0;
  v__tmp15 = v__tmp12 >> v__tmp14;
  v_rd = v__tmp15;
  Ctx.setReg(rd, v_rd);
}


void EXEC_OR(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction OR
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp16 = 0;
  v__tmp16 = v_rs1 | v_rs2;
  v_rd = v__tmp16;
  Ctx.setReg(rd, v_rd);
}


void EXEC_AND(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction AND
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp17 = 0;
  v__tmp17 = v_rs1 & v_rs2;
  v_rd = v__tmp17;
  Ctx.setReg(rd, v_rd);
}


void EXEC_ADDI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction ADDI
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  int32_t v__tmp18 = 0;
  v__tmp18 = Ctx.sext(v_imm, 11);
  uint32_t v__tmp19 = 0;
  v__tmp19 = v_rs1 + v__tmp18;
  v_rd = v__tmp19;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLTI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SLTI
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp20 = 0;
  v__tmp20 = (static_cast<int32_t>(v_rs1) < static_cast<int32_t>(v_imm));
  v_rd = v__tmp20;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLTIU(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SLTIU
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp21 = 0;
  v__tmp21 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp22 = 0;
  v__tmp22 = static_cast<uint32_t>(v_imm);
  uint32_t v__tmp23 = 0;
  v__tmp23 = (static_cast<int32_t>(v__tmp21) < static_cast<int32_t>(v__tmp22));
  v_rd = v__tmp23;
  Ctx.setReg(rd, v_rd);
}


void EXEC_XORI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction XORI
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp24 = 0;
  v__tmp24 = v_rs1 ^ v_imm;
  v_rd = v__tmp24;
  Ctx.setReg(rd, v_rd);
}


void EXEC_ORI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction ORI
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp25 = 0;
  v__tmp25 = v_rs1 | v_imm;
  v_rd = v__tmp25;
  Ctx.setReg(rd, v_rd);
}


void EXEC_ANDI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction ANDI
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp26 = 0;
  v__tmp26 = v_rs1 & v_imm;
  v_rd = v__tmp26;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLLI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SLLI
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp27 = 0;
  v__tmp27 = v_rs1 << v_imm;
  v_rd = v__tmp27;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SRLI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SRLI
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp28 = 0;
  v__tmp28 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp29 = 0;
  v__tmp29 = v__tmp28 >> v_imm;
  v_rd = v__tmp29;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SRAI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SRAI
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  int32_t v__tmp30 = 0;
  v__tmp30 = static_cast<int32_t>(v_rs1);
  uint32_t v__tmp31 = 0;
  v__tmp31 = v__tmp30 >> v_imm;
  v_rd = v__tmp31;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LB(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LB
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  int32_t v__tmp32 = 0;
  v__tmp32 = Ctx.sext(v_imm, 12);
  uint32_t v__tmp33 = 0;
  v__tmp33 = v_rs1 + v__tmp32;
  uint32_t v__tmp34 = 0;
  v__tmp34 = Ctx.read8(v__tmp33);
  uint32_t v__tmp35 = 0;
  v__tmp35 = Ctx.sext(v__tmp34, 8);
  v_rd = v__tmp35;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LH(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LH
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  int32_t v__tmp36 = 0;
  v__tmp36 = Ctx.sext(v_imm, 12);
  uint32_t v__tmp37 = 0;
  v__tmp37 = v_rs1 + v__tmp36;
  uint32_t v__tmp38 = 0;
  v__tmp38 = Ctx.read16(v__tmp37);
  uint32_t v__tmp39 = 0;
  v__tmp39 = Ctx.sext(v__tmp38, 16);
  v_rd = v__tmp39;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LW(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LW
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  int32_t v__tmp40 = 0;
  v__tmp40 = Ctx.sext(v_imm, 12);
  uint32_t v__tmp41 = 0;
  v__tmp41 = v_rs1 + v__tmp40;
  uint32_t v__tmp42 = 0;
  v__tmp42 = Ctx.read32(v__tmp41);
  v_rd = v__tmp42;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LBU(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LBU
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  int32_t v__tmp43 = 0;
  v__tmp43 = Ctx.sext(v_imm, 12);
  uint32_t v__tmp44 = 0;
  v__tmp44 = v_rs1 + v__tmp43;
  uint32_t v__tmp45 = 0;
  v__tmp45 = Ctx.read8(v__tmp44);
  uint32_t v__tmp46 = 0;
  v__tmp46 = Ctx.zext(v__tmp45, 8);
  v_rd = v__tmp46;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LHU(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LHU
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  int32_t v__tmp47 = 0;
  v__tmp47 = Ctx.sext(v_imm, 12);
  uint32_t v__tmp48 = 0;
  v__tmp48 = v_rs1 + v__tmp47;
  uint32_t v__tmp49 = 0;
  v__tmp49 = Ctx.read16(v__tmp48);
  uint32_t v__tmp50 = 0;
  v__tmp50 = Ctx.zext(v__tmp49, 16);
  v_rd = v__tmp50;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SB(ExecContext& Ctx, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// Instruction SB
{
  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp51 = 0;
  v__tmp51 = v_rs1 + v_imm;
  int32_t v__tmp52 = 0;
  v__tmp52 = Ctx.zext(v_rs2, 8);
  Ctx.write32(v__tmp51, v__tmp52);
}


void EXEC_SH(ExecContext& Ctx, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// Instruction SH
{
  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp53 = 0;
  v__tmp53 = v_rs1 + v_imm;
  int32_t v__tmp54 = 0;
  v__tmp54 = Ctx.zext(v_rs2, 16);
  Ctx.write32(v__tmp53, v__tmp54);
}


void EXEC_SW(ExecContext& Ctx, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// Instruction SW
{
  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp55 = 0;
  v__tmp55 = v_rs1 + v_imm;
  int32_t v__tmp56 = 0;
  v__tmp56 = Ctx.zext(v_rs2, 32);
  Ctx.write32(v__tmp55, v__tmp56);
}


void EXEC_JAL(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction JAL
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp57 = 0;
  v__tmp57 = Ctx.getPC();
  uint32_t v__c58 = 0;
  v__c58 = 4;
  uint64_t v__tmp59 = 0;
  v__tmp59 = v__tmp57 + v__c58;
  v_rd = v__tmp59;
  Ctx.setReg(rd, v_rd);
  uint32_t v__tmp60 = 0;
  v__tmp60 = Ctx.getPC();
  uint64_t v__tmp61 = 0;
  v__tmp61 = v__tmp60 + v_imm;
}


void EXEC_JALR(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction JALR
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp62 = 0;
  v__tmp62 = Ctx.getPC();
  uint32_t v__c63 = 0;
  v__c63 = 4;
  uint64_t v__tmp64 = 0;
  v__tmp64 = v__tmp62 + v__c63;
  v_rd = v__tmp64;
  Ctx.setReg(rd, v_rd);
  uint32_t v__tmp65 = 0;
  v__tmp65 = v_rs1 + v_imm;
  uint32_t v__c66 = 0;
  v__c66 = -2;
  uint32_t v__tmp67 = 0;
  v__tmp67 = v__tmp65 & v__c66;
  Ctx.setPC(v__tmp67);
}


void EXEC_LUI(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction LUI
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__c68 = 0;
  v__c68 = 12;
  uint32_t v__tmp69 = 0;
  v__tmp69 = v_imm << v__c68;
  v_rd = v__tmp69;
  Ctx.setReg(rd, v_rd);
}


void EXEC_AUIPC(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction AUIPC
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp70 = 0;
  v__tmp70 = Ctx.getPC();
  uint32_t v__c71 = 0;
  v__c71 = 12;
  uint32_t v__tmp72 = 0;
  v__tmp72 = v_imm << v__c71;
  uint64_t v__tmp73 = 0;
  v__tmp73 = v__tmp70 + v__tmp72;
  v_rd = v__tmp73;
  Ctx.setReg(rd, v_rd);
}


void EXEC_BEQ(ExecContext& Ctx, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// Instruction BEQ
{
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp74 = 0;
  v__tmp74 = Ctx.getPC();
  uint32_t v__tmp75 = 0;
  v__tmp75 = (v_rs1 == v_rs2);
  uint32_t v__tmp76 = 0;
  v__tmp76 = v__tmp75 * v_imm;
  uint64_t v__tmp77 = 0;
  v__tmp77 = v__tmp74 + v__tmp76;
  Ctx.setPC(v__tmp77);
}


void EXEC_ECALL(ExecContext& Ctx)
// Instruction ECALL
{
  Ctx.syscall();
}


void EXEC_MUL(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction MUL
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp79 = 0;
  v__tmp79 = v_rs1 * v_rs2;
  v_rd = v__tmp79;
  Ctx.setReg(rd, v_rd);
}


void EXEC_MULH(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction MULH
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  int64_t v__tmp80 = 0;
  v__tmp80 = Ctx.sext(v_rs1, 32);
  int64_t v__tmp81 = 0;
  v__tmp81 = Ctx.sext(v_rs2, 32);
  uint64_t v__tmp82 = 0;
  v__tmp82 = v__tmp80 * v__tmp81;
  int64_t v__tmp83 = 0;
  v__tmp83 = static_cast<int64_t>(v__tmp82);
  uint32_t v__c84 = 0;
  v__c84 = 32;
  uint64_t v__tmp85 = 0;
  v__tmp85 = v__tmp83 >> v__c84;
  v_rd = v__tmp85;
  Ctx.setReg(rd, v_rd);
}


void EXEC_MULHSU(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction MULHSU
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  int64_t v__tmp86 = 0;
  v__tmp86 = Ctx.sext(v_rs1, 32);
  int64_t v__tmp87 = 0;
  v__tmp87 = Ctx.zext(v_rs2, 32);
  uint64_t v__tmp88 = 0;
  v__tmp88 = v__tmp86 * v__tmp87;
  int64_t v__tmp89 = 0;
  v__tmp89 = static_cast<int64_t>(v__tmp88);
  uint32_t v__c90 = 0;
  v__c90 = 32;
  uint64_t v__tmp91 = 0;
  v__tmp91 = v__tmp89 >> v__c90;
  v_rd = v__tmp91;
  Ctx.setReg(rd, v_rd);
}


void EXEC_MULHU(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction MULHU
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  int64_t v__tmp92 = 0;
  v__tmp92 = Ctx.zext(v_rs1, 32);
  int64_t v__tmp93 = 0;
  v__tmp93 = Ctx.zext(v_rs2, 32);
  uint64_t v__tmp94 = 0;
  v__tmp94 = v__tmp92 * v__tmp93;
  uint32_t v__c95 = 0;
  v__c95 = 32;
  uint64_t v__tmp96 = 0;
  v__tmp96 = v__tmp94 >> v__c95;
  v_rd = v__tmp96;
  Ctx.setReg(rd, v_rd);
}


void EXEC_DIV(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction DIV
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  int32_t v__tmp97 = 0;
  v__tmp97 = static_cast<int32_t>(v_rs1);
  int32_t v__tmp98 = 0;
  v__tmp98 = static_cast<int32_t>(v_rs2);
  uint32_t v__tmp99 = 0;
  v__tmp99 = v__tmp97 / v__tmp98;
  v_rd = v__tmp99;
  Ctx.setReg(rd, v_rd);
}


void EXEC_DIVU(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction DIVU
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp100 = 0;
  v__tmp100 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp101 = 0;
  v__tmp101 = static_cast<uint32_t>(v_rs2);
  uint32_t v__tmp102 = 0;
  v__tmp102 = v__tmp100 / v__tmp101;
  v_rd = v__tmp102;
  Ctx.setReg(rd, v_rd);
}


void EXEC_REM(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction REM
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  int32_t v__tmp103 = 0;
  v__tmp103 = static_cast<int32_t>(v_rs1);
  int32_t v__tmp104 = 0;
  v__tmp104 = static_cast<int32_t>(v_rs2);
  uint32_t v__tmp105 = 0;
  v__tmp105 = v__tmp103 % v__tmp104;
  v_rd = v__tmp105;
  Ctx.setReg(rd, v_rd);
}


void EXEC_REMU(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction REMU
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp106 = 0;
  v__tmp106 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp107 = 0;
  v__tmp107 = static_cast<uint32_t>(v_rs2);
  uint32_t v__tmp108 = 0;
  v__tmp108 = v__tmp106 % v__tmp107;
  v_rd = v__tmp108;
  Ctx.setReg(rd, v_rd);
}

} // namespace TestSim
