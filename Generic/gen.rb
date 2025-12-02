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
      dump_tree_to_graphviz(tree, 'dtree.dot')
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

    # Everything below is AI generated (except some comments)

    def dump_tree_to_graphviz(root_node, output_file_path = nil)
      # Initialize the output string with the graph header
      graphviz_output = StringIO.new
      graphviz_output.puts "digraph InstructionDecodeTree {"
      graphviz_output.puts "  node [shape=box];" # Optional: make nodes rectangular
      graphviz_output.puts "  rankdir=TB;"      # Optional: Top to Bottom layout

      # Start the recursive traversal from the root
      node_counter = 0 # To generate unique node IDs in the graph
      traverse_and_write_node(graphviz_output, root_node, "root", node_counter)

      # Close the graph definition
      graphviz_output.puts "}"

      # Get the final string
      result_string = graphviz_output.string
      graphviz_output.close # Good practice

      # Output the result
      if output_file_path
        File.write(output_file_path, result_string)
        puts "Graphviz DOT output written to #{output_file_path}"
      else
        puts result_string
      end

      result_string # Return the string in case you want to use it elsewhere
    end

    private

    def traverse_and_write_node(io, node, parent_id, node_counter)
      # Generate a unique ID for the current node
      current_node_id = "node_#{node_counter}"
      node_counter += 1 # Increment counter for potential children

      # Create a label for the current node
      # You might want to customize this label based on your needs
      label_parts = [
        "Indexes: #{node.bit_indexes.inspect}",
        "Width: #{node.width}"
      ]
      node_label = label_parts.join("\\n") # Use \n for line breaks in DOT

      # Write the node definition
      io.puts "  #{current_node_id} [label=\"#{node_label}\"];"

      # Write an edge from the parent to this node (if not the root)
      if parent_id != "root"
        io.puts "  #{parent_id} -> #{current_node_id};"
      end

      # Iterate through the children in the 'nodes' hash
      node.nodes.each do |pattern, child_value|
        if child_value.is_a?(MapTree::Node) # Child is another internal node/subtree
          # Recursively process the child node
          traverse_and_write_node(io, child_value, current_node_id, node_counter)
          # The edge to this child will be created in the recursive call when it defines its own ID
        else # Child is a leaf (e.g., an instruction object)
          # Generate a unique ID for the leaf node
          leaf_id = "leaf_#{node_counter}"
          node_counter += 1 # Increment counter

          # Create a label for the leaf node
          # Customize this based on the structure of your instruction objects
          leaf_label = child_value[:name].to_s + ',' + child_value[:bin_value].to_s(2) # AHAHAAAHA, false assumption)) Assuming the instruction object has a good to_s representation

          # Write the leaf node definition
          io.puts "  #{leaf_id} [label=\"#{leaf_label}\", shape=ellipse];" # Use ellipse for leaves

          # Write the edge from the current node to the leaf
          io.puts "  #{current_node_id} -> #{leaf_id} [label=\"#{pattern}\"];"
        end
      end
    end

  end
end
