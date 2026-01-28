#include "Executor.hpp"
namespace GeneralSim {
using XReg = uint16_t;
void EXEC_ADD(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_SUB(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_SLL(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_SLT(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_SLTU(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_XOR(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_SRL(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_SRA(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_OR(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_AND(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_MUL(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_DIV(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_REM(ExecContext& Ctx, XReg rd, XReg rs1, XReg rs2)
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


void EXEC_ADDI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_SLTI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_SLTIU(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_XORI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_ORI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_ANDI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_SLLI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_SRLI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_SRAI(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_LB(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_LH(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_LW(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_LBU(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_LHU(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_SB(ExecContext& Ctx, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_SH(ExecContext& Ctx, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_SW(ExecContext& Ctx, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_JAL(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
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


void EXEC_JALR(ExecContext& Ctx, XReg rd, XReg rs1, GeneralSim::Immediate imm)
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


void EXEC_LUI(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
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


void EXEC_AUIPC(ExecContext& Ctx, XReg rd, GeneralSim::Immediate imm)
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


void EXEC_BEQ(ExecContext& Ctx, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
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


void EXEC_ECALL(ExecContext& Ctx)
// Instruction ECALL
{
  uint64_t v__tmp75 = 0;
  Ctx.syscall(v__tmp75);
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
    } else if constexpr (std::is_same_v<T, MUL>) {
      EXEC_MUL(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, DIV>) {
      EXEC_DIV(Ctx, I.rd, I.rs1, I.rs2);
    } else if constexpr (std::is_same_v<T, REM>) {
      EXEC_REM(Ctx, I.rd, I.rs1, I.rs2);
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
    } else if constexpr (std::is_same_v<T, ECALL>) {
      EXEC_ECALL(Ctx);
    }
    }, Inst);
}
} // namespace GeneralSim
