require_relative "base"

module SimInfra
  
  class Memory
    def initialize(scope)
      @scope = scope
    end

    def [](addr)
      @scope.load(addr)     # Scope generates SSA temp internally
    end

    def []=(addr, value)
      @scope.store(addr, value)
    end
  end

end
