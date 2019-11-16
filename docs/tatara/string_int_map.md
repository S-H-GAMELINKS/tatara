# Tatara::StringIntMap
## About

`Tatara::StringIntMap` is `Map` class like `static type programming lang`.

`Tatara::StringIntMap` used by `String` key, and `Integer` value.
But, you can use `Float` and `Integer` for value.

```ruby
@i = Tatara::StringIntMap.new
@i["A"] = 42
# => Key: "A", Value: 42.
@i["B"] = 8.4
# => Key: "B", Value: 8.
```

But, can not use `Integer` & `Float` for key.

```ruby
@i = Tatara::StringIntMap.new
@i[42] = 42
# => Error!
@i[4.2] = 4.2
# => Error!
```

## Methods
### Tatara::StringIntMap#new

Create new `Tatara::StringIntMap` instance.

```ruby
@i = Tatara::StringIntMap.new
```

### Tatara::StringIntMap#\[\]

Access by key.

```ruby
@i = Tatara::StringIntMap.new
@i["A"] = 42
puts @i["A"]
# => 42
```
