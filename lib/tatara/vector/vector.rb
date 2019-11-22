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

        def &(other)
            self.intersection other
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

        def sum
            result = ""
            self.map{|v| result += v}
            result
        end

        def intersection(other)
            result = Tatara::StringVector.new    
            self.each{|s|
                other.each{|o|
                    if o == s
                        result << s
                    end
                }
            }
            result
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
    end
end