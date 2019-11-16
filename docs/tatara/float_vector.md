# Tatara::FloatVector
## About

`Tatara::FloatVector` is `Vector` class like `static type programming lang`.

`Tatara::FloatVector` use `Float` value.
But, you can use `Integer` for value.

```ruby
@f = Tatara::FloatVector.new
@f[0] = 4.2
# => Set value 4.2 for index of 0.
@f[1] = 8
# => Set value 8.0 for index of 1.
```

But, can not use `String` for value.

```ruby
@f = Tatara::FloatVector.new
@f[0] = "42"
# => Error!
```

## Methods
### Tatara::FloatVector#new

Create new `Tatara::FloatVector` instance.

```ruby
@f = Tatara::FloatVector.new
```


### Tatara::FloatVector#\[\]

Access by index.

```ruby
@f = Tatara::FloatVector.new
@f[0] = 4.2
puts @i[0]
# => 4.2
```

### Tatara::FloatVector#\[\]=

Set value by index.

```ruby
@f = Tatara::FloatVector.new
@f[0] = 4.2
# => Set value 4.2 for index of 0.
```

### Tatara::FloatVector#emplace_back

Create new value on end of `Tatara::intVector`.

```ruby
@f = Tatara::FloatVector.new
@f.emplace_back(4.2)
# => Set value 4.2 on end of `Tatara::intVector`
```
