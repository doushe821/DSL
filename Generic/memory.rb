require_relative "base"

module SimInfra
  
  class Memory
    def initialize(scope)
      @scope = scope
    end

    def [](addr, width)
      @scope.load(addr)
    end

    def []=(addr, value)
      @scope.store(addr, value)
    end
  end

end
