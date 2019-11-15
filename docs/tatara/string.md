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
