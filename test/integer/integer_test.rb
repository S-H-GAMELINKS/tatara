require "test_helper"
require "tatara/tatara"

class IntegerTest < Minitest::Test

  def test_init_tatara_integer
    refute_nil Tatara::Integer.new
  end

  def test_assignment_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
  end

  def test_increment_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
    @i++
    assert_equal @i.value, 43
  end

  def test_decrement_tatara_integer
    @i = Tatara::Integer.new
    @i.value = 42
    assert_equal @i.value, 42
    @i--
    assert_equal @i.value, 41
  end
end