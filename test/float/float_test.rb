require "test_helper"
require "tatara/tatara"

class FloatTest < Minitest::Test

  def test_init_tatara_float
    @f = Tatara::Float.new
    refute_nil @f
    assert_equal @f.value, 0.0
  end

  def test_assignment_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
    @f.val = 2.1
    assert_equal 2.1, @f.val
  end

  def test_increment_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
    @f.inc
    assert_equal @f.value, 5.2
  end

  def test_decrement_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
    @f.dec
    assert_equal @f.value, 3.2
  end

  def test_tos_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
    @s = @f.to_s
    assert_equal @s, "4.2"
  end

  def test_toi_tatar_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
    @i = @f.to_i
    assert_equal @i, 4
  end

  def test_plus_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal 4.2, @f.value
    assert_equal 5.2, @f.value + 1.0
    assert_equal 5.2, @f.val + 1.0
  end

  def test_plus_equal_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
    @f.value += 1.1
    assert_equal @f.value.round(2), 5.3
    @f.val += 1.1
    assert_equal 6.4, @f.val
  end

  def test_minus_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal 4.2, @f.value
    assert_equal 3.2, @f.value - 1.0
    assert_equal 3.2, @f.val - 1.0
  end

  def test_minus_equal_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal 4.2, @f.value
    @f.value -= 1.1
    assert_equal 3.1, @f.value
    @f.val = 4.2
    @f.val -= 1.1
    assert_equal 3.1, @f.val
  end

  def test_multiply_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal 4.2, @f.value
    assert_equal 8.4, @f.value * 2
    assert_equal 8.4, @f.val * 2
  end

  def test_multiply_equal_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal 4.2, @f.value
    @f.value *= 2.0
    assert_equal 8.4, @f.value
    @f.val *= 2.0
    assert_equal 16.8, @f.val
  end

  def test_divide_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal 4.2, @f.value
    assert_equal 2.1, @f.value / 2
    assert_equal @f.value / 2, 2.1
  end

  def test_divided_equal_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal 4.2, @f.value
    @f.value /= 2
    assert_equal 2.1, @f.value
    @f.val = 4.2
    @f.val /= 2.0
    assert_equal @f.val, 2.1
  end

  def test_power_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal 4.2, @f.value
    assert_equal 17.64, @f.value**2.0
  end

  def test_power_equal_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal 4.2, @f.value
    @f.value **= 2.0
    assert_equal 17.64, @f.value
  end

  def test_clear_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
    @f.clear
    assert_equal @f.value, 0.0
  end

  def test_equal_tatara_float
    @f = Tatara::Float.new
    assert_equal @f.value, 0.0
    @f.value = 4.2
    assert @f.value == 4.2
  end
end