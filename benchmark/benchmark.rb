require 'benchmark_driver'

Benchmark.driver do |x|
  x.prelude <<~RUBY
    require 'tatara/tatara'
  RUBY

  x.report %{ Tatara::Integer.new }
  x.report %{ Tatara::Float.new }
  x.report %{ Tatara::String.new }
  x.report %{ Tatara::IntVector.new }
  x.report %{ Tatara::FloatVector.new }
  x.report %{ Tatara::StringVector.new }
  x.report %{ Tatara::IntArray.new }
  x.report %{ Tatara::FloatArray.new }
  x.report %{ Tatara::StringArray.new }
  x.report %{ Tatara::StringIntMap.new }
  x.report %{ Tatara::StringFloatMap.new }
  x.report %{ Tatara::StringStringMap.new }
  x.report %{ Tatara::IntIntMap.new }
  x.report %{ Tatara::IntFloatMap.new }
  x.report %{ Tatara::IntStringMap.new }
  x.report %{ Tatara::FloatIntMap.new }
  x.report %{ Tatara::FloatFloatMap.new }
  x.report %{ Tatara::FloatStringMap.new }  
end
