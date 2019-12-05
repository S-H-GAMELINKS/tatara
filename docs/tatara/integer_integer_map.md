# Tatara::IntIntMap
## About

`Tatara::IntIntMap` is `Map` class like `static type programming lang`.

`Tatara::IntIntMap` used by `Integer` key, and `Integer` value.
But, you can use `Float` for key & value.

```ruby
@i = Tatara::IntIntMap.new
@i[0] = 42
# => Key: 0, Value: 42.
@i[10.0] = 8.4
# => Key: 10, Value: 8.
```

But, can not set `String`.

```ruby
@i = Tatara::IntIntMap.new
@i[0] = "42"
# => Error!
```

## Methods
### Tatara::IntIntMap#new

Create new `Tatara::IntIntMap` instance.
```ruby
@i = Tatara::IntIntMap.new
```

### Tatara::IntIntMap#\[\]

Access by key.

```ruby
@i = Tatara::IntIntMap.new
@i[0] = 42
puts @i[0]
# => 42
```

### Tatara::IntIntMap#\[\]=

Set value by key.

```ruby
@i = Tatara::IntIntMap.new
@i[0] = 42
# => Set value is 42.
```

### Tatara::IntIntMap#insert

Set key & value.

```ruby
@s = Tatara::IntIntMap.new
@s.insert(0, 42)
# => Set value is 42.
```