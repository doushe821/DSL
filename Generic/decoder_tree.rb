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

    entropy =
      counts.reduce(0.0) do |h, c|
        p = c / total
        h - p * Math.log2(p)
      end

    parent_entropy = Math.log2(total)

    info_gain = parent_entropy - entropy

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


  def self.best_bit_slice(words,
                          width: 32,
                          max_slice: 6,
                          alpha: -1,
                          beta: -1,
                          gamma: -1)

    best = nil
    best_score = -Float::INFINITY

    (0...width).each do |start_bit|
      (start_bit...[start_bit + max_slice, width].min).each do |end_bit|
        slice_width = end_bit - start_bit + 1

        result = score_slice(words, start_bit, end_bit)
        next unless result

        info_gain = result[:info_gain]
        fanout = result[:fanout]
        imbalance = result[:imbalance]

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
          best = [start_bit, end_bit]
        end
      end
    end

    best
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
