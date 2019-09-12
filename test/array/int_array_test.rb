require "test_helper"
require "tatara/tatara"

class IntArrayTest < Minitest::Test
  def test_init_tatara_int_array
    refute_nil Tatara::IntArray.new
  end

  def test_tatara_int_array_first
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 42, @array.first
  end

  def test_tatara_int_array_last
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 42, @array.last
    @array.push(55)
    assert_equal 55, @array.last
  end

  def test_tatara_int_array_bracket
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 42, @array[0]
    @array[0] = 55
    assert_equal 55, @array[0]
  end

  def test_tatara_int_array_size
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 1, @array.size
  end
end