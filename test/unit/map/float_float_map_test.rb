require "test_helper"
require "tatara"

class FloatFloatMapTest < Minitest::Test
  def test_int_string_int_map_tatara
    refute_nil Tatara::FloatFloatMap.new
  end

  def test_insert_value_float_int_map
    @map = Tatara::FloatFloatMap.new
    @map[0.5] = 4.2
    assert_equal 4.2, @map[0.5]
  end

  def test_insert_float_float_map
    @map = Tatara::FloatFloatMap.new
    @map.insert(4.2, 4.2)
    assert_equal 4.2, @map[4.2]
  end
end