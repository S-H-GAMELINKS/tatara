# Tatara::IntArray
## About

`Tatara::IntArray` is `Array` class like `static type programming lang`.

`Tatara::IntArray` use `Integer` value.
But, you can use `Float` for value.

```ruby
@i = Tatara::IntArray.new
@i[0] = 42
# => Set value 42 for index of 0.
@i[1] = 8.4
# => Set value 8 for index of 1.
```

But, can not use `String` for value.

```ruby
@i = Tatara::IntArray.new
@i[0] = "42"
# => Error!
```

## Methods
### Tatara::IntArray#new

Create new `Tatara::IntArray` instance.

```ruby
@i = Tatara::IntArray.new
```

### Tatara::IntArray#\[\]

Access by index.

```ruby
@i = Tatara::IntArray.new
@i[0] = 42
puts @i[0]
# => 42
```


### Tatara::IntArray#\[\]=

Set value by index.

```ruby
@i = Tatara::IntArray.new
@i[0] = 42
# => Set value 42 for index of 0.
```

### Tatara::IntArray#push

Create new value on end of `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
@i.push(42)
# => Set value 42 on end of `Tatara::IntArray`
```

### Tatara::IntArray#size

Size of `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
puts @i.size
# => 0
@i.push(42)
puts @i.size
# => 1
```

### Tatara::IntArray#clear

Clear `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
@i.push(42)
puts @i.size
# => 1
@i.clear
puts @i.size
# => 0
```

### Tatara::IntArray#operator<<

Create new value on end of `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
@i << 42
# => Set value 42 on end of `Tatara::IntArray`
```

### Tatara::IntArray#map

`map` method for `Tatara::IntArray`.  
It's likes `Array#map`

```ruby
@i = Tatara::IntArray.new
(1..3).each{|i| @i << i }
# => Set new value's
@i.map{|i|
    puts i
}
# => 1 2 3
```

### Tatara::IntArray#map!

`map!` method for `Tatara::IntArray`.  
It's likes `Array#map!`

```ruby
@i = Tatara::IntArray.new
(1..3).each{|i| @i << i }
# => Set new value's
@i.map!{|i| i * 2 }
@i.map{|i|
    puts i
}
# => 2 4 6
```

### Tatara::IntArray#each

`each` method for `Tatara::IntArray`.  
It's likes `Array#each`

```ruby
@i = Tatara::IntArray.new
(1..3).each{|i| @i << i }
# => Set new value's
@i.each{|i|
    puts i
}
# => 1 2 3
```

### Tatara::IntArray#each_with_index

`each_with_index` method for `Tatara::IntArray`.  
It's likes `Array#each_with_index`

```ruby
@i = Tatara::IntArray.new
(1..3).each{|i| @i << i }
# => Set new value's
@i.each_with_index{|v, i|
    puts "#{i}:#{v}"
}
# => 1:1 2:2 3:3
```

### Tatara::IntArray#intersection

Intersection value's

```ruby
@i1 = Tatara::IntArray.new
(1..10).each{|i| @i1 << i}
@i2 = Tatara::IntArray.new
(10..20).each{|i| @i2 << i}
@i = @i1.intersection @i2
# => [10]
```

### Tatara::IntArray#operator&

Intersection value's

```ruby
@i1 = Tatara::IntArray.new
(1..10).each{|i| @i1 << i}
@i2 = Tatara::IntArray.new
(10..20).each{|i| @i2 << i}
@i = @i1 & @i2
# => [10]
```

### Tatara::IntArray#sort

Sort value's.

```ruby
@i = Tatara::IntArray.new
[9, 1, 4].each{|i| @ << i }
@i = @i.sort
# => [1, 4, 9]
```

### Tatara::IntArray#sort!

Sort value's.

```ruby
@i = Tatara::IntArray.new
[9, 1, 4].each{|i| @ << i }
@i.sort!
# => [1, 4, 9]
```

### Tatara::IntArray#reverse

Reverse value's.

```ruby
@i = Tatara::IntArray.new
[9, 1, 4].each{|i| @i << i }
@i = @i.reverse
# => [4, 1, 9]
```

### Tatara::IntArray#reverse!

Reverse value's.

```ruby
@i = Tatara::IntArray.new
[9, 1, 4].each{|i| @i << i }
@i.reverse!
# => [4, 1, 9]
```

### Tatara::IntArray#uniq

Remove duplicate in `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
[1, 3, 4, 1].each{|i| @i << i}
@i = @i.uniq
# => Remove duplicate!
@i.each{|i| puts i }
# => 1, 3, 4
```

### Tatara::IntArray#uniq!

Remove destructive duplicate in `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
[1, 3, 4, 1].each{|i| @i << i}
@i.uniq!
# => Remove duplicate!
@i.each{|i| puts i }
# => 1, 3, 4
```

### Tatara::IntArray#slice

Slice value's' in `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
[1, 2, 3, 4, 5].each{|i| @i << i}
@i = @i.slice(1, 3)
# => Slice value
@i.each{|i| puts i }
# => 2, 3, 4
```

### Tatara::IntArray#slice!

Destructive Slice value's' in `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
[1, 2, 3, 4, 5].each{|i| @i << i}
@i.slice!(1, 3)
# => Slice value
@i.each{|i| puts i }
# => 2, 3, 4
```

### Tatara::IntArray#first

Get first value of `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
(1..3).each{|i| @i << i }
# => Set new value's
puts @i.first
# => 1
```

### Tatara::IntArray#last

Get last value of `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
(1..3).each{|i| @i << i }
# => Set new value's
puts @i.last
# => 3
```

### Tatara::IntArray#to_array

Convert to `Array` from `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
(1..3).each{|i| @i << i }
# => Set new value's
puts @i.to_array
# => 1, 2, 3
```

### Tatara::IntArray#to_json

Convert to `JSON` from `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
(1..3).each{|i| @i << i }
# => Set new value's
puts @i.to_json
# => Convert to JSON
```

### Tatara::IntArray#import_array

Import to `Array` from `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
@i.import_array [1, 2, 3]
# => Set new value's [1, 2, 3]
```

### Tatara::IntArray#import_json

Import to `JSON` for `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
@i.import_json "[1, 2, 3]"
# => Set new value's [1, 2, 3]
```