require "bundler/gem_tasks"
require "rake/testtask"
require "rake/extensiontask"

CLASSES = [
  "integer",
  "float",
  "string"
]

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
namespace :benchmark do
  CLASSES.map {|klass|
    task klass do
      system("bundle exec benchmark-driver benchmark/config/#{klass}.yml -o gruff")
    end
  }

  CLASSES.map {|klass|
    task "#{klass}_vector" do
      system("bundle exec benchmark-driver benchmark/config/#{klass}_vector.yml -o gruff")
    end
  }

  CLASSES.map {|klass|
    task "#{klass}_array" do
      system("bundle exec benchmark-driver benchmark/config/#{klass}_array.yml -o gruff")
    end
  }

  CLASSES.map {|key|
    CLASSES.map {|value|
      task "#{key}_#{value}_map" do
        system("bundle exec benchmark-driver benchmark/config/#{key}_#{value}_map.yml -o gruff")
      end
    }
  }
end