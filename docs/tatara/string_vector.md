# Tatara::StringVector
## About

`Tatara::StringVector` is `Vector` class like `static type programming lang`.

`Tatara::StringVector` use `String` value.
But, you can not use `Integer` & `Float` for value.

```ruby
@s = Tatara::StringVector.new
@s[0] = "42"
# => Set value "42" for index of 0.
@s[1] = "8.4"
# => Set value "8.4" for index of 1.
```

But, can not use `Integer` & `Float` for value.

```ruby
@s = Tatara::StringVector.new
@s[0] = 42
# => Error!
```


## Methods
### Tatara::StringVector#new

Create new `Tatara::StringVector` instance.

```ruby
@s = Tatara::StringVector.new
```

### Tatara::StringVector#\[\]

Access by index.

```ruby
@s = Tatara::StringVector.new
@s[0] = "42"
puts @i[0]
# => "42"
```

### Tatara::StringVector#\[\]=

Set value by index.

```ruby
@s = Tatara::StringVector.new
@s[0] = "42"
# => Set value "42" for index of 0.
```
