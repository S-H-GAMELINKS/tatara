require "tatara/tatara"

module Tatara
    module Array
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

        def to_json
            self.to_array.to_json
        end

        def import_json(json)
            self.import_array(JSON.parse(json))
        end
    end

    class IntArray
        include Array

        def intersection other
            self & other
        end
    end

    class FloatArray
        include Array

        def & other
            self.intersection other
        end

        def reverse
            copy = self.dup
            result = self.to_array.reverse
            result.each{|v| copy << v }
            return copy
        end
    end

    class StringArray
        include Array

        def & other
            self.intersection other
        end

        def reverse
            copy = self.dup
            result = self.to_array.reverse
            result.each{|v| copy << v }
            return copy
        end
    end
end