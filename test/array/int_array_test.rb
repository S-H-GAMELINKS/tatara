require "test_helper"
require "tatara/tatara"

class IntArrayTest < Minitest::Test
  def test_init_tatara_int_array
    refute_nil Tatara::IntArray.new
  end
end