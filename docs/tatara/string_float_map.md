# Tatara::StringFloatMap
## About

`Tatara::StringFloatMap` is `Map` class like `static type programming lang`.

`Tatara::StringFloatMap` used by `String` key, and `Float` value.
But, you can not use `Float` and `Integer` for value.

```ruby
@f = Tatara::StringFloatMap.new
@f["A"] = 4.2
# => Key: "A", Value: 4.2
@f["B"] = 8
# => Key: "B", Value: 8.0
```

But, can not use `Integer` & `Float` for key.

```ruby
@f = Tatara::StringFloatMap.new
@f[0] = 4.2
# => Error!
@f[4.2] = 4.2
# => Error!
```

## Methods
### Tatara::StringFloatMap#new

Create new `Tatara::StringFloatMap` instance.

```ruby
@f = Tatara::StringFloatMap.new
```

### Tatara::StringFloatMap#\[\]

Access by key.

```ruby
@f = Tatara::StringFloatMap.new
@f["A"] = 4.2
puts @f["A"]
# => 4.2
```


### Tatara::StringFloatMap#\[\]=

Set value by key.

```ruby
@f = Tatara::StringFloatMap.new
@f["A"] = 4.2
# => Set value is 4.2
```

### Tatara::StringFloatMap#insert

Set key & value.

```ruby
@f = Tatara::StringFloatMap.new
@f.insert("A", 4.2)
# => Set value is 42.
```