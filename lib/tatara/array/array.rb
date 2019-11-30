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

        def reverse
            copy = self.dup
            result = self.to_array.reverse
            result.each{|v| copy << v }
            return copy
        end

        def reverse!
            result = self.to_array.reverse
            self.clear
            result.each{|v| self << v }
            return self
        end

        def slice(start, length)
            copy = self.dup
            result = self.to_array.slice(start, length)
            copy.clear
            result.each{|v| copy << v }
            return copy
        end

        def slice!(start, length)
            result = self.to_array.slice(start, length)
            self.clear
            result.each{|v| self << v }
            return self
        end

        def to_array
            result = []
            self.map{|v| result << v}
            result
        end

        def to_json
            self.to_array.to_json
        end

        def import_array(data)
            data.each(&self.method(:<<))
        end

        def import_json(json)
            self.import_array(JSON.parse(json))
        end
    end

    class IntArray
        include Array
    end

    class FloatArray
        include Array
    end

    class StringArray
        include Array
    end
end