#include "Executor.hpp"
namespace GeneralSim {
using XReg = uint16_t;
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
  v__tmp18 = Ctx.sext(v_imm, 12);
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

  int32_t v__tmp51 = 0;
  v__tmp51 = Ctx.sext(v_imm, 12);
  uint32_t v__tmp52 = 0;
  v__tmp52 = v_rs1 + v__tmp51;
  int32_t v__tmp53 = 0;
  v__tmp53 = Ctx.zext(v_rs2, 8);
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
  v__tmp54 = Ctx.sext(v_imm, 12);
  uint32_t v__tmp55 = 0;
  v__tmp55 = v_rs1 + v__tmp54;
  int32_t v__tmp56 = 0;
  v__tmp56 = Ctx.zext(v_rs2, 16);
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
  v__tmp57 = Ctx.sext(v_imm, 12);
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
  uint32_t v__tmp63 = 0;
  v__tmp63 = v__tmp62 + v_imm;
  Ctx.setPC(v__tmp63);
}


void EXEC_JALR(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction JALR
{
  uint32_t v_rd = 0;
  uint32_t v_rs1 = 0;
  v_rs1 = Ctx.getReg(rs1);

  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp64 = 0;
  v__tmp64 = Ctx.getPC();
  uint32_t v__c65 = 0;
  v__c65 = 4;
  uint32_t v__tmp66 = 0;
  v__tmp66 = v__tmp64 + v__c65;
  v_rd = v__tmp66;
  Ctx.setReg(rd, v_rd);
  uint32_t v__tmp67 = 0;
  v__tmp67 = v_rs1 + v_imm;
  uint32_t v__c68 = 0;
  v__c68 = -2;
  uint32_t v__tmp69 = 0;
  v__tmp69 = v__tmp67 & v__c68;
  Ctx.setPC(v__tmp69);
}


void EXEC_LUI(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction LUI
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__c70 = 0;
  v__c70 = 12;
  uint32_t v__tmp71 = 0;
  v__tmp71 = v_imm << v__c70;
  v_rd = v__tmp71;
  Ctx.setReg(rd, v_rd);
}


void EXEC_AUIPC(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
// Instruction AUIPC
{
  uint32_t v_rd = 0;
  uint32_t v_imm = 0;
  v_imm = imm.raw();

  uint32_t v__tmp72 = 0;
  v__tmp72 = Ctx.getPC();
  uint32_t v__c73 = 0;
  v__c73 = 12;
  uint32_t v__tmp74 = 0;
  v__tmp74 = v_imm << v__c73;
  uint32_t v__tmp75 = 0;
  v__tmp75 = v__tmp72 + v__tmp74;
  v_rd = v__tmp75;
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

  uint32_t v__tmp76 = 0;
  v__tmp76 = Ctx.getPC();
  uint32_t v__tmp77 = 0;
  v__tmp77 = (v_rs1 == v_rs2);
  int32_t v__tmp78 = 0;
  v__tmp78 = Ctx.sext(v_imm, 13);
  uint32_t v__tmp79 = 0;
  v__tmp79 = v__tmp77 * v__tmp78;
  uint32_t v__tmp80 = 0;
  v__tmp80 = v__tmp76 + v__tmp79;
  Ctx.setPC(v__tmp80);
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

  uint32_t v__tmp81 = 0;
  v__tmp81 = Ctx.getPC();
  uint32_t v__tmp82 = 0;
  v__tmp82 = (v_rs1 != v_rs2);
  int32_t v__tmp83 = 0;
  v__tmp83 = Ctx.sext(v_imm, 13);
  uint32_t v__tmp84 = 0;
  v__tmp84 = v__tmp82 * v__tmp83;
  uint32_t v__tmp85 = 0;
  v__tmp85 = v__tmp81 + v__tmp84;
  Ctx.setPC(v__tmp85);
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

  uint32_t v__tmp86 = 0;
  v__tmp86 = Ctx.getPC();
  uint32_t v__tmp87 = 0;
  v__tmp87 = (static_cast<int32_t>(v_rs1) < static_cast<int32_t>(v_rs2));
  int32_t v__tmp88 = 0;
  v__tmp88 = Ctx.sext(v_imm, 13);
  uint32_t v__tmp89 = 0;
  v__tmp89 = v__tmp87 * v__tmp88;
  uint32_t v__tmp90 = 0;
  v__tmp90 = v__tmp86 + v__tmp89;
  Ctx.setPC(v__tmp90);
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

  uint32_t v__tmp91 = 0;
  v__tmp91 = Ctx.getPC();
  uint32_t v__tmp92 = 0;
  v__tmp92 = (static_cast<int32_t>(v_rs1) >= static_cast<int32_t>(v_rs2));
  int32_t v__tmp93 = 0;
  v__tmp93 = Ctx.sext(v_imm, 13);
  uint32_t v__tmp94 = 0;
  v__tmp94 = v__tmp92 * v__tmp93;
  uint32_t v__tmp95 = 0;
  v__tmp95 = v__tmp91 + v__tmp94;
  Ctx.setPC(v__tmp95);
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

  uint32_t v__tmp96 = 0;
  v__tmp96 = Ctx.getPC();
  uint32_t v__tmp97 = 0;
  v__tmp97 = (v_rs1 >= v_rs2);
  int32_t v__tmp98 = 0;
  v__tmp98 = Ctx.sext(v_imm, 13);
  uint32_t v__tmp99 = 0;
  v__tmp99 = v__tmp97 * v__tmp98;
  uint32_t v__tmp100 = 0;
  v__tmp100 = v__tmp96 + v__tmp99;
  Ctx.setPC(v__tmp100);
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

  uint32_t v__tmp101 = 0;
  v__tmp101 = Ctx.getPC();
  uint32_t v__tmp102 = 0;
  v__tmp102 = (v_rs1 < v_rs2);
  int32_t v__tmp103 = 0;
  v__tmp103 = Ctx.sext(v_imm, 13);
  uint32_t v__tmp104 = 0;
  v__tmp104 = v__tmp102 * v__tmp103;
  uint32_t v__tmp105 = 0;
  v__tmp105 = v__tmp101 + v__tmp104;
  Ctx.setPC(v__tmp105);
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

  uint32_t v__tmp107 = 0;
  v__tmp107 = v_rs1 * v_rs2;
  v_rd = v__tmp107;
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

  int64_t v__tmp108 = 0;
  v__tmp108 = Ctx.sext(v_rs1, 32);
  int64_t v__tmp109 = 0;
  v__tmp109 = Ctx.sext(v_rs2, 32);
  uint64_t v__tmp110 = 0;
  v__tmp110 = v__tmp108 * v__tmp109;
  int64_t v__tmp111 = 0;
  v__tmp111 = static_cast<int64_t>(v__tmp110);
  uint32_t v__c112 = 0;
  v__c112 = 32;
  uint64_t v__tmp113 = 0;
  v__tmp113 = v__tmp111 >> v__c112;
  v_rd = v__tmp113;
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

  int64_t v__tmp114 = 0;
  v__tmp114 = Ctx.sext(v_rs1, 32);
  int64_t v__tmp115 = 0;
  v__tmp115 = Ctx.zext(v_rs2, 32);
  uint64_t v__tmp116 = 0;
  v__tmp116 = v__tmp114 * v__tmp115;
  int64_t v__tmp117 = 0;
  v__tmp117 = static_cast<int64_t>(v__tmp116);
  uint32_t v__c118 = 0;
  v__c118 = 32;
  uint64_t v__tmp119 = 0;
  v__tmp119 = v__tmp117 >> v__c118;
  v_rd = v__tmp119;
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

  int64_t v__tmp120 = 0;
  v__tmp120 = Ctx.zext(v_rs1, 32);
  int64_t v__tmp121 = 0;
  v__tmp121 = Ctx.zext(v_rs2, 32);
  uint64_t v__tmp122 = 0;
  v__tmp122 = v__tmp120 * v__tmp121;
  uint32_t v__c123 = 0;
  v__c123 = 32;
  uint64_t v__tmp124 = 0;
  v__tmp124 = v__tmp122 >> v__c123;
  v_rd = v__tmp124;
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

  int32_t v__tmp125 = 0;
  v__tmp125 = static_cast<int32_t>(v_rs1);
  int32_t v__tmp126 = 0;
  v__tmp126 = static_cast<int32_t>(v_rs2);
  uint32_t v__tmp127 = 0;
  v__tmp127 = v__tmp125 / v__tmp126;
  v_rd = v__tmp127;
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

  uint32_t v__tmp128 = 0;
  v__tmp128 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp129 = 0;
  v__tmp129 = static_cast<uint32_t>(v_rs2);
  uint32_t v__tmp130 = 0;
  v__tmp130 = v__tmp128 / v__tmp129;
  v_rd = v__tmp130;
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

  int32_t v__tmp131 = 0;
  v__tmp131 = static_cast<int32_t>(v_rs1);
  int32_t v__tmp132 = 0;
  v__tmp132 = static_cast<int32_t>(v_rs2);
  uint32_t v__tmp133 = 0;
  v__tmp133 = v__tmp131 % v__tmp132;
  v_rd = v__tmp133;
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

  uint32_t v__tmp134 = 0;
  v__tmp134 = static_cast<uint32_t>(v_rs1);
  uint32_t v__tmp135 = 0;
  v__tmp135 = static_cast<uint32_t>(v_rs2);
  uint32_t v__tmp136 = 0;
  v__tmp136 = v__tmp134 % v__tmp135;
  v_rd = v__tmp136;
  Ctx.setReg(rd, v_rd);
}

void Executor::execute(const Instruction &Inst, ExecContext &Ctx) {
  std::visit([&](auto&& I) {
    using T = std::decay_t<decltype(I)>;
    if constexpr (std::is_same_v<T, ADD>) {
      EXEC_ADD(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, SUB>) {
      EXEC_SUB(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, SLL>) {
      EXEC_SLL(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, SLT>) {
      EXEC_SLT(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, SLTU>) {
      EXEC_SLTU(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, XOR>) {
      EXEC_XOR(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, SRL>) {
      EXEC_SRL(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, SRA>) {
      EXEC_SRA(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, OR>) {
      EXEC_OR(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, AND>) {
      EXEC_AND(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, ADDI>) {
      EXEC_ADDI(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, SLTI>) {
      EXEC_SLTI(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, SLTIU>) {
      EXEC_SLTIU(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, XORI>) {
      EXEC_XORI(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, ORI>) {
      EXEC_ORI(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, ANDI>) {
      EXEC_ANDI(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, SLLI>) {
      EXEC_SLLI(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, SRLI>) {
      EXEC_SRLI(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, SRAI>) {
      EXEC_SRAI(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, LB>) {
      EXEC_LB(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, LH>) {
      EXEC_LH(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, LW>) {
      EXEC_LW(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, LBU>) {
      EXEC_LBU(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, LHU>) {
      EXEC_LHU(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, SB>) {
      EXEC_SB(Ctx, I.rs2, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, SH>) {
      EXEC_SH(Ctx, I.rs2, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, SW>) {
      EXEC_SW(Ctx, I.rs2, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, JAL>) {
      EXEC_JAL(Ctx, I.rd, I.imm);
    } else if constexpr (std::is_same_v<T, JALR>) {
      EXEC_JALR(Ctx, I.rd, I.rs1, I.imm);
    } else if constexpr (std::is_same_v<T, LUI>) {
      EXEC_LUI(Ctx, I.rd, I.imm);
    } else if constexpr (std::is_same_v<T, AUIPC>) {
      EXEC_AUIPC(Ctx, I.rd, I.imm);
    } else if constexpr (std::is_same_v<T, BEQ>) {
      EXEC_BEQ(Ctx, I.rs1, I.rs2, I.imm);
    } else if constexpr (std::is_same_v<T, BNE>) {
      EXEC_BNE(Ctx, I.rs1, I.rs2, I.imm);
    } else if constexpr (std::is_same_v<T, BLT>) {
      EXEC_BLT(Ctx, I.rs1, I.rs2, I.imm);
    } else if constexpr (std::is_same_v<T, BGE>) {
      EXEC_BGE(Ctx, I.rs1, I.rs2, I.imm);
    } else if constexpr (std::is_same_v<T, BGEU>) {
      EXEC_BGEU(Ctx, I.rs1, I.rs2, I.imm);
    } else if constexpr (std::is_same_v<T, BLTU>) {
      EXEC_BLTU(Ctx, I.rs1, I.rs2, I.imm);
    } else if constexpr (std::is_same_v<T, ECALL>) {
      EXEC_ECALL(Ctx);
    } else if constexpr (std::is_same_v<T, MUL>) {
      EXEC_MUL(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, MULH>) {
      EXEC_MULH(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, MULHSU>) {
      EXEC_MULHSU(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, MULHU>) {
      EXEC_MULHU(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, DIV>) {
      EXEC_DIV(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, DIVU>) {
      EXEC_DIVU(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, REM>) {
      EXEC_REM(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, REMU>) {
      EXEC_REMU(Ctx, I.rd, I.rs1, I.rs2);
    }
    }, Inst);
}
} // namespace GeneralSim
