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
