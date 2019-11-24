require "tatara/tatara"

module Tatara
    module Vector
        def map(&block)
            (0...(self.size)).each{|i| block.call(self[i])}
        end

        def map!(&block)
            (0...(self.size)).each{|i| self[i] = block.call(self[i]) }
        end
        
        def each(&block)
            (0...(self.size)).each{|i| block.call(self[i])}
        end

        def each_with_index(&block)
            (0...(self.size)).each{|i| block.call(self[i], i)}
        end

        def intersection(other, var)
            @result = self.to_array & other.to_array
            @result.map(&var.method(:<<))
            return var
        end

        def &(other)
            self.intersection other
        end

        def sum
            self.to_array.inject(:+)
        end

        def uniq
            @result = self.to_array.uniq
        end

        def uniq!
            result = self.to_array
            self.clear
            result.each{|v| self << v}
            return self
        end

        def to_array
            result = []
            self.map{|v| result << v}
            result
        end
    end

    class IntVector
        include Vector

        def intersection(other)
            super(other, Tatara::IntVector.new)
        end

        def sort
            result = []
            self.each{|s| result << s}
            result.sort!
            return_value = Tatara::IntVector.new
            result.each{|r| return_value << r}
            return_value
        end

        def sort!
            result = []
            self.each{|s| result << s}
            result.sort!
            result.each_with_index{|r, i| self[i] = r}
            self
        end

        def reverse
            result = []
            self.each{|s| result << s}
            result.reverse!
            return_value = Tatara::IntVector.new
            result.each{|r| return_value << r}
            return_value
        end

        def reverse!
            result = []
            self.each{|s| result << s }
            result.reverse!
            result.each_with_index{|r, i| self[i] = r}
            self
        end

        def uniq
            super
            uniq = Tatara::IntVector.new
            @result.each{|v| uniq << v}
            return uniq
        end
    end

    class FloatVector
        include Vector

        def intersection(other)
            super(other, Tatara::FloatVector.new)
        end

        def sort
            result = []
            self.each{|s| result << s}
            result.sort!
            return_value = Tatara::FloatVector.new
            result.each{|r| return_value << r}
            return_value
        end

        def sort!
            result = []
            self.each{|s| result << s}
            result.sort!
            result.each_with_index{|r, i| self[i] = r}
            self
        end

        def reverse
            result = []
            self.each{|s| result << s}
            result.reverse!
            return_value = Tatara::FloatVector.new
            result.each{|r| return_value << r}
            return_value
        end

        def reverse!
            result = []
            self.each{|s| result << s }
            result.reverse!
            result.each_with_index{|r, i| self[i] = r}
            self
        end

        def uniq
            super
            uniq = Tatara::FloatVector.new
            @result.each{|v| uniq << v}
            return uniq
        end
    end

    class StringVector
        include Vector

        def intersection(other)
            super(other, Tatara::StringVector.new)
        end

        def sort
            result = []
            self.each{|s| result << s}
            result.sort!
            return_value = Tatara::StringVector.new
            result.each{|r| return_value << r}
            return_value
        end

        def sort!
            result = []
            self.each{|s| result << s}
            result.sort!
            result.each_with_index{|r, i| self[i] = r}
            self
        end

        def reverse
            result = []
            self.each{|s| result << s}
            result.reverse!
            return_value = Tatara::StringVector.new
            result.each{|r| return_value << r}
            return_value
        end

        def reverse!
            result = []
            self.each{|s| result << s }
            result.reverse!
            result.each_with_index{|r, i| self[i] = r}
            self
        end

        def uniq
            super
            uniq = Tatara::StringVector.new
            @result.each{|v| uniq << v}
            return uniq
        end
    end
end