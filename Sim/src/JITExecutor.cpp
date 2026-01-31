#include "JIT.hpp"
namespace SimJIT {
using XReg = uint16_t;
void EXEC_ADD(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction ADD
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp0 = CC.newUInt32();
  CC.+(v_rs1, v_rs2);
  CC.mov(v__tmp0, v_rs1);
  CC.mov(v_rd, v__tmp0);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SUB(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SUB
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp1 = CC.newUInt32();
  CC.-(v_rs1, v_rs2);
  CC.mov(v__tmp1, v_rs1);
  CC.mov(v_rd, v__tmp1);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SLL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SLL
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__c2 = CC.newUInt32();
  asmjit::x86::Gp v__tmp3 = CC.newUInt32();
  CC.&(v_rs2, v__c2);
  CC.mov(v__tmp3, v_rs2);
  asmjit::x86::Gp v__tmp4 = CC.newUInt32();
  CC.<<(v_rs1, v__tmp3);
  CC.mov(v__tmp4, v_rs1);
  CC.mov(v_rd, v__tmp4);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SLT(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SLT
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp5 = CC.newUInt32();
  CC.cmp_lt(v_rs1, v_rs2);
  CC.mov(v__tmp5, v_rs1);
  CC.mov(v_rd, v__tmp5);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SLTU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SLTU
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp6 = CC.newUInt32();
  CC.cmp_ltu(v_rs1, v_rs2);
  CC.mov(v__tmp6, v_rs1);
  CC.mov(v_rd, v__tmp6);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_XOR(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction XOR
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp7 = CC.newUInt32();
  CC.^(v_rs1, v_rs2);
  CC.mov(v__tmp7, v_rs1);
  CC.mov(v_rd, v__tmp7);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SRL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SRL
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp8 = CC.newUInt32();
  // as_unsigned not implemented in JIT, skip
  asmjit::x86::Gp v__c9 = CC.newUInt32();
  asmjit::x86::Gp v__tmp10 = CC.newUInt32();
  CC.&(v_rs2, v__c9);
  CC.mov(v__tmp10, v_rs2);
  asmjit::x86::Gp v__tmp11 = CC.newUInt32();
  CC.>>(v__tmp8, v__tmp10);
  CC.mov(v__tmp11, v__tmp8);
  CC.mov(v_rd, v__tmp11);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SRA(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SRA
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp12 = CC.newUInt32();
  // as_signed not implemented in JIT, skip
  asmjit::x86::Gp v__c13 = CC.newUInt32();
  asmjit::x86::Gp v__tmp14 = CC.newUInt32();
  CC.&(v_rs2, v__c13);
  CC.mov(v__tmp14, v_rs2);
  asmjit::x86::Gp v__tmp15 = CC.newUInt32();
  CC.>>(v__tmp12, v__tmp14);
  CC.mov(v__tmp15, v__tmp12);
  CC.mov(v_rd, v__tmp15);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_OR(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction OR
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp16 = CC.newUInt32();
  CC.|(v_rs1, v_rs2);
  CC.mov(v__tmp16, v_rs1);
  CC.mov(v_rd, v__tmp16);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_AND(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction AND
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp17 = CC.newUInt32();
  CC.&(v_rs1, v_rs2);
  CC.mov(v__tmp17, v_rs1);
  CC.mov(v_rd, v__tmp17);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_ADDI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction ADDI
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp18 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp19 = CC.newUInt32();
  CC.+(v_rs1, v__tmp18);
  CC.mov(v__tmp19, v_rs1);
  CC.mov(v_rd, v__tmp19);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SLTI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction SLTI
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp20 = CC.newUInt32();
  CC.cmp_lt(v_rs1, v_imm);
  CC.mov(v__tmp20, v_rs1);
  CC.mov(v_rd, v__tmp20);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SLTIU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction SLTIU
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp21 = CC.newUInt32();
  // as_unsigned not implemented in JIT, skip
  asmjit::x86::Gp v__tmp22 = CC.newUInt32();
  // as_unsigned not implemented in JIT, skip
  asmjit::x86::Gp v__tmp23 = CC.newUInt32();
  CC.cmp_lt(v__tmp21, v__tmp22);
  CC.mov(v__tmp23, v__tmp21);
  CC.mov(v_rd, v__tmp23);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_XORI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction XORI
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp24 = CC.newUInt32();
  CC.^(v_rs1, v_imm);
  CC.mov(v__tmp24, v_rs1);
  CC.mov(v_rd, v__tmp24);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_ORI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction ORI
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp25 = CC.newUInt32();
  CC.|(v_rs1, v_imm);
  CC.mov(v__tmp25, v_rs1);
  CC.mov(v_rd, v__tmp25);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_ANDI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction ANDI
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp26 = CC.newUInt32();
  CC.&(v_rs1, v_imm);
  CC.mov(v__tmp26, v_rs1);
  CC.mov(v_rd, v__tmp26);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SLLI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction SLLI
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp27 = CC.newUInt32();
  CC.<<(v_rs1, v_imm);
  CC.mov(v__tmp27, v_rs1);
  CC.mov(v_rd, v__tmp27);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SRLI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction SRLI
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp28 = CC.newUInt32();
  // as_unsigned not implemented in JIT, skip
  asmjit::x86::Gp v__tmp29 = CC.newUInt32();
  CC.>>(v__tmp28, v_imm);
  CC.mov(v__tmp29, v__tmp28);
  CC.mov(v_rd, v__tmp29);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SRAI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction SRAI
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp30 = CC.newUInt32();
  // as_signed not implemented in JIT, skip
  asmjit::x86::Gp v__tmp31 = CC.newUInt32();
  CC.>>(v__tmp30, v_imm);
  CC.mov(v__tmp31, v__tmp30);
  CC.mov(v_rd, v__tmp31);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_LB(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction LB
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp32 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp33 = CC.newUInt32();
  CC.+(v_rs1, v__tmp32);
  CC.mov(v__tmp33, v_rs1);
  asmjit::x86::Gp v__tmp34 = CC.newUInt32();
  v__tmp34 = CC.call(asmjit::imm(&GeneralSim::read8), v__tmp33);
  asmjit::x86::Gp v__tmp35 = CC.newUInt32();
  // sext not implemented in JIT, skip
  CC.mov(v_rd, v__tmp35);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_LH(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction LH
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp36 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp37 = CC.newUInt32();
  CC.+(v_rs1, v__tmp36);
  CC.mov(v__tmp37, v_rs1);
  asmjit::x86::Gp v__tmp38 = CC.newUInt32();
  v__tmp38 = CC.call(asmjit::imm(&GeneralSim::read16), v__tmp37);
  asmjit::x86::Gp v__tmp39 = CC.newUInt32();
  // sext not implemented in JIT, skip
  CC.mov(v_rd, v__tmp39);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_LW(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction LW
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp40 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp41 = CC.newUInt32();
  CC.+(v_rs1, v__tmp40);
  CC.mov(v__tmp41, v_rs1);
  asmjit::x86::Gp v__tmp42 = CC.newUInt32();
  v__tmp42 = CC.call(asmjit::imm(&GeneralSim::read32), v__tmp41);
  CC.mov(v_rd, v__tmp42);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_LBU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction LBU
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp43 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp44 = CC.newUInt32();
  CC.+(v_rs1, v__tmp43);
  CC.mov(v__tmp44, v_rs1);
  asmjit::x86::Gp v__tmp45 = CC.newUInt32();
  v__tmp45 = CC.call(asmjit::imm(&GeneralSim::read8), v__tmp44);
  asmjit::x86::Gp v__tmp46 = CC.newUInt32();
  // zext not implemented in JIT, skip
  CC.mov(v_rd, v__tmp46);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_LHU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction LHU
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp47 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp48 = CC.newUInt32();
  CC.+(v_rs1, v__tmp47);
  CC.mov(v__tmp48, v_rs1);
  asmjit::x86::Gp v__tmp49 = CC.newUInt32();
  v__tmp49 = CC.call(asmjit::imm(&GeneralSim::read16), v__tmp48);
  asmjit::x86::Gp v__tmp50 = CC.newUInt32();
  // zext not implemented in JIT, skip
  CC.mov(v_rd, v__tmp50);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_SB(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction SB
{
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp51 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp52 = CC.newUInt32();
  CC.+(v_rs1, v__tmp51);
  CC.mov(v__tmp52, v_rs1);
  asmjit::x86::Gp v__tmp53 = CC.newUInt32();
  // zext not implemented in JIT, skip
  CC.call(asmjit::imm(&GeneralSim::write32), v__tmp52, v__tmp53);
}


void EXEC_SH(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction SH
{
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp54 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp55 = CC.newUInt32();
  CC.+(v_rs1, v__tmp54);
  CC.mov(v__tmp55, v_rs1);
  asmjit::x86::Gp v__tmp56 = CC.newUInt32();
  // zext not implemented in JIT, skip
  CC.call(asmjit::imm(&GeneralSim::write32), v__tmp55, v__tmp56);
}


void EXEC_SW(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs2, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction SW
{
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp57 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp58 = CC.newUInt32();
  CC.+(v_rs1, v__tmp57);
  CC.mov(v__tmp58, v_rs1);
  CC.call(asmjit::imm(&GeneralSim::write32), v__tmp58, v_rs2);
}


void EXEC_JAL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, GeneralSim::Immediate imm)
// JIT Instruction JAL
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp59 = CC.newUInt32();
  v__tmp59 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__c60 = CC.newUInt32();
  asmjit::x86::Gp v__tmp61 = CC.newUInt32();
  CC.+(v__tmp59, v__c60);
  CC.mov(v__tmp61, v__tmp59);
  CC.mov(v_rd, v__tmp61);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
  asmjit::x86::Gp v__tmp62 = CC.newUInt32();
  v__tmp62 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__tmp63 = CC.newUInt32();
  CC.+(v__tmp62, v_imm);
  CC.mov(v__tmp63, v__tmp62);
  CC.call(asmjit::imm(&GeneralSim::setPCWrapper), v__tmp63);
}


void EXEC_JALR(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate imm)
// JIT Instruction JALR
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp64 = CC.newUInt32();
  v__tmp64 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__c65 = CC.newUInt32();
  asmjit::x86::Gp v__tmp66 = CC.newUInt32();
  CC.+(v__tmp64, v__c65);
  CC.mov(v__tmp66, v__tmp64);
  CC.mov(v_rd, v__tmp66);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
  asmjit::x86::Gp v__tmp67 = CC.newUInt32();
  CC.+(v_rs1, v_imm);
  CC.mov(v__tmp67, v_rs1);
  asmjit::x86::Gp v__c68 = CC.newUInt32();
  asmjit::x86::Gp v__tmp69 = CC.newUInt32();
  CC.&(v__tmp67, v__c68);
  CC.mov(v__tmp69, v__tmp67);
  CC.call(asmjit::imm(&GeneralSim::setPCWrapper), v__tmp69);
}


void EXEC_LUI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, GeneralSim::Immediate imm)
// JIT Instruction LUI
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__c70 = CC.newUInt32();
  asmjit::x86::Gp v__tmp71 = CC.newUInt32();
  CC.<<(v_imm, v__c70);
  CC.mov(v__tmp71, v_imm);
  CC.mov(v_rd, v__tmp71);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_AUIPC(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, GeneralSim::Immediate imm)
// JIT Instruction AUIPC
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp72 = CC.newUInt32();
  v__tmp72 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__c73 = CC.newUInt32();
  asmjit::x86::Gp v__tmp74 = CC.newUInt32();
  CC.<<(v_imm, v__c73);
  CC.mov(v__tmp74, v_imm);
  asmjit::x86::Gp v__tmp75 = CC.newUInt32();
  CC.+(v__tmp72, v__tmp74);
  CC.mov(v__tmp75, v__tmp72);
  CC.mov(v_rd, v__tmp75);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_BEQ(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// JIT Instruction BEQ
{
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp76 = CC.newUInt32();
  v__tmp76 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__tmp77 = CC.newUInt32();
  CC.cmp_eq(v_rs1, v_rs2);
  CC.mov(v__tmp77, v_rs1);
  asmjit::x86::Gp v__tmp78 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp79 = CC.newUInt32();
  CC.*(v__tmp77, v__tmp78);
  CC.mov(v__tmp79, v__tmp77);
  asmjit::x86::Gp v__tmp80 = CC.newUInt32();
  CC.+(v__tmp76, v__tmp79);
  CC.mov(v__tmp80, v__tmp76);
  CC.call(asmjit::imm(&GeneralSim::setPCWrapper), v__tmp80);
}


void EXEC_BNE(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// JIT Instruction BNE
{
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp81 = CC.newUInt32();
  v__tmp81 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__tmp82 = CC.newUInt32();
  CC.cmp_ne(v_rs1, v_rs2);
  CC.mov(v__tmp82, v_rs1);
  asmjit::x86::Gp v__tmp83 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp84 = CC.newUInt32();
  CC.*(v__tmp82, v__tmp83);
  CC.mov(v__tmp84, v__tmp82);
  asmjit::x86::Gp v__tmp85 = CC.newUInt32();
  CC.+(v__tmp81, v__tmp84);
  CC.mov(v__tmp85, v__tmp81);
  CC.call(asmjit::imm(&GeneralSim::setPCWrapper), v__tmp85);
}


void EXEC_BLT(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// JIT Instruction BLT
{
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp86 = CC.newUInt32();
  v__tmp86 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__tmp87 = CC.newUInt32();
  CC.cmp_lt(v_rs1, v_rs2);
  CC.mov(v__tmp87, v_rs1);
  asmjit::x86::Gp v__tmp88 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp89 = CC.newUInt32();
  CC.*(v__tmp87, v__tmp88);
  CC.mov(v__tmp89, v__tmp87);
  asmjit::x86::Gp v__tmp90 = CC.newUInt32();
  CC.+(v__tmp86, v__tmp89);
  CC.mov(v__tmp90, v__tmp86);
  CC.call(asmjit::imm(&GeneralSim::setPCWrapper), v__tmp90);
}


void EXEC_BGE(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// JIT Instruction BGE
{
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp91 = CC.newUInt32();
  v__tmp91 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__tmp92 = CC.newUInt32();
  CC.cmp_ge(v_rs1, v_rs2);
  CC.mov(v__tmp92, v_rs1);
  asmjit::x86::Gp v__tmp93 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp94 = CC.newUInt32();
  CC.*(v__tmp92, v__tmp93);
  CC.mov(v__tmp94, v__tmp92);
  asmjit::x86::Gp v__tmp95 = CC.newUInt32();
  CC.+(v__tmp91, v__tmp94);
  CC.mov(v__tmp95, v__tmp91);
  CC.call(asmjit::imm(&GeneralSim::setPCWrapper), v__tmp95);
}


void EXEC_BGEU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// JIT Instruction BGEU
{
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp96 = CC.newUInt32();
  v__tmp96 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__tmp97 = CC.newUInt32();
  CC.cmp_geu(v_rs1, v_rs2);
  CC.mov(v__tmp97, v_rs1);
  asmjit::x86::Gp v__tmp98 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp99 = CC.newUInt32();
  CC.*(v__tmp97, v__tmp98);
  CC.mov(v__tmp99, v__tmp97);
  asmjit::x86::Gp v__tmp100 = CC.newUInt32();
  CC.+(v__tmp96, v__tmp99);
  CC.mov(v__tmp100, v__tmp96);
  CC.call(asmjit::imm(&GeneralSim::setPCWrapper), v__tmp100);
}


void EXEC_BLTU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate imm)
// JIT Instruction BLTU
{
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v_imm = CC.newUInt32();
  v_imm = imm.raw();
  asmjit::x86::Gp v__tmp101 = CC.newUInt32();
  v__tmp101 = CC.call(asmjit::imm(&GeneralSim::getPCWrapper));
  asmjit::x86::Gp v__tmp102 = CC.newUInt32();
  CC.cmp_ltu(v_rs1, v_rs2);
  CC.mov(v__tmp102, v_rs1);
  asmjit::x86::Gp v__tmp103 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp104 = CC.newUInt32();
  CC.*(v__tmp102, v__tmp103);
  CC.mov(v__tmp104, v__tmp102);
  asmjit::x86::Gp v__tmp105 = CC.newUInt32();
  CC.+(v__tmp101, v__tmp104);
  CC.mov(v__tmp105, v__tmp101);
  CC.call(asmjit::imm(&GeneralSim::setPCWrapper), v__tmp105);
}


void EXEC_ECALL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg)
// JIT Instruction ECALL
{
  // Syscall skipped in JIT
}


void EXEC_MUL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction MUL
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp107 = CC.newUInt32();
  CC.*(v_rs1, v_rs2);
  CC.mov(v__tmp107, v_rs1);
  CC.mov(v_rd, v__tmp107);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_MULH(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction MULH
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp108 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp109 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp110 = CC.newUInt32();
  CC.*(v__tmp108, v__tmp109);
  CC.mov(v__tmp110, v__tmp108);
  asmjit::x86::Gp v__tmp111 = CC.newUInt32();
  // as_signed not implemented in JIT, skip
  asmjit::x86::Gp v__c112 = CC.newUInt32();
  asmjit::x86::Gp v__tmp113 = CC.newUInt32();
  CC.>>(v__tmp111, v__c112);
  CC.mov(v__tmp113, v__tmp111);
  CC.mov(v_rd, v__tmp113);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_MULHSU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction MULHSU
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp114 = CC.newUInt32();
  // sext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp115 = CC.newUInt32();
  // zext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp116 = CC.newUInt32();
  CC.*(v__tmp114, v__tmp115);
  CC.mov(v__tmp116, v__tmp114);
  asmjit::x86::Gp v__tmp117 = CC.newUInt32();
  // as_signed not implemented in JIT, skip
  asmjit::x86::Gp v__c118 = CC.newUInt32();
  asmjit::x86::Gp v__tmp119 = CC.newUInt32();
  CC.>>(v__tmp117, v__c118);
  CC.mov(v__tmp119, v__tmp117);
  CC.mov(v_rd, v__tmp119);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_MULHU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction MULHU
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp120 = CC.newUInt32();
  // zext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp121 = CC.newUInt32();
  // zext not implemented in JIT, skip
  asmjit::x86::Gp v__tmp122 = CC.newUInt32();
  CC.*(v__tmp120, v__tmp121);
  CC.mov(v__tmp122, v__tmp120);
  asmjit::x86::Gp v__c123 = CC.newUInt32();
  asmjit::x86::Gp v__tmp124 = CC.newUInt32();
  CC.>>(v__tmp122, v__c123);
  CC.mov(v__tmp124, v__tmp122);
  CC.mov(v_rd, v__tmp124);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_DIV(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction DIV
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp125 = CC.newUInt32();
  // as_signed not implemented in JIT, skip
  asmjit::x86::Gp v__tmp126 = CC.newUInt32();
  // as_signed not implemented in JIT, skip
  asmjit::x86::Gp v__tmp127 = CC.newUInt32();
  // Division not implemented in JIT, fallback or skip
  CC.mov(v_rd, v__tmp127);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_DIVU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction DIVU
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp128 = CC.newUInt32();
  // as_unsigned not implemented in JIT, skip
  asmjit::x86::Gp v__tmp129 = CC.newUInt32();
  // as_unsigned not implemented in JIT, skip
  asmjit::x86::Gp v__tmp130 = CC.newUInt32();
  // Division not implemented in JIT, fallback or skip
  CC.mov(v_rd, v__tmp130);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_REM(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction REM
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp131 = CC.newUInt32();
  // as_signed not implemented in JIT, skip
  asmjit::x86::Gp v__tmp132 = CC.newUInt32();
  // as_signed not implemented in JIT, skip
  asmjit::x86::Gp v__tmp133 = CC.newUInt32();
  // Modulo not implemented in JIT, fallback or skip
  CC.mov(v_rd, v__tmp133);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}


void EXEC_REMU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction REMU
{
  asmjit::x86::Gp v_rd = CC.newUInt32();
  asmjit::x86::Gp v_rs1 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs1);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs1, asmjit::x86::eax);
  asmjit::x86::Gp v_rs2 = CC.newUInt32();
  CC.mov(asmjit::x86::rcx,  CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rs2);
  CC.call(&GeneralSim::getRegWrapper);
  CC.mov(v_rs2, asmjit::x86::eax);
  asmjit::x86::Gp v__tmp134 = CC.newUInt32();
  // as_unsigned not implemented in JIT, skip
  asmjit::x86::Gp v__tmp135 = CC.newUInt32();
  // as_unsigned not implemented in JIT, skip
  asmjit::x86::Gp v__tmp136 = CC.newUInt32();
  // Modulo not implemented in JIT, fallback or skip
  CC.mov(v_rd, v__tmp136);
  CC.mov(asmjit::x86::rcx, CtxPtrReg);
  CC.mov(asmjit::x86::rdx, rd)
  CC.call(&GeneralSim::setRegWrapper)
  CC.mov(asmjit::imm(&GeneralSim::setRegWrapper), rd, v_rd);
}

void JIT::emitInstruction(const Instruction &Inst, ExecContext &Ctx) {
  std::visit([&](auto&& I) {
    using T = std::decay_t<decltype(I)>;
    if constexpr (std::is_same_v<T, ADD>) {
  EXEC_ADD(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, SUB>) {
  EXEC_SUB(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, SLL>) {
  EXEC_SLL(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, SLT>) {
  EXEC_SLT(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, SLTU>) {
  EXEC_SLTU(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, XOR>) {
  EXEC_XOR(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, SRL>) {
  EXEC_SRL(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, SRA>) {
  EXEC_SRA(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, OR>) {
  EXEC_OR(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, AND>) {
  EXEC_AND(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, ADDI>) {
  EXEC_ADDI(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, SLTI>) {
  EXEC_SLTI(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, SLTIU>) {
  EXEC_SLTIU(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, XORI>) {
  EXEC_XORI(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, ORI>) {
  EXEC_ORI(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, ANDI>) {
  EXEC_ANDI(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, SLLI>) {
  EXEC_SLLI(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, SRLI>) {
  EXEC_SRLI(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, SRAI>) {
  EXEC_SRAI(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, LB>) {
  EXEC_LB(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, LH>) {
  EXEC_LH(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, LW>) {
  EXEC_LW(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, LBU>) {
  EXEC_LBU(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, LHU>) {
  EXEC_LHU(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, SB>) {
  EXEC_SB(Ctx, CC, I.rs2, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, SH>) {
  EXEC_SH(Ctx, CC, I.rs2, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, SW>) {
  EXEC_SW(Ctx, CC, I.rs2, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, JAL>) {
  EXEC_JAL(Ctx, CC, I.rd, I.imm);
}
 else if constexpr (std::is_same_v<T, JALR>) {
  EXEC_JALR(Ctx, CC, I.rd, I.rs1, I.imm);
}
 else if constexpr (std::is_same_v<T, LUI>) {
  EXEC_LUI(Ctx, CC, I.rd, I.imm);
}
 else if constexpr (std::is_same_v<T, AUIPC>) {
  EXEC_AUIPC(Ctx, CC, I.rd, I.imm);
}
 else if constexpr (std::is_same_v<T, BEQ>) {
  EXEC_BEQ(Ctx, CC, I.rs1, I.rs2, I.imm);
}
 else if constexpr (std::is_same_v<T, BNE>) {
  EXEC_BNE(Ctx, CC, I.rs1, I.rs2, I.imm);
}
 else if constexpr (std::is_same_v<T, BLT>) {
  EXEC_BLT(Ctx, CC, I.rs1, I.rs2, I.imm);
}
 else if constexpr (std::is_same_v<T, BGE>) {
  EXEC_BGE(Ctx, CC, I.rs1, I.rs2, I.imm);
}
 else if constexpr (std::is_same_v<T, BGEU>) {
  EXEC_BGEU(Ctx, CC, I.rs1, I.rs2, I.imm);
}
 else if constexpr (std::is_same_v<T, BLTU>) {
  EXEC_BLTU(Ctx, CC, I.rs1, I.rs2, I.imm);
}
 else if constexpr (std::is_same_v<T, ECALL>) {
  EXEC_ECALL(Ctx, CC);
}
 else if constexpr (std::is_same_v<T, MUL>) {
  EXEC_MUL(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, MULH>) {
  EXEC_MULH(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, MULHSU>) {
  EXEC_MULHSU(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, MULHU>) {
  EXEC_MULHU(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, DIV>) {
  EXEC_DIV(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, DIVU>) {
  EXEC_DIVU(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, REM>) {
  EXEC_REM(Ctx, CC, I.rd, I.rs1, I.rs2);
}
 else if constexpr (std::is_same_v<T, REMU>) {
  EXEC_REMU(Ctx, CC, I.rd, I.rs1, I.rs2);
}

    }, Inst);
}
} // namespace GeneralSim
