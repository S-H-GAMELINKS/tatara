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

### new

Create new `Tatara::Integer` instance.  And init `value` is `0`

```ruby
@i = Tatara::Integer.new
```

### val/value

return `Tatara::Integer` instance value.

```ruby
@i = Tatara::Integer.new
puts @i.val
puts @i.value
# => Show `0`
```

### val=/value=

Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.val = 42
# => Set 42.
@i.value = 21
# => Set 21.
```

### val+/value+

Add instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 21
puts @i.val + 21
# => Value is 42
puts @i.value + 21
# => Value is 42
```

### val-/value-

Subtract instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 21
puts @i.val - 21
# => Value is 0
puts @i.value - 5
# => Value is 16
```

### val*/value*

Multiply instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 2
puts @i.val * 21
# => Value is 42
puts @i.value * 10
# => Value is 20
```

### val//value/

Divided instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 42
puts @i.val / 21
# => Value is 2
puts @i.value * 2
# => Value is 21
```

### val%/value%

Mod instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 42
puts @i.val % 20
# => Value is 2
puts @i.value % 42
# => Value is 0
```

### val**/value**

Power instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 2
puts @i.val ** 2
# => Value is 4
puts @i.value ** 2
# => Value is 8
```

### val+=/value+= 

Add and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 21
@i.val += 21
# => Value is 42
@i.value += 21
# => Value is 63
```

### val-=/value-= 

Subtract and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.val -= 10
# => Value is 10
@i.value -= 5
# => Value is 5
```

### val*=/value*= 

Multiply and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.val *= 10
# => Value is 200
@i.value *= 5
# => Value is 1000
```

### val/=/value/= 

Divided and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 20
@i.val /= 5
# => Value is 4
@i.value /= 2
# => Value is 2
```

### val%=/value%= 

Mod and Set instance value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.val = 20
@i.val %= 20
# => Value is 0
@i.value = 20
@i.value %= 20
# => Value is 0
```

### val**=/value**= 

Power and Set instance value value for `Tatara::Integer`.

```ruby
@i = Tatara::Integer.new
@i.value = 2
@i.val **= 2
# => Value is 4
@i.value **= 2
# => Value is 16
```

### inc

Increment for instance value.

```ruby
@i = Tatara::Integer.new
@i.val = 1
@i.inc
# => Increment instance value
puts @i.val
# => 2
```

### dec

Decrement for instance value.

```ruby
@i = Tatara::Integer.new
@i.val = 1
@i.dec
# => Increment instance value
puts @i.val
# => 0
```

### to_s

Convert to `String` for instance value.

```ruby
@i = Tatara::Integer.new
@i.val = 42
@i.to_s
# => Conver to String.
```

### to_f

Convert to `Float` for instance value.

```ruby
@i = Tatara::Integer.new
@i.val = 42
@i.to_f
# => Conver to Float.
```