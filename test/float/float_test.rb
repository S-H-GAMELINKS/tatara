require "test_helper"
require "tatara/tatara"

class FloatTest < Minitest::Test

  def test_init_tatara_float
    refute_nil Tatara::Float.new
  end
end