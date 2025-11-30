require_relative 'base'
require 'yaml'
require 'set'
require 'map_tree.rb'

module SimGen
  class UltimateGenerator
    def initialize
      yaml = File.read('IR.yaml')
      @@parsed_ir = YAML.safe_load(yaml,
        permitted_classes: [SimInfra::Field, SimInfra::Scope, SimInfra::IrStmt,
        SimInfra::Var, SimInfra::XReg, Symbol], aliases: true)
    end
  end

  def generate_description
    @@parsed_ir.each do |instr|
      fields = instr.dig(:fields)
      fields.each do |field|
        
      end
    end
  end


  def generate_decoder
    format_switch = {}
    @@parsed_ir.each do |instr|
      format_name = instr.dig(:format)
      fields = instr.dig(:fields)
      instr_path = []
      fields.each do |field|
        field_name = field.dig(:name)
        if field_name == :opcode
          if !format_switch.key?(format_name)
            format_switch[format_name] = [field.value, MapTree::Tree.new(instr.dig(:format))]
          end
        elsif field_name.include?('funct')
          if instr_path.empty
            funct_node = format_switch[format_name][1].search(field_name)
            if funct_node
              if !funct_node.has_child?(field.value)
                funct_node.add_child(field.value)
              end
              instr_path.push(field.value)
            else
            end
          end
        end
      end
    end
  end



end