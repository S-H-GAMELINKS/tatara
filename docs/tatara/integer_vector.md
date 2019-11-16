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

### Tatara::Intvector#duplicate

Intersection value's

```ruby
@i1 = Tatara::IntVector.new
(1..10).each{|i| @i1 << i}
@i2 = Tatara::IntVector.new
(10..20).each{|i| @i2 << i}
@i = @i1.duplicate @i2
# => [10]
```