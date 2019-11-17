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

### Tatara::StringVector#emplace_back

Create new value on end of `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
@s.emplace_back("42")
# => Set value "42" on end of `Tatara::StringVector`
```

### Tatara::StringVector#size

Size of `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
puts @s.size
# => 0
@s.emplace_back("42")
puts @s.size
# => 1
```

### Tatara::StringVector#clear

Clear `Tatara::StringVector`.

```ruby
@s = Tatara::StringVector.new
@s.emplace_back("42")
puts @s.size
# => 1
@s.clear
puts @s.size
# => 0
```
