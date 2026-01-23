#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <stdexcept>

#include "GeneralSim.hpp"

namespace RV32IMRegState {

class RV32IMRegState final : public GeneralSim::RegState {
public:
  using XReg = uint16_t;

  static constexpr uint8_t PERM_USER = 1 << 0; // Expandable
  static constexpr uint8_t PERM_SYS  = 1 << 1;

  struct Register {
    uint64_t Value;
    uint8_t  Perm;
  };

  constexpr RV32IMRegState() : Regs{{
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_USER},
          {0, PERM_SYS},
  }} {};

  virtual uint64_t getReg(XReg r) override {
    assert(r < 33);
    const Register& Reg = Regs[r];
    if (!(Reg.Perm & PERM_USER)) {
      assert(false && "Access to system register from user");
      // throw std::runtime_error("Register access violation");
    }
    return Reg.Value;
  }

  virtual void setReg(XReg r, uint64_t v) override {
    assert(r < 33);
    Register& Reg = Regs[r];
    if (!(Reg.Perm & PERM_USER)) {
      assert(false && "Write to system register from user");
      // throw std::runtime_error("Register access violation");
    }
    Reg.Value = v;
  }

  virtual uint64_t getRegSystem(XReg r) override {
    assert(r < 33);
    return Regs[r].Value;
  }

  virtual void setRegSystem(XReg r, uint64_t v) override {
    assert(r < 33);
    Regs[r].Value = v;
  }


private:
  std::array<Register, 33> Regs;
};

} // namespace RV32IMRegState
