require "test_helper"
require "tatara/tatara"

class FloatArrayTest < Minitest::Test
  def test_init_tatara_float_array
    refute_nil Tatara::FloatArray.new
  end

  def test_tatara_float_array_first
    @array = Tatara::FloatArray.new
    @array.push(4.2)
    assert_equal 4.2, @array.first
  end

  def test_tatara_float_array_last
    @array = Tatara::FloatArray.new
    @array.push(4.2)
    assert_equal 4.2, @array.last
    @array.push(5.5)
    assert_equal 5.5, @array.last
  end

  def test_tatara_float_array_bracket
    @array = Tatara::FloatArray.new
    @array.push(4.2)
    assert_equal 4.2, @array[0]
    @array[0] = 5.5
    assert_equal 5.5, @array[0]
  end

  def test_tatara_float_array_size
    @array = Tatara::FloatArray.new
    @array.push(4.2)
    assert_equal 1, @array.size
  end
end