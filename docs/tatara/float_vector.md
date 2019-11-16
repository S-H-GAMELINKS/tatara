# Tatara::FloatVector
## About

`Tatara::FloatVector` is `Vector` class like `static type programming lang`.

`Tatara::FloatVector` use `Float` value.
But, you can use `Integer` for value.

```ruby
@f = Tatara::FloatVector.new
@f[0] = 4.2
# => Set value 4.2 for index of 0.
@f[1] = 8
# => Set value 8.0 for index of 1.
```

But, can not use `String` for value.

```ruby
@f = Tatara::FloatVector.new
@f[0] = "42"
# => Error!
```

## Methods
### Tatara::FloatVector#new

Create new `Tatara::FloatVector` instance.

```ruby
@f = Tatara::FloatVector.new
```


### Tatara::FloatVector#\[\]

Access by index.

```ruby
@f = Tatara::FloatVector.new
@f[0] = 4.2
puts @i[0]
# => 4.2
```

### Tatara::FloatVector#\[\]=

Set value by index.

```ruby
@f = Tatara::FloatVector.new
@f[0] = 4.2
# => Set value 4.2 for index of 0.
```

### Tatara::FloatVector#emplace_back

Create new value on end of `Tatara::FloatVector`.

```ruby
@f = Tatara::FloatVector.new
@f.emplace_back(4.2)
# => Set value 4.2 on end of `Tatara::intVector`
```

### Tatara::FloatVector#size

Size of `Tatara::FloatVector`.

```ruby
@f = Tatara::FloatVector.new
puts @f.size
# => 0
@f.emplace_back(4.2)
puts @f.size
# => 1
```

### Tatara::FloatVector#clear

Clear `Tatara::FloatVector`.

```ruby
@f = Tatara::FloatVector.new
@f.emplace_back(4.2)
puts @f.size
# => 1
@f.clear
puts @f.size
# => 0
```

### Tatara::FloatVector#sum

Sum value's for `Tatara::FloatVector`.

```ruby
@f = Tatara::FloatVector.new
(1..3).each{|i|
    @f.emplace_back(i)
}
puts @f.sum
# => 6.0
```

### Tatara::FloatVector#operator<<

Create new value on end of `Tatara::FloatVector`.

```ruby
@f = Tatara::FloatVector.new
@f << 4.2
# => Set value 4.2 on end of `Tatara::FloatVector`
```

### Tatara::FloatVector#map

`map` method for `Tatara::FloatVector`.  
It's likes `Array#map`

```ruby
@f = Tatara::FloatVector.new
(1..3).each{|i| @f << i }
# => Set new value's
@i.map{|f|
    puts f
}
# => 1.0 2.0 3.0
```

### Tatara::FloatVector#map!

`map!` method for `Tatara::FloatVector`.  
It's likes `Array#map!`

```ruby
@f = Tatara::FloatVector.new
(1..3).each{|i| @f << i }
# => Set new value's
@f.map!{|f| f * 2.0 }
@f.map{|f|
    puts i
}
# => 2.0 4.0 6.0
```