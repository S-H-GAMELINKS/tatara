# Tatara::IntArray
## About

`Tatara::IntArray` is `Vector` class like `static type programming lang`.

`Tatara::IntArray` use `Integer` value.
But, you can use `Float` for value.

```ruby
@i = Tatara::IntArray.new
@i[0] = 42
# => Set value 42 for index of 0.
@i[1] = 8.4
# => Set value 8 for index of 1.
```

But, can not use `String` for value.

```ruby
@i = Tatara::IntArray.new
@i[0] = "42"
# => Error!
```

## Methods
### Tatara::IntArray#new

Create new `Tatara::IntArray` instance.

```ruby
@i = Tatara::IntArray.new
```

### Tatara::IntArray#\[\]

Access by index.

```ruby
@i = Tatara::IntArray.new
@i[0] = 42
puts @i[0]
# => 42
```


### Tatara::IntArray#\[\]=

Set value by index.

```ruby
@i = Tatara::IntArray.new
@i[0] = 42
# => Set value 42 for index of 0.
```

### Tatara::IntArray#push

Create new value on end of `Tatara::IntArray`.

```ruby
@i = Tatara::IntArray.new
@i.push(42)
# => Set value 42 on end of `Tatara::IntArray`
```
