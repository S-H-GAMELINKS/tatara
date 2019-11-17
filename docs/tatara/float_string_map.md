# Tatara::FloatStringMap
## About

`Tatara::FloatStringMap` is `Map` class like `static type programming lang`.

`Tatara::FloatStringMap` used by `Float` key, and `String` value.
But, you can use `Integer` for key.

```ruby
@f = Tatara::FloatStringMap.new
@f[0.5] = "42"
# => Key: 0.5, Value: "42"
@f[10] = "8"
# => Key: 10.0, Value: "8"
```

But, can not set `Integer` & `Float` for value.

```ruby
@f = Tatara::FloatStringMap.new
@f[0.5] = 42
# => Error!
```

## Methods
### Tatara::FloatStringMap#new

Create new `Tatara::FloatStringMap` instance.
```ruby
@f = Tatara::FloatStringMap.new
```

### Tatara::FloatStringMap#\[\]

Access by key.

```ruby
@f = Tatara::FloatStringMap.new
@f[0.5] = "42"
puts @i[0.5]
# => "42"
```

### Tatara::FloatStringMap#\[\]=

Set value by key.

```ruby
@f = Tatara::FloatStringMap.new
@f[0.5] = "42"
# => Set value is "42"
```