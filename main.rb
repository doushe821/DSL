#!/usr/bin/ruby
require_relative "Generic/base"
require_relative "Generic/builder"
require_relative "Generic/regbuilder"
require_relative "Target/RISC-V/32I.rb"
require_relative "Target/RISC-V/32M"
require_relative "Target/RISC-V/regfile"
require_relative "CodeGen/gen.rb"
require_relative "CodeGen/gen_regstate"
SimInfra.serialize
# SimInfra::DecoderGenerator.generate("zxc")
# UGen = SimGen::UltimateGenerator.new
SimGen::GenStateGenerator.new
