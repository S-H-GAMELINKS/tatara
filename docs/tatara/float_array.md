# Tatara::FloatArray
## About

`Tatara::FloatArray` is `Vector` class like `static type programming lang`.

`Tatara::FloatArray` use `Float` value.
But, you can use `Integer` for value.

```ruby
@f = Tatara::FloatArray.new
@f[0] = 4.2
# => Set value 4.2 for index of 0.
@f[1] = 8
# => Set value 8.0 for index of 1.
```

But, can not use `String` for value.

```ruby
@f = Tatara::FloatArray.new
@f[0] = "42"
# => Error!
```

## Methods
### Tatara::FloatArray#new

Create new `Tatara::FloatArray` instance.

```ruby
@f = Tatara::FloatArray.new
```

### Tatara::FloatArray#\[\]

Access by index.

```ruby
@f = Tatara::FloatArray.new
@f[0] = 4.2
puts @i[0]
# => 4.2
```

### Tatara::FloatArray#\[\]=

Set value by index.

```ruby
@f = Tatara::FloatArray.new
@f[0] = 4.2
# => Set value 4.2 for index of 0.
```

### Tatara::FloatArray#push

Create new value on end of `Tatara::FloatArray`.

```ruby
@f = Tatara::FloatArray.new
@f.push(4.2)
# => Set value 4.2 on end of `Tatara::FloatArray`
```
