# Tatara::FloatFloatMap
## About

`Tatara::FloatFloatMap` is `Map` class like `static type programming lang`.

`Tatara::FloatFloatMap` used by `Float` key, and `Float` value.
But, you can use `Integer` for key & value.

```ruby
@f = Tatara::FloatFloatMap.new
@f[0.5] = 4.2
# => Key: 0.5, Value: 4.2
@f[10] = 8
# => Key: 10.0, Value: 8.0
```

But, can not set `String`.

```ruby
@f = Tatara::FloatFloatMap.new
@f[0] = "42"
# => Error!
```

## Methods
### Tatara::FloatFloatMap#new

Create new `Tatara::FloatFloatMap` instance.
```ruby
@f = Tatara::FloatFloatMap.new
```

### Tatara::FloatFloatMap#\[\]

Access by key.

```ruby
@f = Tatara::FloatFloatMap.new
@f[0.5] = 4.2
puts @i[0.5]
# => 4.2
```

### Tatara::FloatFloatMap#\[\]=

Set value by key.

```ruby
@f = Tatara::FloatFloatMap.new
@f[0.5] = 4.2
# => Set value is 4.2
```

### Tatara::FloatFloatMap#insert

Set key & value.

```ruby
@f = Tatara::FloatFloatMap.new
@f.insert(0.5, 4.2)
# => Set value is 4.2.
```