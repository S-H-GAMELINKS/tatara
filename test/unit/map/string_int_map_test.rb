require "test_helper"
require "tatara/tatara"

class StringIntMapTest < Minitest::Test
  def test_init_tatara_string_int_map
    refute_nil Tatara::StringIntMap.new
  end

  def test_insert_value_string_int_map
    @map = Tatara::StringIntMap.new
    @map["Map"] = 42
    assert_equal 42, @map["Map"]
  end
end