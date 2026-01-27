# Testing infra

module SimInfra
    # @@instructions -array of instruction description
    # shows result of our tests in interactive Ruby (IRB) or standalone
    def self.serialize(msg= nil)
        return @@instructions, @@registers_specs if Object.const_defined?(:IRB)
        require 'yaml'

        yaml_regfile_data = YAML.dump(@@registers_specs.map(&:to_h))
        File.open("Regfile.yaml", "w") do |file|
            file.write(yaml_regfile_data)
        end

        yaml_IR_data = YAML.dump(@@instructions.map(&:to_h))
        File.open("IR.yaml", "w") do |file|
            file.write(yaml_IR_data)
        end
    end

    # reset state
    def siminfra_reset_module_state; @@instructions = []; @@registers_specs = [] end

    # mixin for global counter, function returns 0,1,2,....
    module GlobalCounter
        @@counter = -1
        def next_counter; @@counter += 1; end
    end

    Field = Struct.new(:name, :from, :to, :value)
    ImmFieldPart = Struct.new(:name, :from, :to, :hi, :lo, :value)

    def field(name, from, to, value = nil)
        Field.new(name, from, to, value).freeze
    end
    def immpart(name, from, to, hi, lo)
        ImmFieldPart.new(name, from, to, hi, lo).freeze
    end

    def assert(condition, msg = nil); raise msg if !condition; end
end
