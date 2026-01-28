#pragma once
#include "ExecContext.hpp"
namespace TestSim {
using XReg = uint16_t;

void EXEC_ADD(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction ADD
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp0 = 0;
  v__tmp0 = v_rs1 + v_rs2;
  v_rd = v__tmp0;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SUB(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SUB
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp1 = 0;
  v__tmp1 = v_rs1 - v_rs2;
  v_rd = v__tmp1;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLL(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SLL
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__c2 = 0;
  v__c2 = 31;
  uint64_t v__tmp3 = 0;
  v__tmp3 = v_rs2 & v__c2;
  uint64_t v__tmp4 = 0;
  v__tmp4 = v_rs1 << v__tmp3;
  v_rd = v__tmp4;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLT(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SLT
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp5 = 0;
  v__tmp5 = (static_cast<int32_t>(v_rs1) < static_cast<int32_t>(v_rs2));
  v_rd = v__tmp5;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLTU(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SLTU
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp6 = 0;
  v__tmp6 = (v_rs1 < v_rs2);
  v_rd = v__tmp6;
  Ctx.setReg(rd, v_rd);
}


void EXEC_XOR(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction XOR
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp7 = 0;
  v__tmp7 = v_rs1 ^ v_rs2;
  v_rd = v__tmp7;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SRL(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SRL
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp8 = 0;
  v__tmp8 = static_cast<uint64_t>(v_rs1);
  uint64_t v__c9 = 0;
  v__c9 = 31;
  uint64_t v__tmp10 = 0;
  v__tmp10 = v_rs2 & v__c9;
  uint64_t v__tmp11 = 0;
  v__tmp11 = v__tmp8 >> v__tmp10;
  v_rd = v__tmp11;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SRA(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction SRA
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp12 = 0;
  v__tmp12 = static_cast<int64_t>(v_rs1);
  uint64_t v__c13 = 0;
  v__c13 = 31;
  uint64_t v__tmp14 = 0;
  v__tmp14 = v_rs2 & v__c13;
  uint64_t v__tmp15 = 0;
  v__tmp15 = v__tmp12 >> v__tmp14;
  v_rd = v__tmp15;
  Ctx.setReg(rd, v_rd);
}


void EXEC_OR(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction OR
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp16 = 0;
  v__tmp16 = v_rs1 | v_rs2;
  v_rd = v__tmp16;
  Ctx.setReg(rd, v_rd);
}


void EXEC_AND(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction AND
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp17 = 0;
  v__tmp17 = v_rs1 & v_rs2;
  v_rd = v__tmp17;
  Ctx.setReg(rd, v_rd);
}


void EXEC_MUL(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction MUL
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp18 = 0;
  v__tmp18 = v_rs1 * v_rs2;
  v_rd = v__tmp18;
  Ctx.setReg(rd, v_rd);
}


void EXEC_DIV(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction DIV
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp19 = 0;
  v__tmp19 = v_rs1 / v_rs2;
  v_rd = v__tmp19;
  Ctx.setReg(rd, v_rd);
}


void EXEC_REM(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
// Instruction REM
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v__tmp20 = 0;
  v__tmp20 = v_rs1 % v_rs2;
  v_rd = v__tmp20;
  Ctx.setReg(rd, v_rd);
}


void EXEC_ADDI(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction ADDI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp21 = 0;
  v__tmp21 = v_rs1 + v_imm;
  v_rd = v__tmp21;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLTI(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SLTI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp22 = 0;
  v__tmp22 = (static_cast<int32_t>(v_rs1) < static_cast<int32_t>(v_imm));
  v_rd = v__tmp22;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLTIU(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SLTIU
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp23 = 0;
  v__tmp23 = static_cast<uint64_t>(v_rs1);
  uint64_t v__tmp24 = 0;
  v__tmp24 = static_cast<uint64_t>(v_imm);
  uint64_t v__tmp25 = 0;
  v__tmp25 = (static_cast<int32_t>(v__tmp23) < static_cast<int32_t>(v__tmp24));
  v_rd = v__tmp25;
  Ctx.setReg(rd, v_rd);
}


void EXEC_XORI(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction XORI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp26 = 0;
  v__tmp26 = v_rs1 ^ v_imm;
  v_rd = v__tmp26;
  Ctx.setReg(rd, v_rd);
}


void EXEC_ORI(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction ORI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp27 = 0;
  v__tmp27 = v_rs1 | v_imm;
  v_rd = v__tmp27;
  Ctx.setReg(rd, v_rd);
}


void EXEC_ANDI(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction ANDI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp28 = 0;
  v__tmp28 = v_rs1 & v_imm;
  v_rd = v__tmp28;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SLLI(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SLLI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp29 = 0;
  v__tmp29 = v_rs1 << v_imm;
  v_rd = v__tmp29;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SRLI(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SRLI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp30 = 0;
  v__tmp30 = static_cast<uint64_t>(v_rs1);
  uint64_t v__tmp31 = 0;
  v__tmp31 = v__tmp30 >> v_imm;
  v_rd = v__tmp31;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SRAI(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SRAI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp32 = 0;
  v__tmp32 = static_cast<int64_t>(v_rs1);
  uint64_t v__tmp33 = 0;
  v__tmp33 = v__tmp32 >> v_imm;
  v_rd = v__tmp33;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LB(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LB
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp34 = 0;
  v__tmp34 = v_rs1 + v_imm;
  uint64_t v__tmp35 = 0;
  v__tmp35 = Ctx.read8(v__tmp34);
  uint64_t v__tmp36 = 0;
  v__tmp36 = Ctx.sext(v__tmp35, 8);
  v_rd = v__tmp36;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LH(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LH
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp37 = 0;
  v__tmp37 = v_rs1 + v_imm;
  uint64_t v__tmp38 = 0;
  v__tmp38 = Ctx.read16(v__tmp37);
  uint64_t v__tmp39 = 0;
  v__tmp39 = Ctx.sext(v__tmp38, 16);
  v_rd = v__tmp39;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LW(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LW
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp40 = 0;
  v__tmp40 = v_rs1 + v_imm;
  uint64_t v__tmp41 = 0;
  v__tmp41 = Ctx.read32(v__tmp40);
  v_rd = v__tmp41;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LBU(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LBU
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp42 = 0;
  v__tmp42 = v_rs1 + v_imm;
  uint64_t v__tmp43 = 0;
  v__tmp43 = Ctx.read8(v__tmp42);
  uint64_t v__tmp44 = 0;
  v__tmp44 = Ctx.zext(v__tmp43, 8);
  v_rd = v__tmp44;
  Ctx.setReg(rd, v_rd);
}


void EXEC_LHU(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LHU
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp45 = 0;
  v__tmp45 = v_rs1 + v_imm;
  uint64_t v__tmp46 = 0;
  v__tmp46 = Ctx.read16(v__tmp45);
  uint64_t v__tmp47 = 0;
  v__tmp47 = Ctx.zext(v__tmp46, 16);
  v_rd = v__tmp47;
  Ctx.setReg(rd, v_rd);
}


void EXEC_SB(GeneralSim::ExecContext& Ctx, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// Instruction SB
{
  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp48 = 0;
  v__tmp48 = v_rs1 + v_imm;
  uint64_t v__tmp49 = 0;
  v__tmp49 = Ctx.zext(v_rs2, 8);
  Ctx.write8(v__tmp48, v__tmp49);
}


void EXEC_SH(GeneralSim::ExecContext& Ctx, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// Instruction SH
{
  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp50 = 0;
  v__tmp50 = v_rs1 + v_imm;
  uint64_t v__tmp51 = 0;
  v__tmp51 = Ctx.zext(v_rs2, 16);
  Ctx.write16(v__tmp50, v__tmp51);
}


void EXEC_SW(GeneralSim::ExecContext& Ctx, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// Instruction SW
{
  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp52 = 0;
  v__tmp52 = v_rs1 + v_imm;
  uint64_t v__tmp53 = 0;
  v__tmp53 = Ctx.zext(v_rs2, 32);
  Ctx.write32(v__tmp52, v__tmp53);
}


void EXEC_JAL(GeneralSim::ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction JAL
{
  uint64_t v_rd = 0;
  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp54 = 0;
  v__tmp54 = Ctx.getPC();
  uint64_t v__c55 = 0;
  v__c55 = 4;
  uint64_t v__tmp56 = 0;
  v__tmp56 = v__tmp54 + v__c55;
  v_rd = v__tmp56;
  Ctx.setReg(rd, v_rd);
  uint64_t v__tmp57 = 0;
  v__tmp57 = Ctx.getPC();
  uint64_t v__tmp58 = 0;
  v__tmp58 = v__tmp57 + v_imm;
}


void EXEC_JALR(GeneralSim::ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction JALR
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp59 = 0;
  v__tmp59 = Ctx.getPC();
  uint64_t v__c60 = 0;
  v__c60 = 4;
  uint64_t v__tmp61 = 0;
  v__tmp61 = v__tmp59 + v__c60;
  v_rd = v__tmp61;
  Ctx.setReg(rd, v_rd);
  uint64_t v__tmp62 = 0;
  v__tmp62 = v_rs1 + v_imm;
  uint64_t v__c63 = 0;
  v__c63 = -2;
  uint64_t v__tmp64 = 0;
  v__tmp64 = v__tmp62 & v__c63;
  Ctx.setPC(v__tmp64);
}


void EXEC_LUI(GeneralSim::ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction LUI
{
  uint64_t v_rd = 0;
  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__c65 = 0;
  v__c65 = 12;
  uint64_t v__tmp66 = 0;
  v__tmp66 = v_imm << v__c65;
  v_rd = v__tmp66;
  Ctx.setReg(rd, v_rd);
}


void EXEC_AUIPC(GeneralSim::ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction AUIPC
{
  uint64_t v_rd = 0;
  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp67 = 0;
  v__tmp67 = Ctx.getPC();
  uint64_t v__c68 = 0;
  v__c68 = 12;
  uint64_t v__tmp69 = 0;
  v__tmp69 = v_imm << v__c68;
  uint64_t v__tmp70 = 0;
  v__tmp70 = v__tmp67 + v__tmp69;
  v_rd = v__tmp70;
  Ctx.setReg(rd, v_rd);
}


void EXEC_BEQ(GeneralSim::ExecContext& Ctx, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// Instruction BEQ
{
  uint64_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = Ctx.getReg(rs2);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp71 = 0;
  v__tmp71 = Ctx.getPC();
  uint64_t v__tmp72 = 0;
  v__tmp72 = (v_rs1 == v_rs2);
  uint64_t v__tmp73 = 0;
  v__tmp73 = v__tmp72 * v_imm;
  uint64_t v__tmp74 = 0;
  v__tmp74 = v__tmp71 + v__tmp73;
  Ctx.setPC(v__tmp74);
}


void EXEC_ECALL(GeneralSim::ExecContext& Ctx)
// Instruction ECALL
{
  uint64_t v__tmp75 = 0;
  Ctx.syscall(v__tmp75);
}
} // namespace GeneralSim
