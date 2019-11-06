require 'tatara/tatara'

module Tatara
    class StringArray
        def map(&block)
            (0...(self.size)).each{|i| block.call(self[i])}
        end
    end
end