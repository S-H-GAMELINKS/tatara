# Tatara
[![Gem Version](https://badge.fury.io/rb/tatara.svg)](https://badge.fury.io/rb/tatara) [![CircleCI](https://circleci.com/gh/S-H-GAMELINKS/tatara/tree/master.svg?style=svg)](https://circleci.com/gh/S-H-GAMELINKS/tatara/tree/master) [![Test Coverage](https://api.codeclimate.com/v1/badges/0a4d91d453ab2466e2bc/test_coverage)](https://codeclimate.com/github/S-H-GAMELINKS/tatara/test_coverage) ![star](https://img.shields.io/github/stars/S-H-GAMELINKS/tatara) ![forks](https://img.shields.io/github/forks/S-H-GAMELINKS/tatara) ![license](https://img.shields.io/github/license/S-H-GAMELINKS/tatara) [![Maintainability](https://api.codeclimate.com/v1/badges/0a4d91d453ab2466e2bc/maintainability)](https://codeclimate.com/github/S-H-GAMELINKS/tatara/maintainability)

Add Type to Ruby!

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'tatara'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install tatara

## Usage

```ruby
@integer = Tatara::Integer.new # => This type is Integer!
@integer.value = 42
puts @integer.value # => 42 and type is Integer!
@integer.value = "42" #=> Error!
```

`Tatara` supported `Integer`, `Float`, `String`.  
And, Container for `Vector`, `Array`, `Map`!

## Reference

[Tatara Reference](https://s-h-gamelinks.github.io/tatara/)

## Development

After checking out the repo, run `bin/setup` to install dependencies. Then, run `rake test` to run the tests. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/S-H-GAMELINKS/tatara.
