require 'tatara/tatara'

module Tatara
    class StringVector
        def map(&block)
            (0...(self.size)).each_with_index{|v, i| block.call(v)}
        end
    end
end