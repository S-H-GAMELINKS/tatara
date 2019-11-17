# Tatara::StringArray
## About

`Tatara::StringArray` is `Vector` class like `static type programming lang`.

`Tatara::StringArray` use `String` value.
But, you can not use `Integer` & `Float` for value.

```ruby
@s = Tatara::StringArray.new
@s[0] = "42"
# => Set value "42" for index of 0.
@s[1] = "8.4"
# => Set value "8.4" for index of 1.
```

But, can not use `Integer` & `Float` for value.

```ruby
@s = Tatara::StringArray.new
@s[0] = 42
# => Error!
```

## Methods
### Tatara::StringArray#new

Create new `Tatara::StringArray` instance.

```ruby
@s = Tatara::StringArray.new
```

### Tatara::StringArray#\[\]

Access by index.

```ruby
@s = Tatara::StringArray.new
@s[0] = "42"
puts @i[0]
# => "42"
```

### Tatara::StringArray#\[\]=

Set value by index.

```ruby
@s = Tatara::StringArray.new
@s[0] = "42"
# => Set value "42" for index of 0.
```

### Tatara::StringArray#push

Create new value on end of `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
@s.push("42")
# => Set value "42" on end of `Tatara::StringArray`
```

### Tatara::StringArray#size

Size of `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
puts @s.size
# => 0
@s.push("42")
puts @s.size
# => 1
```

### Tatara::StringArray#clear

Clear `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
@s.push("42")
puts @s.size
# => 1
@s.clear
puts @s.size
# => 0
```
### Tatara::StringArray#operator<<

Create new value on end of `Tatara::StringArray`.

```ruby
@s = Tatara::StringArray.new
@s << "42"
# => Set value "42" on end of `Tatara::StringArray`
```