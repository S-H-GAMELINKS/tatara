require "test_helper"
require "tatara/tatara"

class FloatArrayTest < Minitest::Test
  def test_init_tatara_float_array
    refute_nil Tatara::FloatArray.new
  end
end