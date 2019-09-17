require "test_helper"
require "tatara/tatara"

class StringStringMapTest < Minitest::Test
  def test_init_tatara_string_string_map
    refute_nil Tatara::StringStringMap.new
  end

  def test_insert_value_string_string_map
    @map = Tatara::StringStringMap.new
    @map["Map"] = "42"
    assert_equal "42", @map["Map"]
  end
end