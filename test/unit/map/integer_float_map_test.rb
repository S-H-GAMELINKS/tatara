require "test_helper"
require "tatara"

class IntFloatMapTest < Minitest::Test
  def test_int_string_int_map_tatara
    refute_nil Tatara::IntFloatMap.new
  end

  def test_insert_value_int_float_map
    @map = Tatara::IntFloatMap.new
    @map[0] = 4.2
    assert_equal 4.2, @map[0]
  end

  def test_insert_int_float_map
    @map = Tatara::IntFloatMap.new
    @map.insert(42, 4.2)
    assert_equal 4.2, @map[42]
  end
end