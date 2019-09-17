require 'benchmark_driver'

Benchmark.driver do |x|
  x.prelude <<~RUBY
    require 'tatara/tatara'
  RUBY

  x.report %{ Tatara::String.new }
  x.report %{ Tatara::Integer.new }
  x.report %{ Tatara::Float.new }
  x.report %{ Tatara::StringVector.new }
  x.report %{ Tatara::IntVector.new }
  x.report %{ Tatara::FloatVector.new }
end
