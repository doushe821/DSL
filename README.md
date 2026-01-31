# DSL
Implementation of Domain-Specific-Language (DSL) for general Instruction Set Architecture specifics' description.
Along with DSL, this project contains implementation of (mostly) architecture-independent simulator core.
It provides interpreter/JIT co-simulation.
DSL is Ruby-based, generated code is C++.
Currently has fully-described RV32IM architecture in ``Target/RISC-V``.
This is an educational project based on https://github.com/ProteusLab/ProtDSL.
Project uses [CLI11](https://github.com/CLIUtils/CLI11), [elfio](https://github.com/serge1/ELFIO), [Catch2](https://github.com/catchorg/Catch2) and [asmjit](https://asmjit.com/).

## Structure

```bash
DSL/
├── Generic/                # Base constructs and core DSL infrastructure
│   ├── base.rb             # Fundamental base classes and utilities
│   ├── builder.rb          # DSL builder pattern implementation
│   ├── scope.rb            # Scope management for symbol resolution
│   └── var.rb              # Variable and operand definitions
├── Target/                 # Target architecture implementations
│   └── RISC-V/             # RISC-V architecture support
│       ├── 32I.rb          # RV32I base instruction set definition
│       ├── encoding.rb     # Instruction encoding schemes
│       └── regfile.rb      # Register file configuration
├── CodeGen/                # IR parser, C++ code emitter
│   ├── gen.rb              # Main emitter
│   ├── decoder_tree.rb     # Decoder tree emitter
│   ├── map_tree.rb         # Helper structure for tree emitter
│   ├── gen_regstate.rb     # Register holder class emitter
│   ├── codegen.rb          # Interpreter code generator
│   └── jitgen.rb           # JIT code generator
└── main.rb                 # Main entry point and examples
```
Generated files are marked with (g):
```bash
DSL/Sim
├── src/
│   ├── CPU.cpp             # Controls simulation
│   ├── Decoder.cpp         # Decodes. 
│   ├── ElfLoader.cpp       # Loads ELF files of target architecture
|   ├── JIT.cpp             # JIT infrastracture
|   ├── Memory.cpp          # Memory model
|   ├── main.cpp            # main
│(g)├── Executor.cpp        # Instruction execution for interpreter
|(g)├── JITExecutor.cpp     # Instruction execution for JIT (using asmjit)
|(g)└──RegState.cpp         # Reg state holder
├── include/
│   ├── elfio               # elfio (HO)
│   ├── CLI11.hpp           # CLI11 (HO)
│   ├── ...                 # name.hpp description matches name.cpp
│   ├── GeneralSimTypes.hpp # Architecture-independent types 
│   ├── GeneralSim.hpp      # CPU class
│   ├── ExecContext.hpp     # Execution interface
│(g)├── Instructions.hpp    # Instruction structure description
│(g)├── RegAliases.hpp      # enum with register aliasess
│   ├── TestInfra.hpp       # infra for Tests
│   ├── ExecutorTestOnly.hpp# I'm a monkey
├── external/               # asmjit submodule 
└── CMakeLists.txt          # Check Usage
```

## Implementation details
### DSL

### Decoder

### Interpreter

### Memory

### JIT

## Usage
Describe target architecture in Target directory (there will be dsl syntax rules in future). This repository contains RV32IM description for reference.

Generate decoder, encoder, register file, e.t.c.:
```
ruby main.rb
```
Compile simulator in Sim directory:

```
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++
cmake --build build
```

This will compile both ``sim`` and ``sim_tests`` executables. Tests can be added in
``Sim/src/Tests.cpp`` (I use [Catch2](https://github.com/catchorg/Catch2)).

After compilator has been compiled:
```
./sim --elf=elf_name
```

For greater dump (in cost of much slower performance):
```
./sim --elf=elf_name --pretty=true
```

ELF should be compiled and linked with ``-nostdlib`` option (for now).

You can also run tests:
```
./sim_tests
```
They cover some edge-cases for RV32IM instructions.
