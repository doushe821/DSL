#!/usr/bin/ruby
require_relative "Generic/base"
require_relative "Generic/builder"
require_relative "Target/RISC-V/32I.rb"
require_relative "Generic/gen.rb"

SimInfra.serialize
# SimInfra::DecoderGenerator.generate("zxc")

UGen = SimGen::UltimateGenerator.new
UGen.generate_decoder