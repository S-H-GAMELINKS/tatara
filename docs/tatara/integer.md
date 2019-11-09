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