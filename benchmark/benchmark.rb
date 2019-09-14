require "tatara/tatara"
require "benchmark"
require "objspace"

NUM = 1000000

Benchmark.bm 10 do |r|
    r.report "Tatara::String" do
        NUM.times { 
            s = Tatara::String.new
            s.value = "42"
        }
    end

    puts "Tatra::String memory #{ObjectSpace.memsize_of_all(Tatara::String)}\n"

    r.report "Ruby::String" do
        NUM.times { 
            s = String.new
            s = "42"
        }
    end

    puts "Ruby::String #{ObjectSpace.memsize_of_all(String)}\n"

    r.report "Tatara::Integer" do
        NUM.times { 
            i = Tatara::Integer.new
            i.value = 42
        }
    end

    puts "Tatra::Integr memory #{ObjectSpace.memsize_of_all(Tatara::Integer)}\n"

    r.report "Ruby::Integer" do
        NUM.times { 
            i = 42
        }
    end

    puts "Ruby::Integer #{ObjectSpace.memsize_of_all(Integer)}\n"

    r.report "Tatara::Float" do
        NUM.times { 
            f = Tatara::Float.new 
            f.value = 4.2
        }
    end

    puts "Tatra::Float memory #{ObjectSpace.memsize_of_all(Tatara::Float)}\n"

    r.report "Ruby::Float" do
        NUM.times { 
            f = 4.2
        }
    end

    puts "Ruby::Float memory #{ObjectSpace.memsize_of_all(Float)}\n"

    r.report "Tatara::StringVector" do
        NUM.times { 
            vs = Tatara::StringVector.new
            vs.emplace_back("42")
        }
    end

    puts "Tatra::StringVector memory #{ObjectSpace.memsize_of_all(Tatara::StringVector)}\n"

    r.report "Ruby::Array(String)" do
        NUM.times { 
            array = Array.new
            array.push("42")
        }
    end

    puts "Ruby::Array(String) memory #{ObjectSpace.memsize_of_all(Array)}\n"

    r.report "Tatara::IntVector" do
        NUM.times { 
            vi = Tatara::IntVector.new
            vi.emplace_back(42) 
        }
    end

    puts "Tatra::IntVector memory #{ObjectSpace.memsize_of_all(Tatara::IntVector)}\n"

    r.report "Ruby::Array(Integer)" do
        NUM.times { 
            array = Array.new
            array.push(42)
        }
    end

    puts "Ruby::Array(Integer) memory #{ObjectSpace.memsize_of_all(Array)}\n"

    r.report "Tatara::FloatVector" do
        NUM.times { 
            vf = Tatara::FloatVector.new 
            vf.emplace_back(4.2)
        }
    end

    puts "Tatra::FloatVector memory #{ObjectSpace.memsize_of_all(Tatara::FloatVector)}\n"

    r.report "Ruby::Array(Float)" do
        NUM.times { 
            array = Array.new
            array.push(4.2)
        }
    end

    puts "Ruby::Array(Float) memory #{ObjectSpace.memsize_of_all(Array)}\n"
end