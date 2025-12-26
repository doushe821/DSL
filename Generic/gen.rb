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
        SimInfra::Var, SimInfra::XReg, SimInfra::ImmFieldPart, SimInfra::XImm, 
        Symbol], aliases: true)
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
      generate_short_isa_description
    end

    BinInstr = Struct.new(:name, :bin_value)

    def generate_decoder
      tree_root = make_head(@@bin_instrs)
      dump_tree_to_graphviz(tree_root, 'dtree.dot')
      traverse_decode_tree(tree_root)
    end

    def traverse_decode_tree(tree_root)
      File.open('decoder.cpp', 'w') do |file|
        file.write(
        "// Generated code //\n" + 
        "#include \"decoder.hpp\"\n" +
        "#include \"ShortISADescription.hpp\"\n" +
        "#include \"GeneralSim.hpp\"\n" +
        "\n" +
        "ISA::InstructionCodes Decode(int /*replace with actual undecoded instruction type here*/ instr) {\n" # TODO in comment
        )
        tab_counter = 1
        gen_cpp_from_layer(tree_root, tab_counter, file)
        file.write("}\n")
      end
    end

    def gen_cpp_from_layer(node, tab_counter, file)
      tab_counter += 1
      bit_pattern = node[:bit_indexes]
      bit_pattern_string = bit_pattern.to_s
      file.write(' ' * tab_counter + "switch(GetMaskedValue(instr, " + bit_pattern_string + ")) {\n")
      node[:nodes].each do |child_node|
        puts child_node
        puts
        file.write("  " * tab_counter + "case " + child_node[0].to_s + ": {\n")
        
        if child_node[1].is_a? SimGen::UltimateGenerator::BinInstr # reflexion power!
          file.write("  " * (tab_counter + 1) + "return " + child_node[1][:name].to_s + ";\n")
        else # another switch
          gen_cpp_from_layer(child_node, tab_counter, file) # TODO might be source of shifted tabs, check later when tree is big enouogh to notice
        end
        file.write("  " * (tab_counter) + "}\n")
      end
      tab_counter -= 1
      file.write("  " * tab_counter + "}\n")

    end

    def generate_short_isa_description
      File.open('ShortISADescription.hpp', 'w') do |file|
        file.write "#pragma once\n"
        file.write "namespace ISA {\n" +
        "  enum class InstructionCodes {\n"
        @@bin_instrs.each do |instr|
          file.write "    " + instr.name.to_s + ','
          file.write "\n"
        end
        file.write "      INVALID\n"

        file.write "  };\n" +
        "} // namespace ISA\n"

      end
    end

    def get_lead_bits(instructions)
      return [] if instructions.length <= 1 

      all_possible_bits = (0...32).to_a 
      selected_bits = []

      current_patterns = Array.new(instructions.length) { "" } 

      while selected_bits.length < 32
        best_bit = nil
        max_unique_count = current_patterns.uniq.length

        if max_unique_count == instructions.length
          break 
        end
        best_patterns = []
        (all_possible_bits - selected_bits).each do |bit_idx|
          potential_patterns = []
          instructions.each_with_index do |instr, i|
            bit_val = (instr.bin_value >> bit_idx) & 1
            existing_pattern = current_patterns[i]
            potential_patterns << existing_pattern + bit_val.to_s 
          end

          unique_count = potential_patterns.uniq.length
          
          if unique_count > max_unique_count
            max_unique_count = unique_count
            best_bit = bit_idx
            best_patterns = potential_patterns.dup 
          end
        end

        # If no bit was found that increases uniqueness, it implies either:
        # 1. We have already distinguished all instructions (handled by the break above).
        # 2. There are duplicate instructions in the subset (meaning they are indistinguishable by constant fields).
        # In case 2, we cannot proceed further with this method for *these specific instructions*.
        # For now, we break the loop to prevent infinite recursion. 
        # A more robust system might flag this ambiguity.
        if best_bit.nil?
          puts "Warning: Could not find a bit to further distinguish #{instructions.length} instructions." if instructions.length > current_patterns.uniq.length
          puts "This might indicate duplicate definitions or instructions indistinguishable by constant fields." if instructions.length > current_patterns.uniq.length
          break # Exit the loop to avoid infinite recursion
        end

        # Add the best bit found in this iteration to the selection
        selected_bits << best_bit
        
        # Update the patterns for the next iteration based on the bit we just added
        current_patterns = best_patterns
      end

      # Return the list of selected bit indexes that achieve maximum distinguishability
      # for the given subset.
      selected_bits 
    end

    def filter_instructions(instructions, lead_bits, target_pattern)

      instructions.select do |instr|
        puts "lead_bits: " + lead_bits.to_s
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
      if lead_bits == nil
        return nil, nil
      end
      sublist = filter_instructions(instructions, lead_bits, bit_pattern)

      if sublist.empty?
        return nil, nil
      end
      if sublist.length == 1
        return true, sublist[0]
      end

      new_lead_bits = get_lead_bits(sublist)
      new_width = new_lead_bits.length
      puts
      puts new_lead_bits
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

    # Everything below is AI generated

    def dump_tree_to_graphviz(root_node, output_file_path = nil)
      graphviz_output = StringIO.new
      graphviz_output.puts "digraph InstructionDecodeTree {"
      graphviz_output.puts "  node [shape=box];"
      graphviz_output.puts "  rankdir=TB;"

      node_counter = 0
      traverse_and_write_node(graphviz_output, root_node, "root", node_counter)

      graphviz_output.puts "}"

      result_string = graphviz_output.string
      graphviz_output.close

      if output_file_path
        File.write(output_file_path, result_string)
        puts "Graphviz DOT output written to #{output_file_path}"
      else
        puts result_string
      end

      result_string
    end

    private

    def traverse_and_write_node(io, node, parent_id, node_counter, parent_pattern = nil)
      current_node_id = "node_#{node_counter}"
      node_counter += 1

      label_parts = [
        "Indexes: #{node.bit_indexes.inspect}",
        "Width: #{node.width}"
      ]
      node_label = label_parts.join("\\n")

      io.puts "  #{current_node_id} [label=\"#{node_label}\"];"

      if parent_id != "root"
        label_attr = parent_pattern ? " [label=\"#{parent_pattern}\"]" : ""
        io.puts "  #{parent_id} -> #{current_node_id}#{label_attr};"
      end

      node.nodes.each do |pattern, child_value|
        if child_value.is_a?(MapTree::Node)
          traverse_and_write_node(io, child_value, current_node_id, node_counter, pattern)
        else
          leaf_id = "leaf_#{node_counter}"
          node_counter += 1

          leaf_label = child_value[:name].to_s + ',' + child_value[:bin_value].to_s(2)

          io.puts "  #{leaf_id} [label=\"#{leaf_label}\", shape=ellipse];"

          io.puts "  #{current_node_id} -> #{leaf_id} [label=\"#{pattern}\"];"
        end
      end
    end

  end
end
