# Tatara::FloatIntMap
## About

`Tatara::FloatIntMap` is `Map` class like `static type programming lang`.

`Tatara::FloatIntMap` used by `Float` key, and `Integer` value.
But, you can use `Integer` for key.

```ruby
@f = Tatara::FloatIntMap.new
@f[0.5] = 42
# => Key: 0.5, Value: 42.0
@f[10] = 8.4
# => Key: 10.0, Value: 8.4
```

But, can not set `String`.

```ruby
@f = Tatara::FloatIntMap.new
@f[0] = "42"
# => Error!
```

## Methods
### Tatara::FloatIntMap#new

Create new `Tatara::FloatIntMap` instance.
```ruby
@f = Tatara::FloatIntMap.new
```

### Tatara::FloatIntMap#\[\]

Access by key.

```ruby
@f = Tatara::FloatIntMap.new
@f[0.5] = 4.2
puts @i[0.5]
# => 4.2
```

### Tatara::FloatIntMap#\[\]=

Set value by key.

```ruby
@f = Tatara::FloatIntMap.new
@f[0.5] = 4.2
# => Set value is 4.2
```