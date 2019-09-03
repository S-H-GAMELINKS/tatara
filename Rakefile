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
      NUM.times { Tatara::String.new }
    end
    r.report "Tatara::Integer" do
      NUM.times { Tatara::Integer.new }
    end
    r.report "Tatara::Float" do
      NUM.times { Tatara::Float.new }
    end
    r.report "Tatara::Vecs" do
      NUM.times { Tatara::Vecs.new }
    end
    r.report "Tatara::Veci" do
      NUM.times { Tatara::Veci.new }
    end
    r.report "Tatara::Vecf" do
      NUM.times { Tatara::Vecf.new }
    end
  end
end