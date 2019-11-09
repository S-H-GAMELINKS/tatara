# Tatara::Integer
## About

`Tatara::Integer` is `Integer` class like `static type programming lang`.

`Tatara::Integer` can set `val` for `Integer` & `Float`.

```ruby
@i = Tatara::Integer.new
@i.val = 10
# => Set 10.
@i.val = 15.6
# => Set 15.
```

But, can not set `String` value.

```ruby
@i = Tatara::Integer.new
@ival = "42"
# => Error!
```

## Methods

[Tatara::Integer#new](#Tatara::Integer#new)

[Tatara::Integer#value](#Tatara::Integer#value)  
[Tatara::Integer#val](#Tatara::Integer#val)

[Tatara::Integer#value=](#Tatara::Integer#value=)  
[Tatara::Integer#val=](#Tatara::Integer#val=)

[Tatara::Integer#value+](#Tatara::Integer#value+)  
[Tatara::Integer#val+](#Tatara::Integer#value+)  
[Tatara::Integer#value-](#Tatara::Integer#value-)  
[Tatara::Integer#val-](#Tatara::Integer#val-)  
[Tatara::Integer#value*](#Tatara::Integer#value*)  
[Tatara::Integer#val*](#Tatara::Integer#val*)  
[Tatara::Integer#value/](#Tatara::Integer#value/)  
[Tatara::Integer#val/](#Tatara::Integer#val/)  
[Tatara::Integer#value%](#Tatara::Integer#value%)  
[Tatara::Integer#val%](#Tatara::Integer#val%)  
[Tatara::Integer#value**](#Tatara::Integer#value**)  
[Tatara::Integer#val**](#Tatara::Integer#val**)

[Tatara::Integer#value+=](#Tatara::Integer#value+=)  
[Tatara::Integer#val+=](#Tatara::Integer#value+=)  
[Tatara::Integer#value-=](#Tatara::Integer#value-=)  
[Tatara::Integer#val-=](#Tatara::Integer#val-=)  
[Tatara::Integer#value*=](#Tatara::Integer#value*=)  
[Tatara::Integer#val*=](#Tatara::Integer#val*=)  
[Tatara::Integer#value/=](#Tatara::Integer#value/=)  
[Tatara::Integer#val/=](#Tatara::Integer#val/=)  
[Tatara::Integer#value%=](#Tatara::Integer#value%=)  
[Tatara::Integer#val%=](#Tatara::Integer#val%=)  
[Tatara::Integer#value**=](#Tatara::Integer#value**=)  
[Tatara::Integer#val**=](#Tatara::Integer#val**=)


[Tatara::Integer#value==](#Tatara::Integer#value==)  
[Tatara::Integer#val==](#Tatara::Integer#val==)  

[Tatara::Integer#inc](#Tatara::Integer#inc)  
[Tatara::Integer#dec](#Tatara::Integer#dec)


[Tatara::Integer#to_s](#Tatara::Integer#to_s)  
[Tatara::Integer#to_f](#Tatara::Integer#to_f)

[Tatara::Integer#clear](#Tatara::Integer#clear)

[Tatara::Integer#equal?](#Tatara::Integer#equal?)

[Tatara::Integer#operator<<](#Tatara::Integer#operator<<)

### Tatara::Integer#new

Create new `Tatara::Integer` instance.  And init `value` is `0`

```ruby
@i = Tatara::Integer.new
```

### Tatara::Integer#value

return `Tatara::Integer` instance value.

```ruby
@i = Tatara::Integer.new
puts @i.value
# => Show `0`
```

### Tatara::Integer#val

return `Tatara::Integer` instance value.

```ruby
@i = Tatara::Integer.new
puts @i.val
# => Show `0`
```

### Tatara::Integer#value=

Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 42
# => Set 42.
```

### Tatara::Integer#val=

Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.val = 42
# => Set 42.
```

### Tatara::Integer#value+

Add instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 21
puts @i.value + 21
# => Value is 42
```

### Tatara::Integer#val+

Add instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 21
puts @i.val + 21
# => Value is 42
```

### Tatara::Integer#value-

Subtract instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 21
puts @i.value - 21
# => Value is 0
```

### Tatara::Integer#val-

Subtract instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 21
puts @i.val - 21
# => Value is 0
```

### Tatara::Integer#value*

Multiply instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 2
puts @i.value * 21
# => Value is 42
```

### Tatara::Integer#val*

Multiply instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 2
puts @i.val * 21
# => Value is 42
```

### Tatara::Integer#value/

Divided instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 42
puts @i.value / 21
# => Value is 2
```

### Tatara::Integer#val/

Divided instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 42
puts @i.val / 21
# => Value is 2
```

### Tatara::Integer#value%

Mod instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 42
puts @i.value % 20
# => Value is 2
puts @i.value % 42
# => Value is 0
```

### Tatara::Integer#val%

Mod instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 42
puts @i.val % 20
# => Value is 2
puts @i.val % 42
# => Value is 0
```

### Tatara::Integer#value**

Power instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 2
puts @i.value ** 2
# => Value is 4
puts @i.value ** 2
# => Value is 8
```

### Tatara::Integer#val**

Power instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 2
puts @i.val ** 2
# => Value is 4
puts @i.val ** 2
# => Value is 8
```

### Tatara::Integer#value+= 

Add and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 21
@i.value += 21
# => Value is 42
@i.value += 21
# => Value is 63
```

### Tatara::Integer#val+=

Add and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 21
@i.val += 21
# => Value is 42
@i.val += 21
# => Value is 63
```

### Tatara::Integer#value-= 

Subtract and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.value -= 10
# => Value is 10
@i.value -= 5
# => Value is 5
```

### Tatara::Integer#val-=

Subtract and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.val -= 10
# => Value is 10
@i.val -= 5
# => Value is 5
```

### Tatara::Integer#value*= 

Multiply and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.value *= 10
# => Value is 200
@i.value *= 5
# => Value is 1000
```

### Tatara::Integer#val*=

Multiply and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.val *= 10
# => Value is 200
@i.val *= 5
# => Value is 1000
```

### Tatara::Integer#value/= 

Divided and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.value /= 5
# => Value is 4
@i.value /= 2
# => Value is 2
```

### Tatara::Integer#val/=

Divided and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.val /= 5
# => Value is 4
@i.val /= 2
# => Value is 2
```

### Tatara::Integer#value%= 

Mod and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.value %= 20
# => Value is 0
@i.value = 20
@i.value %= 6
# => Value is 2
```


### Tatara::Integer#val%=

Mod and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.val = 20
@i.val %= 20
# => Value is 0
@i.value = 20
@i.value %= 6
# => Value is 2
```

### Tatara::Integer#value**= 

Power and Set instance value value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 2
@i.value **= 2
# => Value is 4
@i.value **= 2
# => Value is 16
```

### Tatara::Integer#val**=

Power and Set instance value value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 2
@i.val **= 2
# => Value is 4
@i.val **= 2
# => Value is 16
```

### Tatara::Integer#value==

Check instance value, and return `Boolean`.

```ruby 
@i = Tatara::Integer.new
@i.value = 42
puts @i.value == 42
# => true
puts @i.value == 62
# => false
```

### Tatara::Integer#val==

Check instance value, and return `Boolean`.

```ruby 
@i = Tatara::Integer.new
@i.val = 42
puts @i.val == 42
# => true
puts @i.val == 62
# => false
```

### Tatara::Integer#inc

Increment for instance value.

```ruby
@i = Tatara::Integer.new
@i.val = 1
@i.inc
# => Increment instance value
puts @i.val
# => 2
```

### Tatara::Integer#dec

Decrement for instance value.

```ruby
@i = Tatara::Integer.new
@i.val = 1
@i.dec
# => Increment instance value
puts @i.val
# => 0
```

### Tatara::Integer#to_s

Convert to `String` for instance value.

```ruby
@i = Tatara::Integer.new
@i.val = 42
@i.to_s
# => Conver to String.
```

### Tatara::Integer#to_f

Convert to `Float` for instance value.

```ruby
@i = Tatara::Integer.new
@i.val = 42
@i.to_f
# => Conver to Float.
```

### Tatara::Integer#clear

Clear instance value.

```ruby
@i = Tatara::Integer.new
@i.val = 42
# => Set 42
@i.clear
# => Clear instance value. Value is 0
```

### Tatara::Integer#equal?

Check instance value, and return `Boolean`

```ruby
@i = Tatara::Integer.new
@i.val = 42
puts @i.equal? 42
# => true
```

### Tatara::Integer#operator<<

Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new << 42
puts @i.val
# => 42
@i = @i << 50
puts @i.val
# => 50
```
