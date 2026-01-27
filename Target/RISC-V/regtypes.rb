module SimInfra
  # Those will be used for validation
  # Can add FReg, VReg e.t.c without changing anything else.
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
  class XImm
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