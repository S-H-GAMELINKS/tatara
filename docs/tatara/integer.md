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