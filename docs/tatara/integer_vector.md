# Tatara::IntVector
## About

`Tatara::IntVector` is `Vector` class like `static type programming lang`.

`Tatara::IntVector` use `Integer` value.
But, you can use `Float` for value.

```ruby
@i = Tatara::IntVector.new
@i[0] = 42
# => Set value 42 for index of 0.
@i[1] = 8.4
# => Set value 8 for index of 1.
```

But, can not use `String` for value.

```ruby
@i = Tatara::IntVector.new
@i[0] = "42"
# => Error!
```

## Methods
### Tatara::IntVector#new

Create new `Tatara::IntVector` instance.

```ruby
@i = Tatara::IntVector.new
```

### Tatara::IntVector#\[\]

Access by index.

```ruby
@i = Tatara::IntVector.new
@i[0] = 42
puts @i[0]
# => 42
```

### Tatara::IntVector#\[\]=

Set value by index.

```ruby
@i = Tatara::IntVector.new
@i[0] = 42
# => Set value 42 for index of 0.
```

### Tatara::IntVector#emplace_back

Create new value on end of `Tatara::intVector`.

```ruby
@i = Tatara::IntVector.new
@i.emplace_back(42)
# => Set value 42 on end of `Tatara::intVector`
```

### Tatara::IntVector#size

Size of `Tatara::intVector`.

```ruby
@i = Tatara::IntVector.new
puts @i.size
# => 0
@i.emplace_back(42)
puts @i.size
# => 1
```

### Tatara::IntVector#clear

Clear `Tatara::intVector`.

```ruby
@i = Tatara::IntVector.new
@i.emplace_back(42)
puts @i.size
# => 1
@i.clear
puts @i.size
# => 0
```