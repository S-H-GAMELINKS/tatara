require "tatara/tatara"

module Tatara
    module Array
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

        def intersection(other)
            copy = self.dup
            result = self.to_array & other.to_array
            copy.clear
            result.map(&copy.method(:<<))
            return copy
        end

        def &(other)
            self.intersection other
        end

        def sort
            copy = self.dup
            result = self.to_array.sort
            copy.clear
            result.each{|v| copy << v}
            return copy
        end

        def sort!
            result = self.to_array.sort
            self.clear
            result.each{|v| self << v}
            return self
        end

        def uniq
            copy = self.dup
            result = self.to_array.uniq
            copy.clear
            result.map(&copy.method(:<<))
            return copy
        end

        def uniq!
            result = self.to_array.uniq
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

    class IntArray
        include Array

        def reverse
            result = []
            self.each{|s| result << s}
            result.reverse!
            return_value = Tatara::IntArray.new
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
    end

    class FloatArray
        include Array

        def reverse
            result = []
            self.each{|s| result << s}
            result.reverse!
            return_value = Tatara::FloatArray.new
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
    end

    class StringArray
        include Array

        def reverse
            result = []
            self.each{|s| result << s}
            result.reverse!
            return_value = Tatara::StringArray.new
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
    end
end