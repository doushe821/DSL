require 'ostruct'

module DecoderTree
  Word = Struct.new(:name, :bin_value)

  class Node
    attr_accessor :bit_start, :bit_end, :children, :instruction

    def initialize(bit_start: nil, bit_end: nil, instruction: nil)
      @bit_start = bit_start
      @bit_end = bit_end
      @children = {}
      @instruction = instruction
    end

    def leaf?
      !@instruction.nil?
    end
  end

  def slice_value(word, start_bit, end_bit)
    mask = ((1 << (end_bit - start_bit + 1)) - 1) << start_bit
    (word.bin_value & mask) >> start_bit
  end

  def best_bit_slice(words, width = 32)
    best_start = 0
    best_end = 0
    best_score = -1

    (0...width).each do |start_bit|
      (start_bit...width).each do |end_bit|
        values = words.map { |w| slice_value(w, start_bit, end_bit) }.uniq
        score = values.size
        if score > best_score
          best_score = score
          best_start = start_bit
          best_end = end_bit
        end
      end
    end

    [best_start, best_end]
  end

  def build_tree(words, width = 32)
    return Node.new(instruction: words.first) if words.size == 1

    start_bit, end_bit = best_bit_slice(words, width)
    node = Node.new(bit_start: start_bit, bit_end: end_bit)

    subsets = {}
    words.each do |word|
      key = slice_value(word, start_bit, end_bit)
      subsets[key] ||= []
      subsets[key] << word
    end

    subsets.each do |key, subset|
      node.children[key] = build_tree(subset, width)
    end

    node
  end

  def print_tree(node, indent = "")
    if node.leaf?
      puts "#{indent}Leaf: #{node.instruction.name} (#{node.instruction.bin_value.to_s(2).rjust(32, '0')})"
    else
      puts "#{indent}Slice [#{node.bit_start}..#{node.bit_end}]"
      node.children.each do |value, child|
        puts "#{indent}  Value #{value}:"
        print_tree(child, indent + "    ")
      end
    end
  end

  def generate_dot(node)
    dot = ["digraph G {"]
    node_counter = 0
    node_ids = {}

    define_singleton_method(:traverse) do |n|
      nid = node_counter
      node_counter += 1
      node_ids[n] = nid

      if n.leaf?
        dot << "  node#{nid} [label=\"#{n.instruction.name}\", shape=box];"
      else
        dot << "  node#{nid} [label=\"Slice [#{n.bit_start}..#{n.bit_end}]\"];"
        n.children.each do |val, child|
          cid = traverse(child)
          dot << "  node#{nid} -> node#{cid} [label=\"#{val}\"];"
        end
      end
      nid
    end

    traverse(node)
    dot << "}"
    dot.join("\n")
  end
end