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


void EXEC_MUL(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction MUL
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint32_t v__tmp18 = 0;
  v__tmp18 = v_rs1 * v_rs2;
  v_rd = v__tmp18;
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

  uint32_t v__tmp19 = 0;
  v__tmp19 = v_rs1 / v_rs2;
  v_rd = v__tmp19;
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

  uint32_t v__tmp20 = 0;
  v__tmp20 = v_rs1 % v_rs2;
  v_rd = v__tmp20;
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

  uint32_t v__tmp21 = 0;
  v__tmp21 = Ctx.sext(v_imm, 11);
  uint32_t v__tmp22 = 0;
  v__tmp22 = v_rs1 + v__tmp21;
  v_rd = v__tmp22;
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

  uint32_t v__tmp23 = 0;
  v__tmp23 = (static_cast<int32_t>(v_rs1) < static_cast<int32_t>(v_imm));
  v_rd = v__tmp23;
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

  uint32_t v__tmp24 = 0;
  v__tmp24 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp25 = 0;
  v__tmp25 = static_cast<uint32_t>(v_imm);
  uint32_t v__tmp26 = 0;
  v__tmp26 = (static_cast<int32_t>(v__tmp24) < static_cast<int32_t>(v__tmp25));
  v_rd = v__tmp26;
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

  uint32_t v__tmp27 = 0;
  v__tmp27 = v_rs1 ^ v_imm;
  v_rd = v__tmp27;
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

  uint32_t v__tmp28 = 0;
  v__tmp28 = v_rs1 | v_imm;
  v_rd = v__tmp28;
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

  uint32_t v__tmp29 = 0;
  v__tmp29 = v_rs1 & v_imm;
  v_rd = v__tmp29;
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

  uint32_t v__tmp30 = 0;
  v__tmp30 = v_rs1 << v_imm;
  v_rd = v__tmp30;
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

  uint32_t v__tmp31 = 0;
  v__tmp31 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp32 = 0;
  v__tmp32 = v__tmp31 >> v_imm;
  v_rd = v__tmp32;
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

  int32_t v__tmp33 = 0;
  v__tmp33 = static_cast<int32_t>(v_rs1);
  uint32_t v__tmp34 = 0;
  v__tmp34 = v__tmp33 >> v_imm;
  v_rd = v__tmp34;
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

  uint32_t v__tmp35 = 0;
  v__tmp35 = v_rs1 + v_imm;
  uint32_t v__tmp36 = 0;
  v__tmp36 = Ctx.read8(v__tmp35);
  uint32_t v__tmp37 = 0;
  v__tmp37 = Ctx.sext(v__tmp36, 8);
  v_rd = v__tmp37;
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

  uint32_t v__tmp38 = 0;
  v__tmp38 = v_rs1 + v_imm;
  uint32_t v__tmp39 = 0;
  v__tmp39 = Ctx.read16(v__tmp38);
  uint32_t v__tmp40 = 0;
  v__tmp40 = Ctx.sext(v__tmp39, 16);
  v_rd = v__tmp40;
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

  uint32_t v__tmp41 = 0;
  v__tmp41 = v_rs1 + v_imm;
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

  uint32_t v__tmp43 = 0;
  v__tmp43 = v_rs1 + v_imm;
  uint32_t v__tmp44 = 0;
  v__tmp44 = Ctx.read8(v__tmp43);
  uint32_t v__tmp45 = 0;
  v__tmp45 = Ctx.zext(v__tmp44, 8);
  v_rd = v__tmp45;
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

  uint32_t v__tmp46 = 0;
  v__tmp46 = v_rs1 + v_imm;
  uint32_t v__tmp47 = 0;
  v__tmp47 = Ctx.read16(v__tmp46);
  uint32_t v__tmp48 = 0;
  v__tmp48 = Ctx.zext(v__tmp47, 16);
  v_rd = v__tmp48;
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

  uint32_t v__tmp49 = 0;
  v__tmp49 = v_rs1 + v_imm;
  uint32_t v__tmp50 = 0;
  v__tmp50 = Ctx.zext(v_rs2, 8);
  Ctx.write8(v__tmp49, v__tmp50);
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

  uint32_t v__tmp51 = 0;
  v__tmp51 = v_rs1 + v_imm;
  uint32_t v__tmp52 = 0;
  v__tmp52 = Ctx.zext(v_rs2, 16);
  Ctx.write16(v__tmp51, v__tmp52);
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

  uint32_t v__tmp53 = 0;
  v__tmp53 = v_rs1 + v_imm;
  uint32_t v__tmp54 = 0;
  v__tmp54 = Ctx.zext(v_rs2, 32);
  Ctx.write32(v__tmp53, v__tmp54);
}


void EXEC_JAL(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction JAL
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp55 = 0;
  v__tmp55 = Ctx.getPC();
  uint32_t v__c56 = 0;
  v__c56 = 4;
  uint32_t v__tmp57 = 0;
  v__tmp57 = v__tmp55 + v__c56;
  v_rd = v__tmp57;
  Ctx.setReg(rd, v_rd);
  uint32_t v__tmp58 = 0;
  v__tmp58 = Ctx.getPC();
  uint32_t v__tmp59 = 0;
  v__tmp59 = v__tmp58 + v_imm;
}


void EXEC_JALR(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction JALR
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp60 = 0;
  v__tmp60 = Ctx.getPC();
  uint32_t v__c61 = 0;
  v__c61 = 4;
  uint32_t v__tmp62 = 0;
  v__tmp62 = v__tmp60 + v__c61;
  v_rd = v__tmp62;
  Ctx.setReg(rd, v_rd);
  uint32_t v__tmp63 = 0;
  v__tmp63 = v_rs1 + v_imm;
  uint32_t v__c64 = 0;
  v__c64 = -2;
  uint32_t v__tmp65 = 0;
  v__tmp65 = v__tmp63 & v__c64;
  Ctx.setPC(v__tmp65);
}


void EXEC_LUI(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction LUI
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__c66 = 0;
  v__c66 = 12;
  uint32_t v__tmp67 = 0;
  v__tmp67 = v_imm << v__c66;
  v_rd = v__tmp67;
  Ctx.setReg(rd, v_rd);
}


void EXEC_AUIPC(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction AUIPC
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp68 = 0;
  v__tmp68 = Ctx.getPC();
  uint32_t v__c69 = 0;
  v__c69 = 12;
  uint32_t v__tmp70 = 0;
  v__tmp70 = v_imm << v__c69;
  uint32_t v__tmp71 = 0;
  v__tmp71 = v__tmp68 + v__tmp70;
  v_rd = v__tmp71;
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

  uint32_t v__tmp72 = 0;
  v__tmp72 = Ctx.getPC();
  uint32_t v__tmp73 = 0;
  v__tmp73 = (v_rs1 == v_rs2);
  uint32_t v__tmp74 = 0;
  v__tmp74 = v__tmp73 * v_imm;
  uint32_t v__tmp75 = 0;
  v__tmp75 = v__tmp72 + v__tmp74;
  Ctx.setPC(v__tmp75);
}


void EXEC_ECALL(ExecContext& Ctx)
// Instruction ECALL
{
  Ctx.syscall();
}

} // namespace TestSim
