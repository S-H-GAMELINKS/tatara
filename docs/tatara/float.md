# Tatara::Float
## About

`Tatara::Float` is `Float` class like `static type programming lang`.

`Tatara::Float` can set `val` for `Float` & `Integer`.

```ruby
@i = Tatara::Float.new
@i.val = 1.1
# => Set 1.1.
@i.val = 15
# => Set 15.0.
```

But, can not set `String` value.

```ruby
@i = Tatara::Float.new
@i.val = "42"
# => Error!
```

## Methods
### Tatara::Float#new

Create new `Tatara::Float` instance.  And init `value` is `0.0`

```ruby
@f = Tatara::Float.new
```

### Tatara::Float#value

return `Tatara::Float` instance value.

```ruby
@f = Tatara::Float.new
puts @f.value
# => Show 0.0
```

### Tatara::Float#val

return `Tatara::Float` instance value.

```ruby
@f = Tatara::Float.new
puts @f.val
# => Show 0.0
```

### Tatara::Float#value=

Set instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 4.2
# => Set 4.2
```

### Tatara::Float#val=

Set instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.val = 4.2
# => Set 4.2
```

### Tatara::Float#value+

Add instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 2.1
puts @f.value + 2.1
# => Value is 4.2
```

### Tatara::Float#val+

Add instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 2.1
puts @i.val + 2.1
# => Value is 4.2
```

### Tatara::Float#value-

Subtract instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 2.1
puts @f.value - 2.1
# => Value is 0.0
```

### Tatara::Float#val-

Subtract instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 2.1
puts @i.val - 2.1
# => Value is 0.0
```

### Tatara::Float#value\*

Multiply instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 2.0
puts @f.value * 2.0
# => Value is 4.0
```

### Tatara::Float#val\*

Multiply instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 2.0
puts @i.val * 2.0
# => Value is 4.0
```

### Tatara::Float#value/

Divided instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 4.0
puts @f.value / 2.0
# => Value is 2.0
```

### Tatara::Float#val/

Divided instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 4.0
puts @f.val / 2.0
# => Value is 2.0
```

### Tatara::Float#value\*\*

Power instance value for `Tatara::Float`.

```ruby
@f = Tatara::Float.new
@f.value = 2.0
puts @i.value ** 2.0
# => Value is 4.0
puts @i.value ** 2.0
# => Value is 8.0
```
