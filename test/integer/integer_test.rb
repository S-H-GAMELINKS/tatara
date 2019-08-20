require "test_helper"
require "tatara/tatara"

class IntegerTest < Minitest::Test

  def test_init_tatara_integer
    refute_nil Tatara::Integer.new
  end

  def test_assignment_tatara_integer
    @i = Tatara::Integer.new
    @i = 42
    assert_equal @i, 42
  end
end