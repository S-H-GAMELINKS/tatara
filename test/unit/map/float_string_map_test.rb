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
end