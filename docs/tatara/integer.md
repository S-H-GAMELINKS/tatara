# Tatara::Integer
## About

`Tatara::Integer` is `Integer` class like `static type programming lang`.

`Tatara::Integer` can set `val` for `Integer` & `Float`.

```ruby
@i = Tatara::Integer.new
@i.val = 10
# => Set 10.
@i.val = 15.6
# => Set 15.
```

But, can not set `String` value.

```ruby
@i = Tatara::Integer.new
@ival = "42"
# => Error!
```
