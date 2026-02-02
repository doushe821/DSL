# decoder_tree.rb

module DecoderTree

  Word = Struct.new(:name, :bits)

  class Node
    attr_accessor :bit_start, :bit_end, :children, :name

    def initialize(bit_start: nil, bit_end: nil, name: nil)
      @bit_start = bit_start
      @bit_end = bit_end
      @children = {}
      @name = name
    end

    def leaf?
      !@name.nil?
    end
  end

  def self.slice_value(bits, start_bit, end_bit)
    mask = ((1 << (end_bit - start_bit + 1)) - 1) << start_bit
    (bits & mask) >> start_bit
  end

  def self.score_slice(words, start_bit, end_bit)
    buckets = Hash.new(0)

    words.each do |w|
      buckets[slice_value(w.bits, start_bit, end_bit)] += 1
    end

    counts = buckets.values
    return nil if counts.size <= 1

    total = counts.sum.to_f
    conditional_entropy =
      counts.reduce(0.0) do |h, c|
        p = c / total
        p * Math.log2(p)
      end

    parent_entropy = Math.log2(total)

    info_gain = parent_entropy - conditional_entropy

    avg = total / counts.size
    variance =
      counts.reduce(0.0) { |v, c| v + (c - avg)**2 } / counts.size
    std_dev = Math.sqrt(variance)
    {
      info_gain: info_gain,
      fanout: counts.size,
      imbalance: std_dev / total,
    }
  end


  def self.best_bit_slice(words, # TODO make determined
                          width: 32,
                          max_slice: 32,
                          alpha: 0.15,
                          beta: -1,
                          gamma: -1)

    best = nil
    best_score = -Float::INFINITY
    
    allowed_slices = get_allowed_slices(words, max_slice: max_slice)

    allowed_slices.each do |slice|
      result = score_slice(words, slice[0], slice[1])
      next unless result

      # black magic
      info_gain = result[:info_gain]
      fanout = result[:fanout]
      imbalance = result[:imbalance]

      slice_width = slice[1] - slice[0] + 1
      width_penalty = alpha * slice_width
      fanout_penalty = beta * fanout

      imbalance_penalty = gamma * imbalance

      score =
        info_gain -
        width_penalty -
        fanout_penalty -
        imbalance_penalty

        if score > best_score
          best_score = score
          best = [slice[0], slice[1]]
        end
    end

    best
  end

  def self.get_allowed_slices(words, max_slice: nil)
    allowed_slices_mask = words.map(&:fixed_mask).reduce { |a, b| a & b }
    slices_from_mask(allowed_slices_mask, max_slice: max_slice)
  end

  def self.slices_from_mask(mask, width: 32, max_slice: nil)
    slices = []
    bit = 0
    while bit < width
      # zero skipper
      if ((mask >> bit) & 1) == 0
        bit += 1
        next
      end
      # find next zero
      slice_start = bit
      bit += 1
      while bit < width && ((mask >> bit) & 1) == 1
        bit += 1
      end
      slice_end = bit - 1

      (slice_start..slice_end).each do |slice|
        max_e =
          if max_slice
            [slice + max_slice - 1, slice_end].min
          else
            slice_end
          end

        (slice..max_e).each do |e|
          slices << [slice, e]
        end
      end
    end
    
    slices
  end

  def self.build_tree(words, width = 32)
    return Node.new(name: words.first.name) if words.size == 1

    slice = best_bit_slice(words, width: width)
    raise "Cannot split further (Probably instructions in set aren't unique)" unless slice

    start_bit, end_bit = slice
    node = Node.new(bit_start: start_bit, bit_end: end_bit)

    buckets = Hash.new { |h, k| h[k] = [] }
    words.each do |word|
      key = slice_value(word.bits, start_bit, end_bit)
      buckets[key] << word
    end

    buckets.each do |key, subset|
      node.children[key] = build_tree(subset, width)
    end

    node
  end

  def self.generate_dot(root)
    dot = ["digraph DecoderTree {"]
    node_id = 0

    traverse = lambda do |node|
      id = node_id
      node_id += 1

      if node.leaf?
        dot << "  node#{id} [shape=box, label=\"#{node.name}\"];"
      else
        dot << "  node#{id} [label=\"bits #{node.bit_start}..#{node.bit_end}\"];"
        node.children.each do |val, child|
          cid = traverse.call(child)
          dot << "  node#{id} -> node#{cid} [label=\"#{val}\"];"
        end
      end

      id
    end

    traverse.call(root)
    dot << "}"
    dot.join("\n")
  end
end
