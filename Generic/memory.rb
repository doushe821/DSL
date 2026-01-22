require_relative "base"

module SimInfra
  
  class Memory
    def initialize(scope)
      @scope = scope
    end
    
    # Load: rd[] = M[address]
    def [](addr)
      addr = @scope.resolve_const(addr)
      tmp = @scope.tmpvar(Type.s(32))
      @scope.stmt(:load, [tmp, addr])
      tmp
    end
    
    # Store: M[address] = value
    def []=(addr, value)
      addr  = @scope.resolve_const(addr)
      value = @scope.resolve_const(value)
      @scope.stmt(:store, [addr, value])
    end
  end


end