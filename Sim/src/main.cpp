#include <cstdint>
#include <stdexcept>
#include <string>

#include "CLI11.hpp"
#include "ElfLoader.hpp"
#include "GeneralSim.hpp"

int main(int argc, char **argv) {

  size_t MemorySize = 4 * UINT16_MAX;
  CLI::App CLIApp;
  std::string ElfName;
  bool IsPretty;
  bool EnableJIT;
  bool LogInterpeter;
  size_t JITExectuionThreshold;
  CLIApp.add_option("-e,--elf", ElfName, "Name of the ELF file")->required();
  CLIApp.add_option("--memory-size", MemorySize, "Maximum size of the memory")
      ->default_val(4 * UINT16_MAX);
  CLIApp
      .add_option("--pretty", IsPretty,
                  "Set true if you want comprehensible dump (simulation will "
                  "become much slower)")
      ->default_val(false);
  CLIApp
      .add_option("--interpreter-log", LogInterpeter,
                  "Enable logginh")
      ->default_val(false);
  CLIApp
      .add_option("--JIT", EnableJIT,
                  "Set true if you want comprehensible dump (simulation will "
                  "become much slower)")
      ->default_val(false);
  CLIApp
      .add_option(
          "--JIT-threshold", JITExectuionThreshold,
          "How many times PC should be executed in order to start translation")
      ->default_val(UINT64_MAX);

  CLI11_PARSE(CLIApp, argc, argv);

  GeneralSim::CPU SPU(MemorySize, IsPretty, EnableJIT, JITExectuionThreshold);
  size_t EntryPoint{0};
  try {
    loadElf(ElfName, SPU.getRawMem(), MemorySize, EntryPoint);
  } catch (std::runtime_error &E) {
    std::cerr << E.what() << std::endl;
    return 0;
  }

  SPU.setEntry(EntryPoint);

  SPU.run();

  return 0;
}
