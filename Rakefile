require "bundler/gem_tasks"
require "rake/testtask"
require "rake/extensiontask"

Rake::TestTask.new(:test) do |t|
  t.libs << "test"
  t.libs << "lib"
  t.test_files = FileList["test/**/*_test.rb"]
end

task :default => :test

Rake::ExtensionTask.new "tatara" do |ext|
  ext.lib_dir = "lib/tatara"
end

desc 'Benchmark Task'
task :benchmark do
  system("ruby benchmark/benchmark.rb")
end