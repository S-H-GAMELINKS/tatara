require "test_helper"
require "tatara/tatara"

class IntegerTest < Minitest::Test

  def test_init_tatara_integer
    @i = Tatara::Integer.new
    refute_nil @i
    assert_equal @i.value, 0
  end

  def test_assignment_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
  end

  def test_return_value_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    @i.val = 21
    assert_equal 21, @i.val
  end

  def test_increment_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
    @i.inc
    assert_equal @i.value, 43
  end

  def test_decrement_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
    @i.dec
    assert_equal @i.value, 41
  end

  def test_tos_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
    @s = @i.to_s
    assert_equal @s, "42"
  end

  def test_plus_equal_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
    @i.value += 10
    assert_equal @i.value, 52
    @i.val += 10
    assert_equal 62, @i.val
  end

  def test_power_equal_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
    @i.value **= 2
    assert_equal @i.value, 1764
  end

  def test_minus_equal_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    @i.value -= 42
    assert_equal 0, @i.value
    @i.val -= 2
    assert_equal -2, @i.val
  end

  def test_multiply_equal_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    @i.value *= 2
    assert_equal 84, @i.value
    @i.val *= 2
    assert_equal 168, @i.val
  end

  def test_divided_equal_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    @i.value /= 42
    assert_equal 1, @i.value
    @i.val = 42
    @i.val /= 42
    assert_equal 1, @i.val
  end

  def test_mod_equal_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    @i.value %= 42
    assert_equal 0, @i.value
  end

  def test_plus_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    assert_equal 43, @i.value + 1
    assert_equal 43, @i.val + 1
  end

  def test_minus_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    assert_equal 41, @i.value - 1
    assert_equal 41, @i.val - 1
  end

  def test_multiply_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    assert_equal 84, @i.value * 2
    assert_equal 84, @i.val * 2
  end

  def test_divide_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    assert_equal 21, @i.value / 2
    assert_equal 21, @i.val / 2
  end

  def test_mod_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    assert_equal 0, @i.value % 42
  end

  def test_power_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal 42, @i.value
    assert_equal 1764, @i.value**2
  end

  def test_clear_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
    @i.clear
    assert_equal @i.value, 0
  end

  def test_equal_tatara_integer
    @i = Tatara::Integer.new
    assert_equal @i.value, 0
    @i.value = 42
    assert @i.value == 42
  end
end