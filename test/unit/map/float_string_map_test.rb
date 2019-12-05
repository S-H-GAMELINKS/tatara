require "test_helper"
require "tatara"

class FloatStringMapTest < Minitest::Test
  def test_int_string_int_map_tatara
    refute_nil Tatara::FloatStringMap.new
  end

  def test_insert_value_float_int_map
    @map = Tatara::FloatStringMap.new
    @map[0.5] = "42"
    assert_equal "42", @map[0.5]
  end

  def test_insert_float_string_map
    @map = Tatara::FloatStringMap.new
    @map.insert(4.2, "42")
    assert_equal "42", @map[4.2]
  end
end