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
Following elements of architecture must be described: 
1. Instructions encoding
2. Instructions semantics
3. Registers

#### Encoding description
Firstly, user must describe one of the formats: format's name is defined
by user and the only restriction is Ruby syntax. Then, in ``main.rb`` require 
base, builder and regbuilder and then, require all your description files. 
after that, require gen and gen_ragstate for C++ code emition.
Encoding must have fields. Fields can be added with field() and immpart() methods.
Use second one when immediate bits are scattered across the binary instruction's fields. Use first one to describe any other field. You technically can put regular immediate in immpart() instead of field and it won't even affect performance, so feel 
free to choose. 

```Ruby
Field = Struct.new(:name, :from, :to, :value, :fixed)
ImmFieldPart = Struct.new(:name, :from, :to, :hi, :lo, :value)
```
From and to are defined from the end of the word, so e.g. opcode field in RISC-V would be ``(:opcode, 6, 0, opcode_value, true)``. Last parameter is false by default and MUST be specified by user if the field is constant. 
After describing encoding, you should describe instruction's semantics and asm:
```Ruby
InstructionInfo= Struct.new(:name, :fields, :format, :code, :args, :asm, :control_flow)
```
You can explicitly set ``:control_flow`` to ``:branch`` or ``:jump`` (for now, it doesn't matter as long as it is not nil), however, you do not need to do that as there is ``setpc`` operation that automatically sets control flow parameter.
You can fill those fields however you like, but if you want some reference, check ``Target/RISC-V`` of this repository.

Interesting part: semantics description.

I tried to make it as close to semantics description from official ISA descriptions as possible.

1. []= sets register
2. setpc sets pc, you can get pc value by simply typing pc as it is register separate
from your description.
3. Logical and arithmetical operations are default.
4. s/zext(variable, from: smalle_value, to: bigger_value) is for sign/zero extension.
5. as_signed/unsigned() is for telling emitter sign of the variable.
6. Do all comparisons with cmp_..() method.
7. Memory access with load/store.

### Decoder
Builds decoder tree that is emitted to C++ code with lots of switches based on 
set of fixed bits. If you forget to specify some bits as fixed, tree will be suboptimal. It uses information gain metric paired with penalty for fan-out and imbalance gain.

### Interpreter
Decodes one instruction, executes one instruction, can be executed with "pretty" dumps after each execution with CLI arguments. 
### Memory
Highly modular, connected to ``GeneralSim::CPU`` with an interface, so model of memory can be easily changed without touching CPU at all. Moreover, you can add MMU and CPU will still require hardly any changes.
### JIT
Breaks encapsulation a bit, but it is worth it for the performance gain (4-5 times faster than interpreter). It has direct access to registers, but still accesses memory via interface functions, because it feels right (TODO: improve argumentation).

## Usage
```
git clone https://github.com/doushe821/DSL.git
git submodule update --init --recursive
```
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
