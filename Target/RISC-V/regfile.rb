require_relative "../../Generic/base"
module RegFile
  extend SimInfra
  Reg(:x0, size: 32, type: :int, hv: 0) {
    aka :zero
  }

  Regs(:x) {
    1.upto(31) do |i|
      Reg :"x#{i}", size: 32, type: :int
    end
  }

  alias_reg(:sp, :x2)

end
