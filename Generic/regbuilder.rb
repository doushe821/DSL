# TODO register validation.
# Not so important right now
# because the only type of supported registers is int.
module SimInfra
  @@registers_specs = []
  RegSpec = Struct.new(:name, :size, :hv, :type, :aliases, :properties)
  
# TODO add other register types.
    
  def Reg(name, size:, type:, hv: nil, **opts, &block)
    spec = RegSpec.new(
    name: name,
    size: size,
    type: type,
    hv: hv,
    aliases: [],
    properties: opts
    )

    if block
      RegBuilder.new(spec).instance_eval(&block)
    end

    @@registers_specs << spec
    nil
  end

  def alias_reg(alias_name, reg_name)
    reg = @registers.find { |r| r.name == reg_name }
    raise "Unknown register #{reg_name}" unless reg
    reg.aliases << alias_name
  end

  def Regs(common_name, &block)
    instance_eval(&block)
  end

  class RegBuilder
    def initialize(spec)
      @spec = spec
    end

    def constant(val)
      @spec.constant = val
    end

    def aka(name)
      @spec.aliases << name
    end

    def method_missing(name, value) # will be needed in future
      @spec.properties[name] = value # (for vector and special regs)
    end
  end

end
