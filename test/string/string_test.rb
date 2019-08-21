require "test_helper"
require "tatara/tatara"

class StringTest < Minitest::Test

  def test_init_tatara_string
    refute_nil Tatara::String.new
  end

  def test_assignment_tatara_string
    @s = Tatara::String.new
    @s.value = "42"
    assert_equal @s.value, "42"
  end
end