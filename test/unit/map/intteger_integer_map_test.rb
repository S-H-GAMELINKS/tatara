require "test_helper"
require "tatara"

class IntIntMapTest < Minitest::Test
  def test_int_string_int_map_tatara
    refute_nil Tatara::IntIntMap.new
  end

  def test_insert_value_int_int_map
    @map = Tatara::IntIntMap.new
    @map[0] = 42
    assert_equal 42, @map[0]
  end

  def test_insert_int_int_map
    @map = Tatara::IntIntMap.new
    @map.insert(42, 42)
    assert_equal 42, @map[42]
  end
end