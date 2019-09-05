require "tatara/tatara"
require "benchmark"

NUM = 1000000

Benchmark.bm 10 do |r|
    r.report "Tatara::String" do
        NUM.times { 
            s = Tatara::String.new
            s.value = "42"
        }
    end
    r.report "Tatara::Integer" do
        NUM.times { 
            i = Tatara::Integer.new
            i.value = 42
        }
    end
    r.report "Tatara::Float" do
        NUM.times { 
            f = Tatara::Float.new 
            f.value = 4.2
        }
    end
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