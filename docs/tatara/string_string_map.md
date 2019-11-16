# Tatara::StringStringMap
## About

`Tatara::StringStringMap` is `Map` class like `static type programming lang`.

`Tatara::StringStringMap` used by `String` key, and `String` value.
But, you can not use `Float` and `Integer` for key & value.

```ruby
@s = Tatara::StringStringMap.new
@s["A"] = "42"
# => Key: "A", Value: "42".
@s["B"] = "8"
# => Key: "B", Value: "8".
```

But, can not set `Integer` & `Float`.

```ruby
@s = Tatara::StringStringMap.new
@s["A"] = 42
# => Error!
@s["B"] = 4.2
# => Error!
```

## Methods
### Tatara::StringStringMap#new

Create new `Tatara::StringStringMap` instance.

```ruby
@s = Tatara::StringStringMap.new
```
