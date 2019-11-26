# Tatara::StringVector
## About

`Tatara::StringVector` is `Vector` class like `static type programming lang`.

`Tatara::StringVector` use `String` value.
But, you can not use `Integer` & `Float` for value.

```ruby
@s = Tatara::StringVector.new
@s[0] = "42"
# => Set value "42" for index of 0.
@s[1] = "8.4"
# => Set value "8.4" for index of 1.
```

But, can not use `Integer` & `Float` for value.

```ruby
@s = Tatara::StringVector.new
@s[0] = 42
# => Error!
```


## Methods
### Tatara::StringVector#new

Create new `Tatara::StringVector` instance.

```ruby
@s = Tatara::StringVector.new
```

### Tatara::StringVector#\[\]

Access by index.

```ruby
@s = Tatara::StringVector.new
@s[0] = "42"
puts @s[0]
# => "42"
```

### Tatara::StringVector#\[\]=

Set value by index.

```ruby
@s = Tatara::StringVector.new
@s[0] = "42"
# => Set value "42" for index of 0.
```

### Tatara::StringVector#emplace_back

Create new value on end of `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
@s.emplace_back("42")
# => Set value "42" on end of `Tatara::StringVector`
```

### Tatara::StringVector#size

Size of `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
puts @s.size
# => 0
@s.emplace_back("42")
puts @s.size
# => 1
```

### Tatara::StringVector#clear

Clear `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
@s.emplace_back("42")
puts @s.size
# => 1
@s.clear
puts @s.size
# => 0
```

### Tatara::StringVector#sum

Sum value's for `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
("A".."C").each{|s|
    @s.emplace_back(s)
}
puts @s.sum
# => "ABC"
```

### Tatara::StringVector#operator<<

Create new value on end of `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
@s << "42"
# => Set value "42" on end of `Tatara::StringVector`
```

### Tatara::StringVector#map

`map` method for `Tatara::StringVector`.  
It's likes `Array#map`

```ruby
@s = Tatara::StringVector.new
("A".."C").each{|s| @s << s }
# => Set new value's
@s.map{|s|
    puts s
}
# => A B C
```

### Tatara::StringVector#map!

`map!` method for `Tatara::StringVector`.  
It's likes `Array#map!`

```ruby
@s = Tatara::StringVector.new
("A".."C").each{|s| @s << s }
# => Set new value's
@s.map!{|s| s.succ }
@s.map{|s|
    puts s
}
# => B C D
```

### Tatara::StringVector#each

`each` method for `Tatara::StringVector`.  
It's likes `Array#each`

```ruby
@s = Tatara::StringVector.new
("A".."C").each{|s| @s << s }
# => Set new value's
@s.each{|s|
    puts s
}
# => A B C
```


### Tatara::StringVector#each_with_index

`each_with_index` method for `Tatara::StringVector`.  
It's likes `Array#each_with_index`

```ruby
@s = Tatara::StringVector.new
("A".."C").each{|s| @s << s }
# => Set new value's
@s.each_with_index{|v, i|
    puts "#{i}:#{v}"
}
# => 1:A 2:B 3:C
```

### Tatara::Stringvector#intersection

Intersection value's

```ruby
@s1 = Tatara::StringVector.new
("A".."C").each{|s| @s1 << s}
@s2 = Tatara::StringVector.new
("C".."F").each{|s| @s2 << s}
@s = @s1.intersection @s2
# => ["C"]
```

### Tatara::StringVector#operator&

Intersection value's

```ruby
@s1 = Tatara::StringVector.new
("A".."C").each{|s| @s1 << s}
@s2 = Tatara::StringVector.new
("C".."F").each{|s| @s2 << s}
@s = @s1 & @s2
# => ["C"]
```

### Tatara::StringVector#sort

Sort value's.

```ruby
@s = Tatara::StringVector.new
["9", "1", "4"].each{|s| @s << s }
@s = @s.sort
# => ["1", "4", "9"]
```

### Tatara::StringVector#sort!

Sort value's.

```ruby
@s = Tatara::StringVector.new
["9", "1", "4"].each{|s| @s << s }
@s.sort!
# => ["1", "4", "9"]
```

### Tatara::StringVector#reverse

Reverse value's.

```ruby
@s = Tatara::StringVector.new
["9", "1", "4"].each{|s| @s << s }
@s = @s.reverse
# => ["4", "1", "9"]
```

### Tatara::StringVector#reverse!

Reverse value's.

```ruby
@s = Tatara::StringVector.new
["9", "1", "4"].each{|s| @s << s }
@s.reverse!
# => ["4", "1", "9"]
```

### Tatara::StringVector#uniq

Remove duplicate in `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
["1", "3", "4", "1"].each{|s| @s << s }
@s = @s.uniq
# => Remove duplicate!
@s.each{|s| puts s }
# => 1, 3, 4
```

### Tatara::StringVector#uniq!

Remove destructive duplicate in `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
["1", "3", "4", "1"].each{|s| @s << s }
@s.uniq!
# => Remove duplicate!
@s.each{|s| puts s }
# => 1, 3, 4
```

### Tatara::StringVector#slice

Slice value's' in `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
["1", "2", "3", "4", "5"].each{|s| @s << s}
@s = @s.slice(1, 3)
# => Slice value
@s.each{|s| puts s }
# => 2, 3, 4
```


### Tatara::StringVector#first

Get first value of `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
("A".."C").each{|s| @s << s }
# => Set new value's
puts @s.first
# => A
```

### Tatara::StringVector#last

Get last value of `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
("A".."C").each{|s| @s << s }
# => Set new value's
puts @s.last
# => "C"
```

### Tatara::StringVector#to_array

Convert to `Array` from `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
("A".."C").each{|s| @s << s }
# => Set new value's
puts @s.to_array
# => A, B, C
```