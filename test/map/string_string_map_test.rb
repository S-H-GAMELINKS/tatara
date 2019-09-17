require "test_helper"
require "tatara/tatara"

class StringStringMapTest < Minitest::Test
  def test_init_tatara_string_string_map
    refute_nil Tatara::StringStringMap.new
  end
end