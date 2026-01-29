# DSL
DSL implementation, written in Ruby. Currently supports RV32IM.
This is an educational project based on https://github.com/ProteusLab/ProtDSL.


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

ELF should be compiled and linked with ``-nostdlib`` option (for now).

You can also run tests:
```
./sim_tests
```
They cover some edge-cases for RV32IM instructions.
