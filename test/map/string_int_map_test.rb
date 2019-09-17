require "test_helper"
require "tatara/tatara"

class StringIntMapTest < Minitest::Test
  def test_init_tatara_string_int_map
    refute_nil Tatara::StringIntMap.new
  end
end