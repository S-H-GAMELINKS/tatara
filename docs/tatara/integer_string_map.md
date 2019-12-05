# Tatara::IntStringMap
## About

`Tatara::IntStringMap` is `Map` class like `static type programming lang`.

`Tatara::IntStringMap` used by `Integer` key, and `String` value.
But, you can use `Float` for key & value.

```ruby
@i = Tatara::IntStringMap.new
@i[0] = "42"
# => Key: 0, Value: "42".
@i[10.0] = "8.4"
# => Key: 10, Value: "8.4".
```

But, can not set `Integer` & `Float` for value.

```ruby
@i = Tatara::IntStringMap.new
@i[0] = 42
# => Error!
```

## Methods
### Tatara::IntStringMap#new

Create new `Tatara::IntStringMap` instance.
```ruby
@i = Tatara::IntStringMap.new
```

### Tatara::IntStringMap#\[\]

Access by key.

```ruby
@i = Tatara::IntStringMap.new
@i[0] = "42"
puts @i[0]
# => "42"
```

### Tatara::IntStringMap#\[\]=

Set value by key.

```ruby
@i = Tatara::IntStringMap.new
@i[0] = "42"
# => Set value is "42".
```

### Tatara::IntStringMap#insert

Set key & value.

```ruby
@s = Tatara::IntStringMap.new
@s.insert(0, "42")
# => Set value is "42".
```