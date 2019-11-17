# Tatara
## About

Tatara is simply Type support gem. Developed by C++/Rice(create Ruby Extension for C++).

Provide a simply type & container for your Ruby Code!

[View Source in GitHub!](https://github.com/S-H-GAMELINKS/tatara)

## Getting Started
### Rails and other Project 
Using Your Project, add `tatara` in your Gemfile.

```ruby:Gemfile
gem 'tatara'
```

And run `bundle` command.

```bash
bundle
```

So, you can use this code!

```ruby
require 'tatara'

@int_container = Tatara::IntVector.new

(1..10).each{|i| @int_container << i}
# Insert 1..10 to @int_container

@int_container.map{|i|
    puts i
    # 1..10 value is shown
}
```

### Install Yourself

Run `gem install tatara`.

```bash
gem install tatara
```

So, you can use this code!

```ruby
require 'tatara'

@int_container = Tatara::IntVector.new

(1..10).each{|i| @int_container << i}
# Insert 1..10 to @int_container

@int_container.map{|i|
    puts i
    # 1..10 value is shown
}
```

## Class List

### [Tatara::Integer](./tatara/integer.md)

### [Tatara::Float](./tatara/float.md)

### [Tatara::String](./tatara/string.md)

### [Tatara::IntVector](./tatara/integer_vector.md)

### [Tatara::FloatVector](./tatara/float_vector.md)

### [Tatara::StringArray](./tatara/string_array.md)]

### [Tatara::StringVector](./tatara/string_vector.md)

### [Tatara::IntArray](./tatara/integer_array.md)

### [Tatara::FloatArray](./tatara/float_array.md)

### [Tatara::StringIntMap](./tatara/string_int_map.md)

### [Tatara::StringFloatMap](./tatara/string_float_map.md)

### [Tatara::StringStringMap](./tatara/string_string_map.md)

### [Tatara::IntIntMap](./tatara/integer_integer_map.md)

### [Tatara::FloatIntMap](./tatara/float_integer_map.md)

### [Tatara::FloatFloatMap](./tatara/float_float_map.md)