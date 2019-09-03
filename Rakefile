require "bundler/gem_tasks"
require "rake/testtask"
require "rake/extensiontask"
require "tatara/tatara"
require "benchmark"

Rake::TestTask.new(:test) do |t|
  t.libs << "test"
  t.libs << "lib"
  t.test_files = FileList["test/**/*_test.rb"]
end

task :default => :test

Rake::ExtensionTask.new "tatara" do |ext|
  ext.lib_dir = "lib/tatara"
end

NUM = 1000000

desc 'Benchmark Task'
task :benchmark do
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
end