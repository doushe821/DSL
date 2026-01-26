#include "GeneralSim.hpp"
namespace ExecTable {
using XReg = uint16_t;
void EXEC_ADD(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction ADD
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp0 = 0;
  v__tmp0 = v_rs1 + v_rs2;
  v_rd = v__tmp0;
  CPU.setReg(rd, v_rd);
}

void EXEC_SUB(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction SUB
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp1 = 0;
  v__tmp1 = v_rs1 - v_rs2;
  v_rd = v__tmp1;
  CPU.setReg(rd, v_rd);
}

void EXEC_SLL(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction SLL
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__c2 = 0;
  v__c2 = 31;
  uint64_t v__tmp3 = 0;
  v__tmp3 = v_rs2 & v__c2;
  uint64_t v__tmp4 = 0;
  v__tmp4 = v_rs1 << v__tmp3;
  v_rd = v__tmp4;
  CPU.setReg(rd, v_rd);
}

void EXEC_SLT(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction SLT
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp5 = 0;
  v__tmp5 = (static_cast<int32_t>(v_rs1) < static_cast<int32_t>(v_rs2));
  v_rd = v__tmp5;
  CPU.setReg(rd, v_rd);
}

void EXEC_SLTU(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction SLTU
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp6 = 0;
  v__tmp6 = (v_rs1 < v_rs2);
  v_rd = v__tmp6;
  CPU.setReg(rd, v_rd);
}

void EXEC_XOR(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction XOR
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp7 = 0;
  v__tmp7 = v_rs1 ^ v_rs2;
  v_rd = v__tmp7;
  CPU.setReg(rd, v_rd);
}

void EXEC_SRL(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction SRL
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp8 = 0;
  v__tmp8 = static_cast<uint64_t>(v_rs1);
  uint64_t v__c9 = 0;
  v__c9 = 31;
  uint64_t v__tmp10 = 0;
  v__tmp10 = v_rs2 & v__c9;
  uint64_t v__tmp11 = 0;
  v__tmp11 = v__tmp8 >> v__tmp10;
  v_rd = v__tmp11;
  CPU.setReg(rd, v_rd);
}

void EXEC_SRA(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction SRA
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp12 = 0;
  v__tmp12 = static_cast<int64_t>(v_rs1);
  uint64_t v__c13 = 0;
  v__c13 = 31;
  uint64_t v__tmp14 = 0;
  v__tmp14 = v_rs2 & v__c13;
  uint64_t v__tmp15 = 0;
  v__tmp15 = v__tmp12 >> v__tmp14;
  v_rd = v__tmp15;
  CPU.setReg(rd, v_rd);
}

void EXEC_OR(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction OR
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp16 = 0;
  v__tmp16 = v_rs1 | v_rs2;
  v_rd = v__tmp16;
  CPU.setReg(rd, v_rd);
}

void EXEC_AND(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction AND
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp17 = 0;
  v__tmp17 = v_rs1 & v_rs2;
  v_rd = v__tmp17;
  CPU.setReg(rd, v_rd);
}

void EXEC_MUL(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction MUL
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp18 = 0;
  v__tmp18 = v_rs1 * v_rs2;
  v_rd = v__tmp18;
  CPU.setReg(rd, v_rd);
}

void EXEC_DIV(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction DIV
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp19 = 0;
  v__tmp19 = v_rs1 / v_rs2;
  v_rd = v__tmp19;
  CPU.setReg(rd, v_rd);
}

void EXEC_REM(GeneralSim::CPU &CPU, XReg rd, XReg rs1, XReg rs2)
// Instruction REM
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v__tmp20 = 0;
  v__tmp20 = v_rs1 % v_rs2;
  v_rd = v__tmp20;
  CPU.setReg(rd, v_rd);
}

void EXEC_ADDI(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction ADDI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp21 = 0;
  v__tmp21 = v_rs1 + v_imm;
  v_rd = v__tmp21;
  CPU.setReg(rd, v_rd);
}

void EXEC_SLTI(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SLTI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp22 = 0;
  v__tmp22 = (static_cast<int32_t>(v_rs1) < static_cast<int32_t>(v_imm));
  v_rd = v__tmp22;
  CPU.setReg(rd, v_rd);
}

void EXEC_SLTIU(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SLTIU
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp23 = 0;
  v__tmp23 = static_cast<uint64_t>(v_rs1);
  uint64_t v__tmp24 = 0;
  v__tmp24 = static_cast<uint64_t>(v_imm);
  uint64_t v__tmp25 = 0;
  v__tmp25 = (static_cast<int32_t>(v__tmp23) < static_cast<int32_t>(v__tmp24));
  v_rd = v__tmp25;
  CPU.setReg(rd, v_rd);
}

void EXEC_XORI(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction XORI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp26 = 0;
  v__tmp26 = v_rs1 ^ v_imm;
  v_rd = v__tmp26;
  CPU.setReg(rd, v_rd);
}

void EXEC_ORI(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction ORI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp27 = 0;
  v__tmp27 = v_rs1 | v_imm;
  v_rd = v__tmp27;
  CPU.setReg(rd, v_rd);
}

void EXEC_ANDI(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction ANDI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp28 = 0;
  v__tmp28 = v_rs1 & v_imm;
  v_rd = v__tmp28;
  CPU.setReg(rd, v_rd);
}

void EXEC_SLLI(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SLLI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp29 = 0;
  v__tmp29 = v_rs1 << v_imm;
  v_rd = v__tmp29;
  CPU.setReg(rd, v_rd);
}

void EXEC_SRLI(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SRLI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp30 = 0;
  v__tmp30 = static_cast<uint64_t>(v_rs1);
  uint64_t v__tmp31 = 0;
  v__tmp31 = v__tmp30 >> v_imm;
  v_rd = v__tmp31;
  CPU.setReg(rd, v_rd);
}

void EXEC_SRAI(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction SRAI
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp32 = 0;
  v__tmp32 = static_cast<int64_t>(v_rs1);
  uint64_t v__tmp33 = 0;
  v__tmp33 = v__tmp32 >> v_imm;
  v_rd = v__tmp33;
  CPU.setReg(rd, v_rd);
}

void EXEC_LB(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LB
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp34 = 0;
  v__tmp34 = v_rs1 + v_imm;
  uint64_t v__tmp35 = 0;
  v__tmp35 = CPU.load(v__tmp34, 8);
  uint64_t v__tmp36 = 0;
  v__tmp36 = CPU.sext(v__tmp35, 8);
  v_rd = v__tmp36;
  CPU.setReg(rd, v_rd);
}

void EXEC_LH(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LH
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp37 = 0;
  v__tmp37 = v_rs1 + v_imm;
  uint64_t v__tmp38 = 0;
  v__tmp38 = CPU.load(v__tmp37, 16);
  uint64_t v__tmp39 = 0;
  v__tmp39 = CPU.sext(v__tmp38, 16);
  v_rd = v__tmp39;
  CPU.setReg(rd, v_rd);
}

void EXEC_LW(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LW
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp40 = 0;
  v__tmp40 = v_rs1 + v_imm;
  uint64_t v__tmp41 = 0;
  v__tmp41 = CPU.load(v__tmp40, 32);
  v_rd = v__tmp41;
  CPU.setReg(rd, v_rd);
}

void EXEC_LBU(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LBU
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp42 = 0;
  v__tmp42 = v_rs1 + v_imm;
  uint64_t v__tmp43 = 0;
  v__tmp43 = CPU.load(v__tmp42, 8);
  uint64_t v__tmp44 = 0;
  v__tmp44 = CPU.zext(v__tmp43, 8);
  v_rd = v__tmp44;
  CPU.setReg(rd, v_rd);
}

void EXEC_LHU(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction LHU
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp45 = 0;
  v__tmp45 = v_rs1 + v_imm;
  uint64_t v__tmp46 = 0;
  v__tmp46 = CPU.load(v__tmp45, 16);
  uint64_t v__tmp47 = 0;
  v__tmp47 = CPU.zext(v__tmp46, 16);
  v_rd = v__tmp47;
  CPU.setReg(rd, v_rd);
}

void EXEC_SB(GeneralSim::CPU &CPU, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// Instruction SB
{
  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp48 = 0;
  v__tmp48 = v_rs1 + v_imm;
  uint64_t v__tmp49 = 0;
  v__tmp49 = CPU.zext(v_rs2, 8);
  CPU.store(v__tmp48, v__tmp49, 8);
}

void EXEC_SH(GeneralSim::CPU &CPU, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// Instruction SH
{
  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp50 = 0;
  v__tmp50 = v_rs1 + v_imm;
  uint64_t v__tmp51 = 0;
  v__tmp51 = CPU.zext(v_rs2, 16);
  CPU.store(v__tmp50, v__tmp51, 16);
}

void EXEC_SW(GeneralSim::CPU &CPU, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// Instruction SW
{
  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp52 = 0;
  v__tmp52 = v_rs1 + v_imm;
  uint64_t v__tmp53 = 0;
  v__tmp53 = CPU.zext(v_rs2, 32);
  CPU.store(v__tmp52, v__tmp53, 32);
}

void EXEC_JAL(GeneralSim::CPU &CPU, XReg rd, GeneralSim::Immediate imm)
// Instruction JAL
{
  uint64_t v_rd = 0;
  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp54 = 0;
  v__tmp54 = CPU.getPC();
  uint64_t v__c55 = 0;
  v__c55 = 4;
  uint64_t v__tmp56 = 0;
  v__tmp56 = v__tmp54 + v__c55;
  v_rd = v__tmp56;
  CPU.setReg(rd, v_rd);
  uint64_t v__tmp57 = 0;
  v__tmp57 = CPU.getPC();
  uint64_t v__tmp58 = 0;
  v__tmp58 = v__tmp57 + v_imm;
  CPU.setPC(v__tmp58);
}

void EXEC_JALR(GeneralSim::CPU &CPU, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// Instruction JALR
{
  uint64_t v_rd = 0;
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp59 = 0;
  v__tmp59 = CPU.getPC();
  uint64_t v__c60 = 0;
  v__c60 = 4;
  uint64_t v__tmp61 = 0;
  v__tmp61 = v__tmp59 + v__c60;
  v_rd = v__tmp61;
  CPU.setReg(rd, v_rd);
  uint64_t v__tmp62 = 0;
  v__tmp62 = v_rs1 + v_imm;
  uint64_t v__c63 = 0;
  v__c63 = -2;
  uint64_t v__tmp64 = 0;
  v__tmp64 = v__tmp62 & v__c63;
  CPU.setPC(v__tmp64);
}

void EXEC_LUI(GeneralSim::CPU &CPU, XReg rd, GeneralSim::Immediate imm)
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
  CPU.setReg(rd, v_rd);
}

void EXEC_AUIPC(GeneralSim::CPU &CPU, XReg rd, GeneralSim::Immediate imm)
// Instruction AUIPC
{
  uint64_t v_rd = 0;
  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp67 = 0;
  v__tmp67 = CPU.getPC();
  uint64_t v__c68 = 0;
  v__c68 = 12;
  uint64_t v__tmp69 = 0;
  v__tmp69 = v_imm << v__c68;
  uint64_t v__tmp70 = 0;
  v__tmp70 = v__tmp67 + v__tmp69;
  v_rd = v__tmp70;
  CPU.setReg(rd, v_rd);
}

void EXEC_BEQ(GeneralSim::CPU &CPU, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// Instruction BEQ
{
  uint64_t v_rs1 = 0;
  v_rs1 = CPU.getReg(rs1);

  uint64_t v_rs2 = 0;
  v_rs2 = CPU.getReg(rs2);

  uint64_t v_imm = 0;
  v_imm = imm.raw();

  uint64_t v__tmp71 = 0;
  v__tmp71 = CPU.getPC();
  uint64_t v__tmp72 = 0;
  v__tmp72 = (v_rs1 == v_rs2);
  uint64_t v__tmp73 = 0;
  v__tmp73 = v__tmp72 * v_imm;
  uint64_t v__tmp74 = 0;
  v__tmp74 = v__tmp71 + v__tmp73;
  CPU.setPC(v__tmp74);
}

void EXEC_ECALL(GeneralSim::CPU &CPU)
// Instruction ECALL
{
  uint64_t v__tmp75 = 0;
  CPU.syscall(v__tmp75);
}

} // namespace ExecTable
")
