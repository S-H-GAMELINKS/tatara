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
end