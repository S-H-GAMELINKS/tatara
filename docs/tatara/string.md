# Tatara::String
## About

`Tatara::String` is `String` class like `static type programming lang`.

`Tatara::String` can set `val` for `String`.

```ruby
@s = Tatara::String.new
@s.val = "hoge"
# => Set "hoge"
@s.val = "fuga"
# => Set "fuga"
```

But, can not set `Integer` & `Float` value.

```ruby
@s = Tatara::String.new
@s.val = 42
# => Error!
@s.val = 4.2
# => Error!
```

## Methods
### Tatara::String#new

Create new `Tatara::String` instance.  And init `value` is `""`

```ruby
@s = Tatara::String.new
```

### Tatara::String#value

return `Tatara::String` instance value.

```ruby
@s = Tatara::String.new
puts @s.value
# => Show ""
```

### Tatara::String#val

return `Tatara::String` instance value.

```ruby
@s = Tatara::String.new
puts @s.val
# => Show ""
```

### Tatara::String#value=

Set instance value for `Tatara::String`.

```ruby
@s = Tatara::String.new
@s.value = "42"
# => Set "42"
```

### Tatara::String#val=

Set instance value for `Tatara::String`.

```ruby
@s = Tatara::String.new
@s.val = "42"
# => Set "42"
```

### Tatara::String#value+= 

Add and Set instance value for `Tatara::String`.

```ruby
@s = Tatara::String.new
@s.value = "21"
@s.value += "21"
# => Value is "2121"
@s.value += "21"
# => Value is "212121"
```

### Tatara::String#val+= 

Add and Set instance value for `Tatara::String`.

```ruby
@s = Tatara::String.new
@s.val = "21"
@s.val += "21"
# => Value is "2121"
@s.val += "21"
# => Value is "212121"
```

### Tatara::String#value==

Check instance value, and return `Boolean`.

```ruby 
@s = Tatara::String.new
@s.value = "42"
puts @s.value == "42"
# => true
puts @s.value == "62"
# => false
```

### Tatara::String#val==

Check instance value, and return `Boolean`.

```ruby 
@s = Tatara::String.new
@s.val = "42"
puts @s.val == "42"
# => true
puts @s.val == "62"
# => false
```

### Tatara::String#to_i

Convert to `Integer` for instance value.

```ruby
@s = Tatara::String.new
@s.val = "42"
@s.to_s
# => Conver to Integer.
```

### Tatara::String#to_f

Convert to `Float` for instance value.

```ruby
@s = Tatara::String.new
@s.val = "4.2"
@s.to_f
# => Convert to Float.
```

### Tatara::String#clear

Clear instance value.

```ruby
@s = Tatara::String.new
@s.val = "42"
# => Set "42"
@s.clear
# => Clear instance value. Value is ""
```

### Tatara::String#operator<<

Set instance value for `Tatara::String`.

```ruby
@s = Tatara::String.new << "42"
puts @s.val
# => "42"
@s = @s << "50"
puts @s.val
# => "50"
```

### Tatara::String#\[\]

Access by Index.

```ruby
@s = Tatara::String.new
@s <<= "hello"
puts @s[0]
# => "h"
puts @s[1]
# => "e"
```

### Tatara::String#slice

Slice `Tatara::String` value.

```ruby
@s = Tatara::String.new
@s <<= "hello"
puts @s.slice(0, 3)
# => "hel"
puts @s.slice(0, 4)
# => "hell"
```

### Tatara::String#slice!

Slice `Tatara::String` value, and Reset sliced value.

```ruby
@s = Tatara::String.new
@s <<= "hello"
@s.slice!(0, 3)
puts @s.val
# => "hel"
```