require "test_helper"
require "tatara"

class StringFloatMapTest < Minitest::Test
  def test_init_tatara_string_float_map
    refute_nil Tatara::StringFloatMap.new
  end

  def test_insert_value_string_float_map
    @map = Tatara::StringFloatMap.new
    @map["Map"] = 4.2
    assert_equal 4.2, @map["Map"]
  end
end