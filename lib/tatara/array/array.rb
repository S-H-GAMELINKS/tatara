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

        def intersection(other)
            result = Tatara::IntArray.new    
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
            return_value = Tatara::IntArray.new
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

        def uniq
            result = []
            self.map{|v| result << v}
            uniq = Tatara::IntArray.new
            result.uniq.each{|v| uniq << v}
            uniq
        end

        def uniq!
            result = []
            self.map{|v| result << v}
            self.clear
            result.uniq.each{|v| self << v}
            self
        end
    end

    class FloatArray
        include Array

        def intersection(other)
            result = Tatara::FloatArray.new    
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
            return_value = Tatara::FloatArray.new
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

        def uniq
            result = []
            self.map{|v| result << v}
            uniq = Tatara::FloatArray.new
            result.uniq.each{|v| uniq << v}
            uniq
        end

        def uniq!
            result = []
            self.map{|v| result << v}
            self.clear
            result.uniq.each{|v| self << v}
            self
        end
    end

    class StringArray
        include Array

        def intersection(other)
            result = Tatara::StringArray.new    
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
            return_value = Tatara::StringArray.new
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

        def uniq
            result = []
            self.map{|v| result << v}
            uniq = Tatara::StringArray.new
            result.uniq.each{|v| uniq << v}
            uniq
        end

        def uniq!
            result = []
            self.map{|v| result << v}
            self.clear
            result.uniq.each{|v| self << v}
            self
        end
    end
end