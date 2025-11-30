require_relative 'base'
require 'yaml'
require 'set'
require_relative 'map_tree.rb'

module SimGen
  class UltimateGenerator
    def initialize
      yaml = File.read('IR.yaml')
      @@parsed_ir = YAML.safe_load(yaml,
        permitted_classes: [SimInfra::Field, SimInfra::Scope, SimInfra::IrStmt,
        SimInfra::Var, SimInfra::XReg, Symbol], aliases: true)
    end
  


    def generate_decoder
      format_switch = {}
      @@parsed_ir.each do |instr|
        format_name = instr.dig(:format)

        puts 'building tree for ' + instr.dig(:name).to_s

        fields = instr.dig(:fields)
        decode_path = []
        fields.each do |field|
          field_name = field.dig(:name)

          puts 'analyzing field ' + field_name.to_s

          if field_name == :opcode

            if !format_switch.key?(format_name)
              puts 'tree initialized for format ' + instr.dig(:format).to_s
              format_switch[format_name] = [field.dig(:value), MapTree::Tree.new('dummy')]
              
              puts format_switch[format_name][1].dump_text
            end

          elsif field_name.to_s.include?('funct') # const field
            puts 'found funct field: ' + field_name.to_s
            if decode_path.empty? # means that this funct field is the first
              if !format_switch[format_name][1].root.has_child?(field.dig(:value))
                format_switch[format_name][1].root.value = field_name
                new_node = MapTree::TreeNode.new('dummy')
                format_switch[format_name][1].root.add_child(field.dig(:value), new_node)
                puts format_switch[format_name][1].dump_text
              end
              decode_path.push(field.dig(:value))
            else 
              if !format_switch[format_name][1].search_by_path(decode_path).has_child?(field.dig(:value))
                new_node = MapTree::TreeNode.new('dummy')
                format_switch[format_name][1].search_by_path(decode_path).value = field_name
                format_switch[format_name][1].search_by_path(decode_path).add_child(field.dig(:value), new_node)
              end
              decode_path.push(field.dig(:value))
            end
          
          

          end
        end
        format_switch[format_name][1].search_by_path(decode_path).value = instr.dig(:name)
      end

      # DEBUG
      format_switch.values.each do |format|
        puts format[1].dump_text
      end
      # DEBUG
    end
  end
end