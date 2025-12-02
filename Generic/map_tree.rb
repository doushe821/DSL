module MapTree

  Node = Struct.new(:bit_indexes, :width, :nodes)
  class TreeNode
    attr_accessor :value, :children, :parent

    def initialize(value = nil)
      @value = value
      @children = {}
      @parent = nil
    end

    def add_child(key, child_node)
      @children[key] = child_node
      child_node.parent = self
    end

    def get_child(key)
      @children[key]
    end

    def has_child?(key)
      @children.key?(key)
    end
  end

  class Tree
    attr_accessor :root

    def initialize(root_value = nil)
      @root = root_value ? TreeNode.new(root_value) : nil
    end

    def search(target_value, start_node = @root)
      return nil if start_node.nil?
      
      return start_node if start_node.value == target_value
      
      start_node.children.each do |key, child|
        result = search(target_value, child)
        return result if result
      end
      
      nil
    end

    def search_by_path(path_keys)
      current = @root
      return nil if current.nil?
      
      path_keys.each do |key|
        current = current.get_child(key)
        return nil if current.nil?
      end
      
      current
    end

    def dump_text(node = @root, level = 0, output = [])
      return output if node.nil?
      
      indent = "  " * level
      output << "#{indent}#{node.value} (Children: #{node.children.keys.join(', ')})"
      
      node.children.each do |key, child|
        dump_text(child, level + 1, output)
      end
      
      output
    end

    def add_node_at_path(path_keys, value)
      current = @root
      return nil if current.nil? || path_keys.empty?
      
      (0...path_keys.length - 1).each do |i|
        key = path_keys[i]
        current = current.get_child(key)
        return nil if current.nil?
      end
      
      new_node = TreeNode.new(value)
      parent_key = path_keys.last
      current.add_child(parent_key, new_node)
      new_node
    end

    def insert_child(parent_node, key, value)
      new_node = TreeNode.new(value)
      parent_node.add_child(key, new_node)
      new_node
    end

    def path_to_node(node)
      path = []
      current = node
      
      while current && current != @root
        parent = current.parent
        key = parent.children.key(current)
        path.unshift(key)
        current = parent
      end
      
      path.unshift(nil) if current == @root  # Mark root
      path
    end
  end
end