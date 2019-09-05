require "tatara/tatara"
require "benchmark"
require "objspace"

NUM = 1000000

GC.disable

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

    puts "Tatra::String memory #{ObjectSpace.memsize_of_all(Tatara::Integer)}\n"

    r.report "Ruby::Integer" do
        NUM.times { 
            i = 42
        }
    end

    puts "Ruby::String #{ObjectSpace.memsize_of_all(Integer)}\n"

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

    r.report "Tatara::Vecs" do
        NUM.times { 
            vs = Tatara::Vecs.new
            vs.emplace_back("42")
        }
    end
    r.report "Tatara::Veci" do
        NUM.times { 
            vi = Tatara::Veci.new
            vi.emplace_back(42) 
        }
    end
    r.report "Tatara::Vecf" do
        NUM.times { 
            vf = Tatara::Vecf.new 
            vf.emplace_back(4.2)
        }
    end
end