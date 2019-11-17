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

        def &(other)
            self.intersection other
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