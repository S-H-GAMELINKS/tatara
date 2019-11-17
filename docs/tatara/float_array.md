# Tatara::FloatArray
## About

`Tatara::FloatArray` is `Vector` class like `static type programming lang`.

`Tatara::FloatArray` use `Float` value.
But, you can use `Integer` for value.

```ruby
@f = Tatara::FloatArray.new
@f[0] = 4.2
# => Set value 4.2 for index of 0.
@f[1] = 8
# => Set value 8.0 for index of 1.
```

But, can not use `String` for value.

```ruby
@f = Tatara::FloatArray.new
@f[0] = "42"
# => Error!
```

## Methods
### Tatara::FloatArray#new

Create new `Tatara::FloatArray` instance.

```ruby
@f = Tatara::FloatArray.new
```

### Tatara::FloatArray#\[\]

Access by index.

```ruby
@f = Tatara::FloatArray.new
@f[0] = 4.2
puts @i[0]
# => 4.2
```

### Tatara::FloatArray#\[\]=

Set value by index.

```ruby
@f = Tatara::FloatArray.new
@f[0] = 4.2
# => Set value 4.2 for index of 0.
```

### Tatara::FloatArray#push

Create new value on end of `Tatara::FloatArray`.

```ruby
@f = Tatara::FloatArray.new
@f.push(4.2)
# => Set value 4.2 on end of `Tatara::FloatArray`
```

### Tatara::FloatArray#size

Size of `Tatara::FloatArray`.

```ruby
@f = Tatara::FloatArray.new
puts @f.size
# => 0
@f.push(4.2)
puts @f.size
# => 1
```

### Tatara::FloatArray#clear

Clear `Tatara::FloatArray`.

```ruby
@f = Tatara::FloatArray.new
@f.push(4.2)
puts @f.size
# => 1
@f.clear
puts @f.size
# => 0
```

### Tatara::FloatArray#operator<<

Create new value on end of `Tatara::FloatArray`.

```ruby
@f = Tatara::FloatArray.new
@f << 4.2
# => Set value 4.2 on end of `Tatara::FloatArray`
```

### Tatara::FloatArray#map

`map` method for `Tatara::FloatArray`.  
It's likes `Array#map`

```ruby
@f = Tatara::FloatArray.new
(1..3).each{|i| @f << i }
# => Set new value's
@f.map{|f|
    puts f
}
# => 1.0 2.0 3.0
```

### Tatara::FloatArray#map!

`map!` method for `Tatara::FloatArray`.  
It's likes `Array#map!`

```ruby
@f = Tatara::FloatArray.new
(1..3).each{|i| @f << i }
# => Set new value's
@f.map!{|f| f * 2.0 }
@f.map{|f|
    puts i
}
# => 2.0 4.0 6.0
```

### Tatara::FloatArray#each

`each` method for `Tatara::FloatArray`.  
It's likes `Array#each`

```ruby
@f = Tatara::FloatArray.new
(1..3).each{|i| @f << i }
# => Set new value's
@f.each{|f|
    puts f
}
# => 1.0 2.0 3.0
```

### Tatara::FloatArray#each_with_index

`each_with_index` method for `Tatara::FloatArray`.  
It's likes `Array#each_with_index`

```ruby
@f = Tatara::FloatArray.new
(1..3).each{|i| @f << i }
# => Set new value's
@i.each_with_index{|v, i|
    puts "#{i}:#{v}"
}
# => 1:1.0 2:2.0 3:3.0
```

### Tatara::FloatArray#intersection

Intersection value's

```ruby
@f1 = Tatara::FloatArray.new
(1..10).each{|i| @f1 << i}
@f2 = Tatara::FloatArray.new
(10..20).each{|i| @f2 << i}
@f = @f1.intersection @f2
# => [10.0]
```

### Tatara::FloatArray#operator&

Intersection value's

```ruby
@f1 = Tatara::FloatArray.new
(1..10).each{|i| @f1 << i}
@f2 = Tatara::FloatArray.new
(10..20).each{|i| @f2 << i}
@f = @f1 & @f2
# => [10.0]
```

### Tatara::FloatArray#sort

Sort value's.

```ruby
@f = Tatara::FloatArray.new
[9, 1, 4].each{|i| @f << i }
@f = @f.sort
# => [1.0, 4.0, 9.0]
```

### Tatara::FloatArray#sort!

Sort value's.

```ruby
@f = Tatara::FloatArray.new
[9, 1, 4].each{|i| @f << i }
@f.sort!
# => [1.0, 4.0, 9.0]
```

### Tatara::FloatArray#first

Get first value of `Tatara::FloatArray`.

```ruby
@f = Tatara::FloatArray.new
(1..3).each{|i| @f << i }
# => Set new value's
puts @f.first
# => 1.0
```

### Tatara::FloatArray#last

Get last value of `Tatara::FloatArray`.

```ruby
@f = Tatara::FloatArray.new
(1..3).each{|i| @f << i }
# => Set new value's
puts @f.last
# => 3.0
```