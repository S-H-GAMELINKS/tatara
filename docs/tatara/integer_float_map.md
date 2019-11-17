# Tatara::IntFloatMap
## About

`Tatara::IntFloatMap` is `Map` class like `static type programming lang`.

`Tatara::IntFloatMap` used by `Integer` key, and `Float` value.
But, you can use `Float` for key & value.

```ruby
@i = Tatara::IntFloatMap.new
@i[0] = 42
# => Key: 0, Value: 42.0
@i[10.0] = 8.4
# => Key: 10, Value: 8.4
```

But, can not set `String`.

```ruby
@i = Tatara::IntFloatMap.new
@i[0] = "42"
# => Error!
```

## Methods
### Tatara::IntFloatMap#new

Create new `Tatara::IntFloatMap` instance.
```ruby
@i = Tatara::IntFloatMap.new
```

### Tatara::IntFloatMap#\[\]

Access by key.

```ruby
@i = Tatara::IntFloatMap.new
@i[0] = 4.2
puts @i[0]
# => 4.2
```

### Tatara::IntFloatMap#\[\]=

Set value by key.

```ruby
@i = Tatara::IntFloatMap.new
@i[0] = 4.2
# => Set value is 4.2
```