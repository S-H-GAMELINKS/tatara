require "test_helper"
require "tatara/tatara"

class IntIntMapTest < Minitest::Test
  def test_int_string_int_map_tatara
    refute_nil Tatara::IntIntMap.new
  end
end