require_relative "base"
require_relative "var"
require_relative "memory"

module SimInfra
  class Scope

    Type = Struct.new(:kind, :bits, :signed) do
      def self.s(bits) = new(:int, bits, true)
      def self.u(bits) = new(:int, bits, false)
      def self.mem     = new(:mem, nil, nil)

      def int? = kind == :int
      def mem? = kind == :mem

      def to_s
          return "mem" if mem?
          signed ? "i#{bits}" : "u#{bits}"
      end
    end


    include GlobalCounter # used for temp variables IDs
    attr_reader :tree, :vars, :parent
    def initialize(parent = nil) 
      @parent = parent
      @tree = []
      @vars = {}
    end
    # resolve allows to convert Ruby Integer constants to Constant instance

    def var(name, type)
      unless type.is_a?(Type)
          raise TypeError, "Var #{name} has invalid type #{type.inspect}, expected Type"
      end
      @vars[name] = SimInfra::Var.new(self, name, type) # return var
      #instance_eval "def #{name.to_s}(); return @vars[:#{name.to_s}]; end" # Replaced with method_missing
      stmt :new_var, [@vars[name]] # returns @vars[name]
    end

    def method_missing(name, *)
        return @vars[name] if @vars.key?(name) # Instead of instance eval in var
        super
    end

    def pc
        stmt :getpc, [tmpvar(Type.u(32))]
    end

    def setpc(var)
      raise "Cannot set SSA variable" if var.is_a?(SimInfra::XReg)
      stmt(:setpc, [var.name, var])
    end

    def setreg(reg_var)
      raise "Cannot set SSA variable" if reg_var.is_a?(SimInfra::XReg)
      stmt(:setreg, [reg_var.name, reg_var])
    end

    def add_var(name, type); var(name, type); self; end

    def resolve_const(what)
        return what if (what.class== Var) or (what.class== Constant) # or other known classes
        return new_tmp_const(what) if what.is_a?(Integer)
    end

    def syscall(*args)
      args = args.map { |a| resolve_const(a) }
      ret = tmpvar(Type.u(32))
      stmt :syscall, [ret, *args]
    end

    def memory
        @memory ||= SimInfra::Memory.new(self)
    end

    alias m memory

    def load(addr, width)
        type = Type.u(width)
        addr = resolve_const(addr)
        tmp  = tmpvar(type)
        stmt(:load, [tmp, addr])
    end

    def store(addr, value)
        addr  = resolve_const(addr)
        value = resolve_const(value)
        stmt(:store, [addr, value])
    end

    def binOp(a,b, op);
        a = resolve_const(a); b = resolve_const(b)
        # TODO: check constant size <= bitsize(var)
        # assert(a.type == b.type|| a.type == :iconst || b.type == :iconst)
        stmt op, [tmpvar(a.type), a, b]
    end

    def unOp(a, op);
        a = resolve_const(a)
        stmt op, [tmpvar(a.type), a]
    end

    def as_signed(a)
        a = resolve_const(a)
        stmt :as_signed, [tmpvar(a.type), a]
    end

    def as_unsigned(a)
        a = resolve_const(a)
        stmt :as_unsigned, [tmpvar(a.type), a]
    end

    alias s as_signed
    alias u as_unsigned



    def sext(a, from:, to:)
        a = resolve_const(a)
        stmt :sext, [tmpvar(Type.s(to)), a], { from:, to: }
    end

    def zext(a, from:, to:)
        a = resolve_const(a)
        stmt :zext, [tmpvar(Type.u(to)), a], { from:, to: }
    end

    def bitrev(a)
        unOp(a, :bitrev)
    end

    def cmp_eq(a, b)  = cmp_bin(a, b, :cmp_eq)
    def cmp_ne(a, b)  = cmp_bin(a, b, :cmp_ne)

    def cmp_lt(a, b)  = cmp_bin(a, b, :cmp_lt)
    def cmp_ge(a, b)  = cmp_bin(a, b, :cmp_ge)

    def cmp_ltu(a, b) = cmp_bin(a, b, :cmp_ltu)
    def cmp_geu(a, b) = cmp_bin(a, b, :cmp_geu)


    def cmp_bin(a, b, op)
        a = resolve_const(a)
        b = resolve_const(b)
        stmt(op, [tmpvar(Type.s(32)), a, b])
    end

    # Var.new is better than calling var, because it does not pollute :vars for no reason
    private def tmpvar(type); Var.new(self, :"_tmp#{next_counter}".to_sym, type); end
    private def new_tmp_const(value)
        tmp = Var.new(self, :"_c#{next_counter}", Type.s(32))
        stmt(:new_const, [tmp, value])
    end

    # stmt adds statement into tree and returns operand[0]
    # which is result in near all cases
    def stmt(name, operands, attrs= nil);
        result = operands.first
        @tree << IrStmt.new(name, operands, attrs)
        result
    end
  end
end
