#pragma once
#include "ExecContext.hpp"
#include "TestInfra.hpp"
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
  v__tmp18 = Helpers::sext(v_imm, 12);
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
  v__tmp32 = Helpers::sext(v_imm, 12);
  uint32_t v__tmp33 = 0;
  v__tmp33 = v_rs1 + v__tmp32;
  uint32_t v__tmp34 = 0;
  v__tmp34 = Ctx.read8(v__tmp33);
  uint32_t v__tmp35 = 0;
  v__tmp35 = Helpers::sext(v__tmp34, 8);
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
  v__tmp36 = Helpers::sext(v_imm, 12);
  uint32_t v__tmp37 = 0;
  v__tmp37 = v_rs1 + v__tmp36;
  uint32_t v__tmp38 = 0;
  v__tmp38 = Ctx.read16(v__tmp37);
  uint32_t v__tmp39 = 0;
  v__tmp39 = Helpers::sext(v__tmp38, 16);
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
  v__tmp40 = Helpers::sext(v_imm, 12);
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
  v__tmp43 = Helpers::sext(v_imm, 12);
  uint32_t v__tmp44 = 0;
  v__tmp44 = v_rs1 + v__tmp43;
  uint32_t v__tmp45 = 0;
  v__tmp45 = Ctx.read8(v__tmp44);
  uint32_t v__tmp46 = 0;
  v__tmp46 = Helpers::zext(v__tmp45, 8);
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
  v__tmp47 = Helpers::sext(v_imm, 12);
  uint32_t v__tmp48 = 0;
  v__tmp48 = v_rs1 + v__tmp47;
  uint32_t v__tmp49 = 0;
  v__tmp49 = Ctx.read16(v__tmp48);
  uint32_t v__tmp50 = 0;
  v__tmp50 = Helpers::zext(v__tmp49, 16);
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

  int32_t v__tmp51 = 0;
  v__tmp51 = Helpers::sext(v_imm, 12);
  uint32_t v__tmp52 = 0;
  v__tmp52 = v_rs1 + v__tmp51;
  int32_t v__tmp53 = 0;
  v__tmp53 = Helpers::zext(v_rs2, 8);
  Ctx.write32(v__tmp52, v__tmp53);
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

  int32_t v__tmp54 = 0;
  v__tmp54 = Helpers::sext(v_imm, 12);
  uint32_t v__tmp55 = 0;
  v__tmp55 = v_rs1 + v__tmp54;
  int32_t v__tmp56 = 0;
  v__tmp56 = Helpers::zext(v_rs2, 16);
  Ctx.write32(v__tmp55, v__tmp56);
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

  int32_t v__tmp57 = 0;
  v__tmp57 = Helpers::sext(v_imm, 12);
  uint32_t v__tmp58 = 0;
  v__tmp58 = v_rs1 + v__tmp57;
  Ctx.write32(v__tmp58, v_rs2);
}


void EXEC_JAL(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction JAL
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp59 = 0;
  v__tmp59 = Ctx.getPC();
  uint32_t v__c60 = 0;
  v__c60 = 4;
  uint32_t v__tmp61 = 0;
  v__tmp61 = v__tmp59 + v__c60;
  v_rd = v__tmp61;
  Ctx.setReg(rd, v_rd);
  uint32_t v__tmp62 = 0;
  v__tmp62 = Ctx.getPC();
  int32_t v__tmp63 = 0;
  v__tmp63 = Helpers::sext(v_imm, 21);
  uint32_t v__tmp64 = 0;
  v__tmp64 = v__tmp62 + v__tmp63;
  Ctx.setPC(v__tmp64);
}


void EXEC_JALR(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction JALR
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp65 = 0;
  v__tmp65 = Ctx.getPC();
  uint32_t v__c66 = 0;
  v__c66 = 4;
  uint32_t v__tmp67 = 0;
  v__tmp67 = v__tmp65 + v__c66;
  v_rd = v__tmp67;
  Ctx.setReg(rd, v_rd);
  int32_t v__tmp68 = 0;
  v__tmp68 = Helpers::sext(v_imm, 12);
  uint32_t v__tmp69 = 0;
  v__tmp69 = v_rs1 + v__tmp68;
  uint32_t v__c70 = 0;
  v__c70 = -2;
  uint32_t v__tmp71 = 0;
  v__tmp71 = v__tmp69 & v__c70;
  Ctx.setPC(v__tmp71);
}


void EXEC_LUI(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction LUI
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__c72 = 0;
  v__c72 = 12;
  uint32_t v__tmp73 = 0;
  v__tmp73 = v_imm << v__c72;
  v_rd = v__tmp73;
  Ctx.setReg(rd, v_rd);
}


void EXEC_AUIPC(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction AUIPC
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp74 = 0;
  v__tmp74 = Ctx.getPC();
  uint32_t v__c75 = 0;
  v__c75 = 12;
  uint32_t v__tmp76 = 0;
  v__tmp76 = v_imm << v__c75;
  uint32_t v__tmp77 = 0;
  v__tmp77 = v__tmp74 + v__tmp76;
  v_rd = v__tmp77;
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

  uint32_t v__tmp78 = 0;
  v__tmp78 = Ctx.getPC();
  uint32_t v__tmp79 = 0;
  v__tmp79 = (v_rs1 == v_rs2);
  int32_t v__tmp80 = 0;
  v__tmp80 = Helpers::sext(v_imm, 13);
  uint32_t v__tmp81 = 0;
  v__tmp81 = v__tmp79 * v__tmp80;
  uint32_t v__tmp82 = 0;
  v__tmp82 = v__tmp78 + v__tmp81;
  Ctx.setPC(v__tmp82);
}


void EXEC_BNE(ExecContext& Ctx, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// Instruction BNE
{
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp83 = 0;
  v__tmp83 = Ctx.getPC();
  uint32_t v__tmp84 = 0;
  v__tmp84 = (v_rs1 != v_rs2);
  int32_t v__tmp85 = 0;
  v__tmp85 = Helpers::sext(v_imm, 13);
  uint32_t v__tmp86 = 0;
  v__tmp86 = v__tmp84 * v__tmp85;
  uint32_t v__tmp87 = 0;
  v__tmp87 = v__tmp83 + v__tmp86;
  Ctx.setPC(v__tmp87);
}


void EXEC_BLT(ExecContext& Ctx, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// Instruction BLT
{
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp88 = 0;
  v__tmp88 = Ctx.getPC();
  uint32_t v__tmp89 = 0;
  v__tmp89 = (static_cast<int32_t>(v_rs1) < static_cast<int32_t>(v_rs2));
  int32_t v__tmp90 = 0;
  v__tmp90 = Helpers::sext(v_imm, 13);
  uint32_t v__tmp91 = 0;
  v__tmp91 = v__tmp89 * v__tmp90;
  uint32_t v__tmp92 = 0;
  v__tmp92 = v__tmp88 + v__tmp91;
  Ctx.setPC(v__tmp92);
}


void EXEC_BGE(ExecContext& Ctx, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// Instruction BGE
{
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp93 = 0;
  v__tmp93 = Ctx.getPC();
  uint32_t v__tmp94 = 0;
  v__tmp94 = (static_cast<int32_t>(v_rs1) >= static_cast<int32_t>(v_rs2));
  int32_t v__tmp95 = 0;
  v__tmp95 = Helpers::sext(v_imm, 13);
  uint32_t v__tmp96 = 0;
  v__tmp96 = v__tmp94 * v__tmp95;
  uint32_t v__tmp97 = 0;
  v__tmp97 = v__tmp93 + v__tmp96;
  Ctx.setPC(v__tmp97);
}


void EXEC_BGEU(ExecContext& Ctx, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// Instruction BGEU
{
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp98 = 0;
  v__tmp98 = Ctx.getPC();
  uint32_t v__tmp99 = 0;
  v__tmp99 = (v_rs1 >= v_rs2);
  int32_t v__tmp100 = 0;
  v__tmp100 = Helpers::sext(v_imm, 13);
  uint32_t v__tmp101 = 0;
  v__tmp101 = v__tmp99 * v__tmp100;
  uint32_t v__tmp102 = 0;
  v__tmp102 = v__tmp98 + v__tmp101;
  Ctx.setPC(v__tmp102);
}


void EXEC_BLTU(ExecContext& Ctx, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// Instruction BLTU
{
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp103 = 0;
  v__tmp103 = Ctx.getPC();
  uint32_t v__tmp104 = 0;
  v__tmp104 = (v_rs1 < v_rs2);
  int32_t v__tmp105 = 0;
  v__tmp105 = Helpers::sext(v_imm, 13);
  uint32_t v__tmp106 = 0;
  v__tmp106 = v__tmp104 * v__tmp105;
  uint32_t v__tmp107 = 0;
  v__tmp107 = v__tmp103 + v__tmp106;
  Ctx.setPC(v__tmp107);
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

  uint32_t v__tmp109 = 0;
  v__tmp109 = v_rs1 * v_rs2;
  v_rd = v__tmp109;
  Ctx.setReg(rd, v_rd);
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

  int64_t v__tmp110 = 0;
  v__tmp110 = Helpers::sext(v_rs1, 32);
  int64_t v__tmp111 = 0;
  v__tmp111 = Helpers::sext(v_rs2, 32);
  uint64_t v__tmp112 = 0;
  v__tmp112 = v__tmp110 * v__tmp111;
  int64_t v__tmp113 = 0;
  v__tmp113 = static_cast<int64_t>(v__tmp112);
  uint32_t v__c114 = 0;
  v__c114 = 32;
  uint64_t v__tmp115 = 0;
  v__tmp115 = v__tmp113 >> v__c114;
  v_rd = v__tmp115;
  Ctx.setReg(rd, v_rd);
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

  int64_t v__tmp116 = 0;
  v__tmp116 = Helpers::sext(v_rs1, 32);
  int64_t v__tmp117 = 0;
  v__tmp117 = Helpers::zext(v_rs2, 32);
  uint64_t v__tmp118 = 0;
  v__tmp118 = v__tmp116 * v__tmp117;
  int64_t v__tmp119 = 0;
  v__tmp119 = static_cast<int64_t>(v__tmp118);
  uint32_t v__c120 = 0;
  v__c120 = 32;
  uint64_t v__tmp121 = 0;
  v__tmp121 = v__tmp119 >> v__c120;
  v_rd = v__tmp121;
  Ctx.setReg(rd, v_rd);
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

  int64_t v__tmp122 = 0;
  v__tmp122 = Helpers::zext(v_rs1, 32);
  int64_t v__tmp123 = 0;
  v__tmp123 = Helpers::zext(v_rs2, 32);
  uint64_t v__tmp124 = 0;
  v__tmp124 = v__tmp122 * v__tmp123;
  uint32_t v__c125 = 0;
  v__c125 = 32;
  uint64_t v__tmp126 = 0;
  v__tmp126 = v__tmp124 >> v__c125;
  v_rd = v__tmp126;
  Ctx.setReg(rd, v_rd);
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

  int32_t v__tmp127 = 0;
  v__tmp127 = static_cast<int32_t>(v_rs1);
  int32_t v__tmp128 = 0;
  v__tmp128 = static_cast<int32_t>(v_rs2);
  uint32_t v__tmp129 = 0;
  v__tmp129 = v__tmp127 / v__tmp128;
  v_rd = v__tmp129;
  Ctx.setReg(rd, v_rd);
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

  uint32_t v__tmp130 = 0;
  v__tmp130 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp131 = 0;
  v__tmp131 = static_cast<uint32_t>(v_rs2);
  uint32_t v__tmp132 = 0;
  v__tmp132 = v__tmp130 / v__tmp131;
  v_rd = v__tmp132;
  Ctx.setReg(rd, v_rd);
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

  int32_t v__tmp133 = 0;
  v__tmp133 = static_cast<int32_t>(v_rs1);
  int32_t v__tmp134 = 0;
  v__tmp134 = static_cast<int32_t>(v_rs2);
  uint32_t v__tmp135 = 0;
  v__tmp135 = v__tmp133 % v__tmp134;
  v_rd = v__tmp135;
  Ctx.setReg(rd, v_rd);
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

  uint32_t v__tmp136 = 0;
  v__tmp136 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp137 = 0;
  v__tmp137 = static_cast<uint32_t>(v_rs2);
  uint32_t v__tmp138 = 0;
  v__tmp138 = v__tmp136 % v__tmp137;
  v_rd = v__tmp138;
  Ctx.setReg(rd, v_rd);
  Ctx.setReg(rd, v_rd);
}

} // namespace TestSim
