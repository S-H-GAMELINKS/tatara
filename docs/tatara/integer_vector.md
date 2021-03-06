# Tatara::IntVector
## About

`Tatara::IntVector` is `Vector` class like `static type programming lang`.

`Tatara::IntVector` use `Integer` value.
But, you can use `Float` for value.

```ruby
@i = Tatara::IntVector.new
@i[0] = 42
# => Set value 42 for index of 0.
@i[1] = 8.4
# => Set value 8 for index of 1.
```

But, can not use `String` for value.

```ruby
@i = Tatara::IntVector.new
@i[0] = "42"
# => Error!
```

## Methods
### Tatara::IntVector#new

Create new `Tatara::IntVector` instance.

```ruby
@i = Tatara::IntVector.new
```

### Tatara::IntVector#\[\]

Access by index.

```ruby
@i = Tatara::IntVector.new
@i[0] = 42
puts @i[0]
# => 42
```

### Tatara::IntVector#\[\]=

Set value by index.

```ruby
@i = Tatara::IntVector.new
@i[0] = 42
# => Set value 42 for index of 0.
```

### Tatara::IntVector#emplace_back

Create new value on end of `Tatara::intVector`.

```ruby
@i = Tatara::IntVector.new
@i.emplace_back(42)
# => Set value 42 on end of `Tatara::intVector`
```

### Tatara::IntVector#size

Size of `Tatara::intVector`.

```ruby
@i = Tatara::IntVector.new
puts @i.size
# => 0
@i.emplace_back(42)
puts @i.size
# => 1
```

### Tatara::IntVector#clear

Clear `Tatara::intVector`.

```ruby
@i = Tatara::IntVector.new
@i.emplace_back(42)
puts @i.size
# => 1
@i.clear
puts @i.size
# => 0
```

### Tatara::IntVector#sum

Sum value's for `Tatara::IntVector`.

```ruby
@i = Tatara::IntVector.new
(1..3).each{|i|
    @i.emplace_back(i)
}
puts @i.sum
# => 6
```

### Tatara::IntVector#operator<<

Create new value on end of `Tatara::intVector`.

```ruby
@i = Tatara::IntVector.new
@i << 42
# => Set value 42 on end of `Tatara::intVector`
```

### Tatara::IntVector#map

`map` method for `Tatara::IntVector`.  
It's likes `Array#map`

```ruby
@i = Tatara::IntVector.new
(1..3).each{|i| @i << i }
# => Set new value's
@i.map{|i|
    puts i
}
# => 1 2 3
```

### Tatara::IntVector#map!

`map!` method for `Tatara::IntVector`.  
It's likes `Array#map!`

```ruby
@i = Tatara::IntVector.new
(1..3).each{|i| @i << i }
# => Set new value's
@i.map!{|i| i * 2 }
@i.map{|i|
    puts i
}
# => 2 4 6
```

### Tatara::IntVector#each

`each` method for `Tatara::IntVector`.  
It's likes `Array#each`

```ruby
@i = Tatara::IntVector.new
(1..3).each{|i| @i << i }
# => Set new value's
@i.each{|i|
    puts i
}
# => 1 2 3
```

### Tatara::IntVector#each_with_index

`each_with_index` method for `Tatara::IntVector`.  
It's likes `Array#each_with_index`

```ruby
@i = Tatara::IntVector.new
(1..3).each{|i| @i << i }
# => Set new value's
@i.each_with_index{|v, i|
    puts "#{i}:#{v}"
}
# => 1:1 2:2 3:3
```

### Tatara::Intvector#intersection

Intersection value's

```ruby
@i1 = Tatara::IntVector.new
(1..10).each{|i| @i1 << i}
@i2 = Tatara::IntVector.new
(10..20).each{|i| @i2 << i}
@i = @i1.intersection @i2
# => [10]
```

### Tatara::Intvector#operator&

Intersection value's

```ruby
@i1 = Tatara::IntVector.new
(1..10).each{|i| @i1 << i}
@i2 = Tatara::IntVector.new
(10..20).each{|i| @i2 << i}
@i = @i1 & @i2
# => [10]
```

### Tatara::IntVector#sort

Sort value's.

```ruby
@i = Tatara::IntVector.new
[9, 1, 4].each{|i| @i << i }
@i = @i.sort
# => [1, 4, 9]
```

### Tatara::IntVector#sort!

Sort value's.

```ruby
@i = Tatara::IntVector.new
[9, 1, 4].each{|i| @i << i }
@i.sort!
# => [1, 4, 9]
```

### Tatara::IntVector#reverse

Reverse value's.

```ruby
@i = Tatara::IntVector.new
[9, 1, 4].each{|i| @i << i }
@i = @i.reverse
# => [4, 1, 9]
```

### Tatara::IntVector#reverse!

Reverse value's.

```ruby
@i = Tatara::IntVector.new
[9, 1, 4].each{|i| @i << i }
@i.reverse!
# => [4, 1, 9]
```

### Tatara::IntVector#uniq

Remove duplicate in `Tatara::IntVector`.

```ruby
@i = Tatara::IntVector.new
[1, 3, 4, 1].each{|i| @i << i}
@i = @i.uniq
# => Remove duplicate!
@i.each{|i| puts i }
# => 1, 3, 4
```

### Tatara::IntVector#uniq!

Remove destructive duplicate in `Tatara::IntVector`.

```ruby
@i = Tatara::IntVector.new
[1, 3, 4, 1].each{|i| @i << i}
@i.uniq!
# => Remove duplicate!
@i.each{|i| puts i }
# => 1, 3, 4
```

### Tatara::IntVector#slice

Slice value's' in `Tatara::IntVector`.

```ruby
@i = Tatara::IntVector.new
[1, 2, 3, 4, 5].each{|i| @i << i}
@i = @i.slice(1, 3)
# => Slice value
@i.each{|i| puts i }
# => 2, 3, 4
```

### Tatara::IntVector#slice!

Destructive Slice value's' in `Tatara::IntVector`.

```ruby
@i = Tatara::IntVector.new
[1, 2, 3, 4, 5].each{|i| @i << i}
@i.slice!(1, 3)
# => Slice value
@i.each{|i| puts i }
# => 2, 3, 4
```

### Tatara::IntVector#first

Get first value of `Tatara::IntVector`.

```ruby
@i = Tatara::IntVector.new
(1..3).each{|i| @i << i }
# => Set new value's
puts @i.first
# => 1
```

### Tatara::IntVector#last

Get last value of `Tatara::IntVector`.

```ruby
@i = Tatara::IntVector.new
(1..3).each{|i| @i << i }
# => Set new value's
puts @i.last
# => 3
```

### Tatara::IntVector#to_array

Convert to `Array` from `Tatara::IntVector`.

```ruby
@i = Tatara::IntVector.new
(1..3).each{|i| @i << i }
# => Set new value's
puts @i.to_array
# => 1, 2, 3
```

### Tatara::IntVector#to_json

Convert to `JSON` from `Tatara::IntVector`.

```ruby
@i = Tatara::IntArray.new
(1..3).each{|i| @i << i}
# => Set new value's
puts @i.to_json
# => Convert to JSON
```

### Tatara::IntVector#import_array

Import to `Array` from `Tatara::IntVector`.

```ruby
@i = Tatara::IntArray.new
@i.import_array [1, 2, 3]
# => Set new value's
```

### Tatara::IntVector#import_json

Import to `JSON` from `Tatara::IntVector`.

```ruby
@i = Tatara::IntVector.new
@i.import_json "[1, 2, 3]"
# => Set new value's [1, 2, 3]
```