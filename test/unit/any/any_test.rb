require "test_helper"
require "tatara"

class AnyTest < Minitest::Test

  def test_init_tatara_any
    @a = Tatara::Any.new
    refute_nil @a
    assert_nil @a.value
  end

  def test_assignment_tatara_any
    @a = Tatara::Any.new
    assert_nil @a.value
    @a.value = 42
    assert_equal 42, @a.value
    @a.value = 4.2
    assert_equal 4.2, @a.value
    @a.value = "hello"
    assert_equal "hello", @a.value
  end

  def test_plus_tatara_any
    @a = Tatara::Any.new
    assert_nil @a.value
    @a.value = 42
    assert_equal 63, @a.value + 21
    @a.value = "hello"
    assert_equal "hellohello", @a.value + "hello"
    @a.value = 4.2
    assert_equal 6.3, (@a.value + 2.1).round(2)
  end

  def test_minus_tatara_any
    @a = Tatara::Any.new
    assert_nil @a.value
    @a.value = 42
    assert_equal 21, @a.value - 21
    @a.value = "hello"
    assert_raises(NoMethodError) { @a.value - "hello" }
    @a.value = 4.2
    assert_equal 2.1, (@a.value - 2.1).round(2)
  end

  def test_multiply_tatara_any
    @a = Tatara::Any.new
    assert_nil @a.value
    @a.value = 42
    assert_equal 84, @a.value * 2
    @a.value = "hello"
    assert_raises(TypeError) { @a.value * "hello" }
    @a.value = 4.2
    assert_equal 8.4, (@a.value * 2).round(2)
  end

  def test_divided_tatara_any
    @a = Tatara::Any.new
    assert_nil @a.value
    @a.value = 42
    assert_equal 21, @a.value / 2
    @a.value = "hello"
    assert_raises(TypeError) { @a.value * "hello" }
    @a.value = 4.2
    assert_equal 2.1, (@a.value / 2).round(2)
  end

  def test_divided_tatara_any
    @a = Tatara::Any.new
    assert_nil @a.value
    @a.value = 42
    assert_equal 2, @a.value % 40
    @a.value = "hello"
    assert_equal "hello", @a.value % "hello"
    @a.value = 4.2
    assert_equal 0.2, (@a.value % 4.0).round(2)
  end

  def test_power_tatara_any
    @a = Tatara::Any.new
    @a.value = 2
    assert_equal 4, @a.value ** 2
    @a.value = "hello"
    assert_raises(NoMethodError) { @a.value ** "hello" }
    @a.value = 2.0
    assert_equal 4.0, (@a.value ** 2.0).round(2)
  end
end