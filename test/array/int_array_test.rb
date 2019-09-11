require "test_helper"
require "tatara/tatara"

class IntArrayTest < Minitest::Test
  def test_init_tatara_int_array
    refute_nil Tatara::IntArray.new
  end

  def test_tatara_int_array_first
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 42, @array.first
  end
end