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
    end

    class IntVector
        include Vector
    end

    class FloatVector
        include Vector
    end

    class StringVector
        include Vector
    end
end