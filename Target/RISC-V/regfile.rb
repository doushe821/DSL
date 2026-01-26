module SimInfra
    class XReg
        attr_reader :name
        def initialize(name)
            @name = name
        end

        # String representation for asm output
        def to_s
            @name.to_s
        end
    end

    def XReg(name); XReg.new(name); end
    # TODO register description
    # TODO Make infra in Generic folder
    # :name, :size, :hw[value]
    # alias zero hw[0] (example)
    class XImm # for regs used as imm (shamt)
        attr_reader :name
        def initialize(name)
            @name = name
        end

        # String representation for asm output
        def to_s
            @name.to_s
        end
    end

    def XImm(name); XImm.new(name); end
end
