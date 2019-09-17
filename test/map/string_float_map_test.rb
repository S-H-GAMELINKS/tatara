require "test_helper"
require "tatara/tatara"

class StringFloatMapTest < Minitest::Test
  def test_init_tatara_string_float_map
    refute_nil Tatara::StringFloatMap.new
  end
end