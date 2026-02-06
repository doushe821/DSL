#include "JIT.hpp"
#include "RegState.hpp"
#include "Helpers.hpp"
namespace SimJIT {
using namespace asmjit;
using namespace asmjit::x86;
using XReg = uint16_t;
void EXEC_ADD(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction ADD
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp0 = CC.newUInt32();
  // add
  CC.add(v_rs1, v_rs2);
  CC.mov(v__tmp0, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp0);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SUB(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SUB
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp1 = CC.newUInt32();
  // sub
  CC.sub(v_rs1, v_rs2);
  CC.mov(v__tmp1, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp1);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SLL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SLL
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__c2 = CC.newUInt32();
  CC.mov(v__c2, 31);
  Gp v__tmp3 = CC.newUInt32();
  // and_
  CC.and_(v_rs2, v__c2);
  CC.mov(v__tmp3, v_rs2);
  Gp v__tmp4 = CC.newUInt32();
  // Left shift
  CC.shl(v_rs1, v__tmp3);
  CC.mov(v__tmp4, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp4);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SLT(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SLT
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp5 = CC.newUInt32();
  // Cmp lt
  CC.cmp(v_rs1, v_rs2);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.setl(cond);
  CC.movzx(v__tmp5, cond);
  // Let
  CC.mov(v_rd, v__tmp5);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SLTU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SLTU
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp6 = CC.newUInt32();
  // Cmp ltu
  CC.cmp(v_rs1, v_rs2);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.setb(cond);
  CC.movzx(v__tmp6, cond);
  // Let
  CC.mov(v_rd, v__tmp6);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_XOR(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction XOR
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp7 = CC.newUInt32();
  // xor_
  CC.xor_(v_rs1, v_rs2);
  CC.mov(v__tmp7, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp7);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SRL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SRL
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  // Type clarification
  Gp v__tmp8 = CC.newUInt32();
  CC.mov(v__tmp8, v_rs1);
  Gp v__c9 = CC.newUInt32();
  CC.mov(v__c9, 31);
  Gp v__tmp10 = CC.newUInt32();
  // and_
  CC.and_(v_rs2, v__c9);
  CC.mov(v__tmp10, v_rs2);
  Gp v__tmp11 = CC.newUInt32();
  // Right shift
  // Signed
  CC.sar(v__tmp8, v__tmp10);
  CC.mov(v__tmp11, v__tmp8);
  // Let
  CC.mov(v_rd, v__tmp11);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SRA(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction SRA
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  // Type clarification
  Gp v__tmp12 = CC.newUInt32();
  CC.mov(v__tmp12, v_rs1);
  Gp v__c13 = CC.newUInt32();
  CC.mov(v__c13, 31);
  Gp v__tmp14 = CC.newUInt32();
  // and_
  CC.and_(v_rs2, v__c13);
  CC.mov(v__tmp14, v_rs2);
  Gp v__tmp15 = CC.newUInt32();
  // Right shift
  // Signed
  CC.sar(v__tmp12, v__tmp14);
  CC.mov(v__tmp15, v__tmp12);
  // Let
  CC.mov(v_rd, v__tmp15);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_OR(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction OR
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp16 = CC.newUInt32();
  // or_
  CC.or_(v_rs1, v_rs2);
  CC.mov(v__tmp16, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp16);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_AND(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction AND
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp17 = CC.newUInt32();
  // and_
  CC.and_(v_rs1, v_rs2);
  CC.mov(v__tmp17, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp17);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_ADDI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction ADDI
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp18 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 12);
    Node->setRet(0, v__tmp18);
  }

  Gp v__tmp19 = CC.newUInt32();
  // add
  CC.add(v_rs1, v__tmp18);
  CC.mov(v__tmp19, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp19);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SLTI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction SLTI
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp20 = CC.newUInt32();
  // Cmp lt
  CC.cmp(v_rs1, v_imm);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.setl(cond);
  CC.movzx(v__tmp20, cond);
  // Let
  CC.mov(v_rd, v__tmp20);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SLTIU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction SLTIU
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  // Type clarification
  Gp v__tmp21 = CC.newUInt32();
  CC.mov(v__tmp21, v_rs1);
  // Type clarification
  Gp v__tmp22 = CC.newUInt32();
  CC.mov(v__tmp22, v_imm);
  Gp v__tmp23 = CC.newUInt32();
  // Cmp lt
  CC.cmp(v__tmp21, v__tmp22);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.setl(cond);
  CC.movzx(v__tmp23, cond);
  // Let
  CC.mov(v_rd, v__tmp23);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_XORI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction XORI
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp24 = CC.newUInt32();
  // xor_
  CC.xor_(v_rs1, v_imm);
  CC.mov(v__tmp24, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp24);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_ORI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction ORI
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp25 = CC.newUInt32();
  // or_
  CC.or_(v_rs1, v_imm);
  CC.mov(v__tmp25, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp25);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_ANDI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction ANDI
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp26 = CC.newUInt32();
  // and_
  CC.and_(v_rs1, v_imm);
  CC.mov(v__tmp26, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp26);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SLLI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction SLLI
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp27 = CC.newUInt32();
  // Left shift
  CC.shl(v_rs1, v_imm);
  CC.mov(v__tmp27, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp27);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SRLI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction SRLI
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  // Type clarification
  Gp v__tmp28 = CC.newUInt32();
  CC.mov(v__tmp28, v_rs1);
  Gp v__tmp29 = CC.newUInt32();
  // Right shift
  // Signed
  CC.sar(v__tmp28, v_imm);
  CC.mov(v__tmp29, v__tmp28);
  // Let
  CC.mov(v_rd, v__tmp29);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SRAI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction SRAI
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  // Type clarification
  Gp v__tmp30 = CC.newUInt32();
  CC.mov(v__tmp30, v_rs1);
  Gp v__tmp31 = CC.newUInt32();
  // Right shift
  // Signed
  CC.sar(v__tmp30, v_imm);
  CC.mov(v__tmp31, v__tmp30);
  // Let
  CC.mov(v_rd, v__tmp31);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_LB(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction LB
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp32 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 12);
    Node->setRet(0, v__tmp32);
  }

  Gp v__tmp33 = CC.newUInt32();
  // add
  CC.add(v_rs1, v__tmp32);
  CC.mov(v__tmp33, v_rs1);
  Gp v__tmp34 = CC.newUInt32();
  // Load 8
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::read8), FuncSignatureT<uint8_t, GeneralSim::ExecContext*, uintptr_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp33);
    Node->setRet(0, v__tmp34);
  }

  Gp v__tmp35 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v__tmp34);
    Node->setArg(1, 8);
    Node->setRet(0, v__tmp35);
  }

  // Let
  CC.mov(v_rd, v__tmp35);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_LH(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction LH
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp36 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 12);
    Node->setRet(0, v__tmp36);
  }

  Gp v__tmp37 = CC.newUInt32();
  // add
  CC.add(v_rs1, v__tmp36);
  CC.mov(v__tmp37, v_rs1);
  Gp v__tmp38 = CC.newUInt32();
  // Load 16
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::read16), FuncSignatureT<uint16_t, GeneralSim::ExecContext*, uintptr_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp37);
    Node->setRet(0, v__tmp38);
  }

  Gp v__tmp39 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v__tmp38);
    Node->setArg(1, 16);
    Node->setRet(0, v__tmp39);
  }

  // Let
  CC.mov(v_rd, v__tmp39);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_LW(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction LW
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp40 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 12);
    Node->setRet(0, v__tmp40);
  }

  Gp v__tmp41 = CC.newUInt32();
  // add
  CC.add(v_rs1, v__tmp40);
  CC.mov(v__tmp41, v_rs1);
  Gp v__tmp42 = CC.newUInt32();
  // Load 32
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::read32), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uintptr_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp41);
    Node->setRet(0, v__tmp42);
  }

  // Let
  CC.mov(v_rd, v__tmp42);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_LBU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction LBU
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp43 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 12);
    Node->setRet(0, v__tmp43);
  }

  Gp v__tmp44 = CC.newUInt32();
  // add
  CC.add(v_rs1, v__tmp43);
  CC.mov(v__tmp44, v_rs1);
  Gp v__tmp45 = CC.newUInt32();
  // Load 8
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::read8), FuncSignatureT<uint8_t, GeneralSim::ExecContext*, uintptr_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp44);
    Node->setRet(0, v__tmp45);
  }

  // Type clarification
  Gp v__tmp46 = CC.newUInt8();
  CC.mov(v__tmp46, v__tmp45);
  // Let
  CC.mov(v_rd, v__tmp46);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_LHU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction LHU
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp47 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 12);
    Node->setRet(0, v__tmp47);
  }

  Gp v__tmp48 = CC.newUInt32();
  // add
  CC.add(v_rs1, v__tmp47);
  CC.mov(v__tmp48, v_rs1);
  Gp v__tmp49 = CC.newUInt32();
  // Load 16
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::read16), FuncSignatureT<uint16_t, GeneralSim::ExecContext*, uintptr_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp48);
    Node->setRet(0, v__tmp49);
  }

  // Type clarification
  Gp v__tmp50 = CC.newUInt16();
  CC.mov(v__tmp50, v__tmp49);
  // Let
  CC.mov(v_rd, v__tmp50);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_SB(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs2, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction SB
{
  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp51 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 12);
    Node->setRet(0, v__tmp51);
  }

  Gp v__tmp52 = CC.newUInt32();
  // add
  CC.add(v_rs1, v__tmp51);
  CC.mov(v__tmp52, v_rs1);
  // Type clarification
  Gp v__tmp53 = CC.newUInt32();
  CC.mov(v__tmp53, v_rs2);
  // Load 32
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::write32), FuncSignatureT<void, GeneralSim::ExecContext*, uintptr_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp52);
    Node->setArg(2, v__tmp53);
  }

}


void EXEC_SH(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs2, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction SH
{
  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp54 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 12);
    Node->setRet(0, v__tmp54);
  }

  Gp v__tmp55 = CC.newUInt32();
  // add
  CC.add(v_rs1, v__tmp54);
  CC.mov(v__tmp55, v_rs1);
  // Type clarification
  Gp v__tmp56 = CC.newUInt32();
  CC.mov(v__tmp56, v_rs2);
  // Load 32
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::write32), FuncSignatureT<void, GeneralSim::ExecContext*, uintptr_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp55);
    Node->setArg(2, v__tmp56);
  }

}


void EXEC_SW(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs2, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction SW
{
  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp57 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 12);
    Node->setRet(0, v__tmp57);
  }

  Gp v__tmp58 = CC.newUInt32();
  // add
  CC.add(v_rs1, v__tmp57);
  CC.mov(v__tmp58, v_rs1);
  // Load 32
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::write32), FuncSignatureT<void, GeneralSim::ExecContext*, uintptr_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp58);
    Node->setArg(2, v_rs2);
  }

}


void EXEC_JAL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, GeneralSim::Immediate Imm)
// JIT Instruction JAL
{
  Gp v_rd = CC.newUInt32();
  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp59 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp59);
  }

  Gp v__c60 = CC.newUInt32();
  CC.mov(v__c60, 4);
  Gp v__tmp61 = CC.newUInt32();
  // add
  CC.add(v__tmp59, v__c60);
  CC.mov(v__tmp61, v__tmp59);
  // Let
  CC.mov(v_rd, v__tmp61);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  Gp v__tmp62 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp62);
  }

  Gp v__tmp63 = CC.newUInt32();
  // add
  CC.add(v__tmp62, v_imm);
  CC.mov(v__tmp63, v__tmp62);
  // Set pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setPCWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp63);
  }

}


void EXEC_JALR(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, GeneralSim::Immediate Imm)
// JIT Instruction JALR
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp64 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp64);
  }

  Gp v__c65 = CC.newUInt32();
  CC.mov(v__c65, 4);
  Gp v__tmp66 = CC.newUInt32();
  // add
  CC.add(v__tmp64, v__c65);
  CC.mov(v__tmp66, v__tmp64);
  // Let
  CC.mov(v_rd, v__tmp66);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  Gp v__tmp67 = CC.newUInt32();
  // add
  CC.add(v_rs1, v_imm);
  CC.mov(v__tmp67, v_rs1);
  Gp v__c68 = CC.newUInt32();
  CC.mov(v__c68, -2);
  Gp v__tmp69 = CC.newUInt32();
  // and_
  CC.and_(v__tmp67, v__c68);
  CC.mov(v__tmp69, v__tmp67);
  // Set pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setPCWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp69);
  }

}


void EXEC_LUI(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, GeneralSim::Immediate Imm)
// JIT Instruction LUI
{
  Gp v_rd = CC.newUInt32();
  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__c70 = CC.newUInt32();
  CC.mov(v__c70, 12);
  Gp v__tmp71 = CC.newUInt32();
  // Left shift
  CC.shl(v_imm, v__c70);
  CC.mov(v__tmp71, v_imm);
  // Let
  CC.mov(v_rd, v__tmp71);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_AUIPC(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, GeneralSim::Immediate Imm)
// JIT Instruction AUIPC
{
  Gp v_rd = CC.newUInt32();
  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp72 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp72);
  }

  Gp v__c73 = CC.newUInt32();
  CC.mov(v__c73, 12);
  Gp v__tmp74 = CC.newUInt32();
  // Left shift
  CC.shl(v_imm, v__c73);
  CC.mov(v__tmp74, v_imm);
  Gp v__tmp75 = CC.newUInt32();
  // add
  CC.add(v__tmp72, v__tmp74);
  CC.mov(v__tmp75, v__tmp72);
  // Let
  CC.mov(v_rd, v__tmp75);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_BEQ(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate Imm)
// JIT Instruction BEQ
{
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp76 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp76);
  }

  Gp v__tmp77 = CC.newUInt32();
  // Cmp eq
  CC.cmp(v_rs1, v_rs2);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.sete(cond);
  CC.movzx(v__tmp77, cond);
  Gp v__tmp78 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 13);
    Node->setRet(0, v__tmp78);
  }

  Gp v__tmp79 = CC.newUInt32();
  // imul
  CC.imul(v__tmp77, v__tmp78);
  CC.mov(v__tmp79, v__tmp77);
  Gp v__tmp80 = CC.newUInt32();
  // add
  CC.add(v__tmp76, v__tmp79);
  CC.mov(v__tmp80, v__tmp76);
  // Set pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setPCWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp80);
  }

}


void EXEC_BNE(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate Imm)
// JIT Instruction BNE
{
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp81 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp81);
  }

  Gp v__tmp82 = CC.newUInt32();
  // Cmp ne
  CC.cmp(v_rs1, v_rs2);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.setne(cond);
  CC.movzx(v__tmp82, cond);
  Gp v__tmp83 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 13);
    Node->setRet(0, v__tmp83);
  }

  Gp v__tmp84 = CC.newUInt32();
  // imul
  CC.imul(v__tmp82, v__tmp83);
  CC.mov(v__tmp84, v__tmp82);
  Gp v__tmp85 = CC.newUInt32();
  // add
  CC.add(v__tmp81, v__tmp84);
  CC.mov(v__tmp85, v__tmp81);
  // Set pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setPCWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp85);
  }

}


void EXEC_BLT(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate Imm)
// JIT Instruction BLT
{
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp86 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp86);
  }

  Gp v__tmp87 = CC.newUInt32();
  // Cmp lt
  CC.cmp(v_rs1, v_rs2);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.setl(cond);
  CC.movzx(v__tmp87, cond);
  Gp v__tmp88 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 13);
    Node->setRet(0, v__tmp88);
  }

  Gp v__tmp89 = CC.newUInt32();
  // imul
  CC.imul(v__tmp87, v__tmp88);
  CC.mov(v__tmp89, v__tmp87);
  Gp v__tmp90 = CC.newUInt32();
  // add
  CC.add(v__tmp86, v__tmp89);
  CC.mov(v__tmp90, v__tmp86);
  // Set pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setPCWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp90);
  }

}


void EXEC_BGE(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate Imm)
// JIT Instruction BGE
{
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp91 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp91);
  }

  Gp v__tmp92 = CC.newUInt32();
  // Cmp ge
  CC.cmp(v_rs1, v_rs2);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.setge(cond);
  CC.movzx(v__tmp92, cond);
  Gp v__tmp93 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 13);
    Node->setRet(0, v__tmp93);
  }

  Gp v__tmp94 = CC.newUInt32();
  // imul
  CC.imul(v__tmp92, v__tmp93);
  CC.mov(v__tmp94, v__tmp92);
  Gp v__tmp95 = CC.newUInt32();
  // add
  CC.add(v__tmp91, v__tmp94);
  CC.mov(v__tmp95, v__tmp91);
  // Set pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setPCWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp95);
  }

}


void EXEC_BGEU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate Imm)
// JIT Instruction BGEU
{
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp96 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp96);
  }

  Gp v__tmp97 = CC.newUInt32();
  // Cmp geu
  CC.cmp(v_rs1, v_rs2);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.setae(cond);
  CC.movzx(v__tmp97, cond);
  Gp v__tmp98 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 13);
    Node->setRet(0, v__tmp98);
  }

  Gp v__tmp99 = CC.newUInt32();
  // imul
  CC.imul(v__tmp97, v__tmp98);
  CC.mov(v__tmp99, v__tmp97);
  Gp v__tmp100 = CC.newUInt32();
  // add
  CC.add(v__tmp96, v__tmp99);
  CC.mov(v__tmp100, v__tmp96);
  // Set pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setPCWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp100);
  }

}


void EXEC_BLTU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rs1, XReg rs2, GeneralSim::Immediate Imm)
// JIT Instruction BLTU
{
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v_imm = CC.newUInt32();
  // Get Immediate 
  CC.mov(v_imm, Imm.raw()); 

  Gp v__tmp101 = CC.newUInt32();
  // Get pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getPCWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setRet(0, v__tmp101);
  }

  Gp v__tmp102 = CC.newUInt32();
  // Cmp ltu
  CC.cmp(v_rs1, v_rs2);
  asmjit::x86::Gp cond = CC.newUInt8();
  CC.setb(cond);
  CC.movzx(v__tmp102, cond);
  Gp v__tmp103 = CC.newUInt32();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_imm);
    Node->setArg(1, 13);
    Node->setRet(0, v__tmp103);
  }

  Gp v__tmp104 = CC.newUInt32();
  // imul
  CC.imul(v__tmp102, v__tmp103);
  CC.mov(v__tmp104, v__tmp102);
  Gp v__tmp105 = CC.newUInt32();
  // add
  CC.add(v__tmp101, v__tmp104);
  CC.mov(v__tmp105, v__tmp101);
  // Set pc
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setPCWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, v__tmp105);
  }

}


void EXEC_ECALL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg)
// JIT Instruction ECALL
{
  // Syscall
  InvokeNode* Call;
  CC.invoke(&Call, imm(&GeneralSim::syscall), FuncSignatureT<void, GeneralSim::ExecContext*>(CallConvId::kCDecl));
  Call->setArg(0, CtxPtrReg);

}


void EXEC_MUL(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction MUL
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp107 = CC.newUInt32();
  // imul
  CC.imul(v_rs1, v_rs2);
  CC.mov(v__tmp107, v_rs1);
  // Let
  CC.mov(v_rd, v__tmp107);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_MULH(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction MULH
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp108 = CC.newUInt64();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_rs1);
    Node->setArg(1, 32);
    Node->setRet(0, v__tmp108);
  }

  Gp v__tmp109 = CC.newUInt64();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_rs2);
    Node->setArg(1, 32);
    Node->setRet(0, v__tmp109);
  }

  Gp v__tmp110 = CC.newUInt64();
  // imul
  CC.imul(v__tmp108, v__tmp109);
  CC.mov(v__tmp110, v__tmp108);
  // Type clarification
  Gp v__tmp111 = CC.newUInt64();
  CC.mov(v__tmp111, v__tmp110);
  Gp v__c112 = CC.newUInt32();
  CC.mov(v__c112, 32);
  Gp v__tmp113 = CC.newUInt64();
  // Right shift
  // Signed
  CC.sar(v__tmp111, v__c112);
  CC.mov(v__tmp113, v__tmp111);
  // Let
  CC.mov(v_rd, v__tmp113);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_MULHSU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction MULHSU
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  Gp v__tmp114 = CC.newUInt64();
  // sext
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(GeneralSim::Helpers::sext), FuncSignatureT<uint64_t, uint64_t, int64_t>(CallConvId::kCDecl));
    Node->setArg(0, v_rs1);
    Node->setArg(1, 32);
    Node->setRet(0, v__tmp114);
  }

  // Type clarification
  Gp v__tmp115 = CC.newUInt32();
  CC.mov(v__tmp115, v_rs2);
  Gp v__tmp116 = CC.newUInt64();
  // imul
  CC.imul(v__tmp114, v__tmp115);
  CC.mov(v__tmp116, v__tmp114);
  // Type clarification
  Gp v__tmp117 = CC.newUInt64();
  CC.mov(v__tmp117, v__tmp116);
  Gp v__c118 = CC.newUInt32();
  CC.mov(v__c118, 32);
  Gp v__tmp119 = CC.newUInt64();
  // Right shift
  // Signed
  CC.sar(v__tmp117, v__c118);
  CC.mov(v__tmp119, v__tmp117);
  // Let
  CC.mov(v_rd, v__tmp119);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_MULHU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction MULHU
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  // Type clarification
  Gp v__tmp120 = CC.newUInt32();
  CC.mov(v__tmp120, v_rs1);
  // Type clarification
  Gp v__tmp121 = CC.newUInt32();
  CC.mov(v__tmp121, v_rs2);
  Gp v__tmp122 = CC.newUInt64();
  // mul
  CC.mul(v__tmp120, v__tmp121);
  CC.mov(v__tmp122, v__tmp120);
  Gp v__c123 = CC.newUInt32();
  CC.mov(v__c123, 32);
  Gp v__tmp124 = CC.newUInt64();
  // Right shift
  // Signed
  CC.sar(v__tmp122, v__c123);
  CC.mov(v__tmp124, v__tmp122);
  // Let
  CC.mov(v_rd, v__tmp124);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_DIV(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction DIV
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  // Type clarification
  Gp v__tmp125 = CC.newUInt32();
  CC.mov(v__tmp125, v_rs1);
  // Type clarification
  Gp v__tmp126 = CC.newUInt32();
  CC.mov(v__tmp126, v_rs2);
  Gp v__tmp127 = CC.newUInt32();
  // Div prelude
  CC.mov(eax, v__tmp125);
  CC.emit(x86::Inst::kIdCdq);
  // idiv
  CC.emit(x86::Inst::kIdIdiv, v__tmp126);
  CC.mov(v__tmp127, eax);
  // Let
  CC.mov(v_rd, v__tmp127);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_DIVU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction DIVU
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  // Type clarification
  Gp v__tmp128 = CC.newUInt32();
  CC.mov(v__tmp128, v_rs1);
  // Type clarification
  Gp v__tmp129 = CC.newUInt32();
  CC.mov(v__tmp129, v_rs2);
  Gp v__tmp130 = CC.newUInt32();
  // Div prelude
  CC.mov(eax, v__tmp128);
  CC.emit(x86::Inst::kIdCdq);
  // idiv
  CC.emit(x86::Inst::kIdIdiv, v__tmp129);
  CC.mov(v__tmp130, eax);
  // Let
  CC.mov(v_rd, v__tmp130);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_REM(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction REM
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  // Type clarification
  Gp v__tmp131 = CC.newUInt32();
  CC.mov(v__tmp131, v_rs1);
  // Type clarification
  Gp v__tmp132 = CC.newUInt32();
  CC.mov(v__tmp132, v_rs2);
  Gp v__tmp133 = CC.newUInt32();
  // Mod prelude
  CC.mov(eax, v__tmp131);
  CC.emit(x86::Inst::kIdCdq);
  // idiv
  CC.emit(x86::Inst::kIdIdiv, v__tmp132);
  CC.mov(v__tmp133, edx);
  // Let
  CC.mov(v_rd, v__tmp133);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}


void EXEC_REMU(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, XReg rd, XReg rs1, XReg rs2)
// JIT Instruction REMU
{
  Gp v_rd = CC.newUInt32();
  Gp v_rs1 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs1));
    Node->setRet(0, v_rs1);
  }

  Gp v_rs2 = CC.newUInt32();
  // Get Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::getRegWrapper), FuncSignatureT<uint32_t, GeneralSim::ExecContext*, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rs2));
    Node->setRet(0, v_rs2);
  }

  // Type clarification
  Gp v__tmp134 = CC.newUInt32();
  CC.mov(v__tmp134, v_rs1);
  // Type clarification
  Gp v__tmp135 = CC.newUInt32();
  CC.mov(v__tmp135, v_rs2);
  Gp v__tmp136 = CC.newUInt32();
  // Mod prelude
  CC.mov(eax, v__tmp134);
  CC.emit(x86::Inst::kIdCdq);
  // idiv
  CC.emit(x86::Inst::kIdIdiv, v__tmp135);
  CC.mov(v__tmp136, edx);
  // Let
  CC.mov(v_rd, v__tmp136);

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

  // Set Register
  {
    InvokeNode* Node;
    CC.invoke(&Node, imm(&GeneralSim::setRegWrapper), FuncSignatureT<void, GeneralSim::ExecContext*, uint32_t, uint32_t>(CallConvId::kCDecl));
    Node->setArg(0, CtxPtrReg);
    Node->setArg(1, imm(rd));
    Node->setArg(2, v_rd);
  }

}

void JIT::emitInstruction(asmjit::x86::Compiler& CC, asmjit::x86::Gp CtxPtrReg, Instruction Instr) {
  std::visit([&](auto&& I) {
    using T = std::decay_t<decltype(I)>;
    if constexpr (std::is_same_v<T, ADD>) {
    EXEC_ADD(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, SUB>) {
    EXEC_SUB(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, SLL>) {
    EXEC_SLL(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, SLT>) {
    EXEC_SLT(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, SLTU>) {
    EXEC_SLTU(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, XOR>) {
    EXEC_XOR(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, SRL>) {
    EXEC_SRL(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, SRA>) {
    EXEC_SRA(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, OR>) {
    EXEC_OR(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, AND>) {
    EXEC_AND(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, ADDI>) {
    EXEC_ADDI(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, SLTI>) {
    EXEC_SLTI(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, SLTIU>) {
    EXEC_SLTIU(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, XORI>) {
    EXEC_XORI(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, ORI>) {
    EXEC_ORI(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, ANDI>) {
    EXEC_ANDI(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, SLLI>) {
    EXEC_SLLI(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, SRLI>) {
    EXEC_SRLI(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, SRAI>) {
    EXEC_SRAI(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, LB>) {
    EXEC_LB(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, LH>) {
    EXEC_LH(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, LW>) {
    EXEC_LW(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, LBU>) {
    EXEC_LBU(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, LHU>) {
    EXEC_LHU(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, SB>) {
    EXEC_SB(CC, CtxPtrReg, I.rs2, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, SH>) {
    EXEC_SH(CC, CtxPtrReg, I.rs2, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, SW>) {
    EXEC_SW(CC, CtxPtrReg, I.rs2, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, JAL>) {
    EXEC_JAL(CC, CtxPtrReg, I.rd, I.imm); } else if constexpr (std::is_same_v<T, JALR>) {
    EXEC_JALR(CC, CtxPtrReg, I.rd, I.rs1, I.imm); } else if constexpr (std::is_same_v<T, LUI>) {
    EXEC_LUI(CC, CtxPtrReg, I.rd, I.imm); } else if constexpr (std::is_same_v<T, AUIPC>) {
    EXEC_AUIPC(CC, CtxPtrReg, I.rd, I.imm); } else if constexpr (std::is_same_v<T, BEQ>) {
    EXEC_BEQ(CC, CtxPtrReg, I.rs1, I.rs2, I.imm); } else if constexpr (std::is_same_v<T, BNE>) {
    EXEC_BNE(CC, CtxPtrReg, I.rs1, I.rs2, I.imm); } else if constexpr (std::is_same_v<T, BLT>) {
    EXEC_BLT(CC, CtxPtrReg, I.rs1, I.rs2, I.imm); } else if constexpr (std::is_same_v<T, BGE>) {
    EXEC_BGE(CC, CtxPtrReg, I.rs1, I.rs2, I.imm); } else if constexpr (std::is_same_v<T, BGEU>) {
    EXEC_BGEU(CC, CtxPtrReg, I.rs1, I.rs2, I.imm); } else if constexpr (std::is_same_v<T, BLTU>) {
    EXEC_BLTU(CC, CtxPtrReg, I.rs1, I.rs2, I.imm); } else if constexpr (std::is_same_v<T, ECALL>) {
    EXEC_ECALL(CC, CtxPtrReg); } else if constexpr (std::is_same_v<T, MUL>) {
    EXEC_MUL(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, MULH>) {
    EXEC_MULH(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, MULHSU>) {
    EXEC_MULHSU(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, MULHU>) {
    EXEC_MULHU(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, DIV>) {
    EXEC_DIV(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, DIVU>) {
    EXEC_DIVU(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, REM>) {
    EXEC_REM(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); } else if constexpr (std::is_same_v<T, REMU>) {
    EXEC_REMU(CC, CtxPtrReg, I.rd, I.rs1, I.rs2); }
    }, Instr);
}
} // namespace GeneralSim
