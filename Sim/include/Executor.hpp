#pragma once
#include "ExecContext.hpp"
#include "Helpers.hpp"
#include "Instructions.hpp"

namespace GeneralSim {
class Executor {
public:
  void execute(const Instruction &Inst, ExecContext &Ctx);
};
} // namespace GeneralSim
