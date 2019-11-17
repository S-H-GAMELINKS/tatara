require "test_helper"
require "tatara"

class IntStringMapTest < Minitest::Test
  def test_int_string_int_map_tatara
    refute_nil Tatara::IntStringMap.new
  end

  def test_insert_value_int_string_map
    @map = Tatara::IntStringMap.new
    @map[0] = "42"
    assert_equal "42", @map[0]
  end
end