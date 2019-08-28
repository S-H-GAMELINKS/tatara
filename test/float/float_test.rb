require "test_helper"
require "tatara/tatara"

class FloatTest < Minitest::Test

  def test_init_tatara_float
    refute_nil Tatara::Float.new
  end

  def test_assignment_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
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

  def test_plus_equal_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
    @f.value += 1.1
    assert_equal @f.value.round(2), 5.3
  end

  def test_clear_tatara_float
    @f = Tatara::Float.new
    @value = 4.2
    assert_equal @f.value, 4.2
    @f.clear
    assert_equal @f.value, 0
end