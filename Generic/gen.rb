require_relative 'base'
require 'yaml'
require 'set'
require_relative 'map_tree.rb'

module SimGen
  class UltimateGenerator

    @@bin_instrs = []
    def initialize
      yaml = File.read('IR.yaml')
      @@parsed_ir = YAML.safe_load(yaml,
        permitted_classes: [SimInfra::Field, SimInfra::Scope, SimInfra::IrStmt,
        SimInfra::Var, SimInfra::XReg, Symbol], aliases: true)
      # Make an array with default encodings of every instruction to 
      # later determine constant fields.
      @@parsed_ir.each do |instr|
        binary_value = 0
        instr[:fields].each do |field|
          if field.value.is_a?(Integer)
            num_bits = field.from - field.to + 1
            mask = (1 << num_bits) - 1
            masked_value = field.value & mask
            binary_value |= (masked_value << field.to)
          end
        end
        @@bin_instrs.push(BinInstr.new(instr[:name], binary_value))
      end
    end

    BinInstr = Struct.new(:name, :bin_value)
    def generate_decoder
      tree = make_head(@@bin_instrs)
      
    end

    def tree_gen(instruction_subset)
      
    end
    #LeadBitsAndMask = Struct.new(:bits, :mask)


    def get_lead_bits(bin_instruction_subset)
      result = 0
      bin_instruction_subset.each do |inst|
        result = result ^ inst.bin_value
      end
      lead_bits = []
      (0...result.bit_length).each do |i|
        if (result & (1 << i)) != 0
          lead_bits << i
        end
      end
      lead_bits
    end

    def filter_instructions(instructions, lead_bits, target_pattern)

      instructions.select do |instr|
        extracted_bits = []
        lead_bits.each do |idx|
          bit_val = (instr.bin_value >> idx) & 1
          extracted_bits << bit_val
        end

        pattern = 0
        extracted_bits.each_with_index do |bit, i|
          pattern |= (bit << (extracted_bits.length - 1 - i))
        end
        pattern == target_pattern
      end
    end

    def make_child(bit_pattern, instructions, width, lead_bits)
      sublist = filter_instructions(instructions, lead_bits, bit_pattern)

      if sublist.empty?
        return nil, nil
      end
      if sublist.length == 1
        return true, sublist[0]
      end

      new_lead_bits = get_lead_bits(sublist)
      new_width = new_lead_bits.length

      current_root = MapTree::Node.new(new_lead_bits, new_width, {})

      (0..((1 << new_width) - 1)).each do |bit_pattern|
        is_leaf, result = make_child(bit_pattern, sublist, new_width, new_lead_bits)

        if is_leaf # keeping for possible future use
          current_root[:nodes][bit_pattern] = result
        elsif result
          current_root[:nodes][bit_pattern] = result
        end
      end

      return nil, current_root
    end

    def make_head(instructions)
      lead_bits = get_lead_bits(instructions)
      puts lead_bits
      width = lead_bits.length
      root = MapTree::Node.new(lead_bits, width, {})
      (0..((1 << width) - 1)).each do |bit_pattern|
        is_leaf, result = make_child(bit_pattern, instructions, width, lead_bits)

        if is_leaf # keeping for possible future needs
            root[:nodes][bit_pattern] = result
        elsif result
            root[:nodes][bit_pattern] = result
        end
      end
      root
    end
  end
end
