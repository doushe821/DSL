#pragma once

#include <variant>
#include "GeneralSim.hpp"
struct Add {
  GeneralSim::Register rd;
  GeneralSim::Register rs1;
  GeneralSim::Register rs2;
};


using Instruction = std::variant<
    Add
>;
