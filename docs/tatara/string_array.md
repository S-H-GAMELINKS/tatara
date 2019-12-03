# Tatara::StringArray
## About

`Tatara::StringArray` is `Array` class like `static type programming lang`.

`Tatara::StringArray` use `String` value.
But, you can not use `Integer` & `Float` for value.

```ruby
@s = Tatara::StringArray.new
@s[0] = "42"
# => Set value "42" for index of 0.
@s[1] = "8.4"
# => Set value "8.4" for index of 1.
```

But, can not use `Integer` & `Float` for value.

```ruby
@s = Tatara::StringArray.new
@s[0] = 42
# => Error!
```

## Methods
### Tatara::StringArray#new

Create new `Tatara::StringArray` instance.

```ruby
@s = Tatara::StringArray.new
```

### Tatara::StringArray#\[\]

Access by index.

```ruby
@s = Tatara::StringArray.new
@s[0] = "42"
puts @s[0]
# => "42"
```

### Tatara::StringArray#\[\]=

Set value by index.

```ruby
@s = Tatara::StringArray.new
@s[0] = "42"
# => Set value "42" for index of 0.
```

### Tatara::StringArray#push

Create new value on end of `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
@s.push("42")
# => Set value "42" on end of `Tatara::StringArray`
```

### Tatara::StringArray#size

Size of `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
puts @s.size
# => 0
@s.push("42")
puts @s.size
# => 1
```

### Tatara::StringArray#clear

Clear `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
@s.push("42")
puts @s.size
# => 1
@s.clear
puts @s.size
# => 0
```
### Tatara::StringArray#operator<<

Create new value on end of `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
@s << "42"
# => Set value "42" on end of `Tatara::StringArray`
```

### Tatara::StringArray#map

`map` method for `Tatara::StringArray`.  
It's likes `Array#map`

```ruby
@s = Tatara::StringArray.new
("A".."C").each{|s| @s << s }
# => Set new value's
@s.map{|s|
    puts s
}
# => A B C
```

### Tatara::StringArray#map!

`map!` method for `Tatara::StringArray`.  
It's likes `Array#map!`

```ruby
@s = Tatara::StringArray.new
("A".."C").each{|s| @s << s }
# => Set new value's
@s.map!{|s| s.succ }
@s.map{|s|
    puts s
}
# => B C D
```

### Tatara::StringArray#each

`each` method for `Tatara::StringArray`.  
It's likes `Array#each`

```ruby
@s = Tatara::StringArray.new
("A".."C").each{|s| @s << s }
# => Set new value's
@s.each{|s|
    puts s
}
# => A B C
```

### Tatara::StringArray#each_with_index

`each_with_index` method for `Tatara::StringArray`.  
It's likes `Array#each_with_index`

```ruby
@s = Tatara::StringArray.new
("A".."C").each{|s| @s << s }
# => Set new value's
@s.each_with_index{|v, i|
    puts "#{i}:#{v}"
}
# => 1:A 2:B 3:C
```

### Tatara::StringArrayr#intersection

Intersection value's

```ruby
@s1 = Tatara::StringArray.new
("A".."C").each{|s| @s1 << s}
@s2 = Tatara::StringArray.new
("C".."F").each{|s| @s2 << s}
@s = @s1.intersection @s2
# => ["C"]
```

### Tatara::StringArray#operator&

Intersection value's

```ruby
@s1 = Tatara::StringArray.new
("A".."C").each{|s| @s1 << s}
@s2 = Tatara::StringArray.new
("C".."F").each{|s| @s2 << s}
@s = @s1 & @s2
# => ["C"]
```

### Tatara::StringArray#sort

Sort value's.

```ruby
@s = Tatara::StringArray.new
["9", "1", "4"].each{|s| @s << s }
@s = @s.sort
# => ["1", "4", "9"]
```

### Tatara::StringArray#sort!

Sort value's.

```ruby
@s = Tatara::StringArray.new
["9", "1", "4"].each{|s| @s << s }
@s.sort!
# => ["1", "4", "9"]
```

### Tatara::StringArray#reverse

Reverse value's.

```ruby
@s = Tatara::StringArray.new
["9", "1", "4"].each{|s| @s << s }
@s = @s.reverse
# => ["4", "1", "9"]
```

### Tatara::StringArray#reverse!

Reverse value's.

```ruby
@s = Tatara::StringArray.new
["9", "1", "4"].each{|s| @s << s }
@s.reverse!
# => ["4", "1", "9"]
```

### Tatara::StringArray#uniq

Remove duplicate in `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
["1", "3", "4", "1"].each{|s| @s << s }
@s = @s.uniq
# => Remove duplicate!
@s.each{|s| puts s }
# => 1, 3, 4
```

### Tatara::StringArray#uniq!

Remove destructive duplicate in `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
["1", "3", "4", "1"].each{|s| @s << s }
@s.uniq!
# => Remove duplicate!
@s.each{|s| puts s }
# => 1, 3, 4
```

### Tatara::StringArray#slice

Slice value's' in `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
["1", "2", "3", "4", "5"].each{|s| @s << s}
@s = @s.slice(1, 3)
# => Slice value
@s.each{|s| puts s }
# => 2, 3, 4
```

### Tatara::StringArray#slice!

Destructive Slice value's' in `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
["1", "2", "3", "4", "5"].each{|s| @s << s}
@s.slice!(1, 3)
# => Slice value
@s.each{|s| puts s }
# => 2, 3, 4
```

### Tatara::StringArray#first

Get first value of `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
("A".."C").each{|s| @s << s }
# => Set new value's
puts @s.first
# => "A"
```

### Tatara::StringArray#last

Get last value of `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
("A".."C").each{|s| @s << s }
# => Set new value's
puts @s.last
# => "C"
```

### Tatara::StringArray#to_array

Convert to `Array` from `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
("A".."C").each{|s| @s << s }
# => Set new value's
puts @i.to_array
# => A, B, C
```

### Tatara::StringArray#to_json

Convert to `JSON` from `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
("A".."C").each{|s| @s << s }
# => Set new value's
puts @i.to_json
# => Convert to JSON
```

### Tatara::StringArray#import_array

Import to `Array` from `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
@s.import_array ["A", "B", "C"]
# => Set new value's ["A", "B", "C"]
```

### Tatara::StringArray#import_json

Import to `JSON` for `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
@s.import_json "[\"A\", \"B\", \"C\"]"
# => Set new value's ["A", "B", "C"]
```