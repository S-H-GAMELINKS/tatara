require "test_helper"
require "tatara/tatara"

class FloatTest < Minitest::Test

  def test_init_tatara_float
    refute_nil Tatara::Float.new
  end

  def test_assignment_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
  end

  def test_increment_tatara_float
    @f = Tatara::Float.new
    @f.value = 4.2
    assert_equal @f.value, 4.2
    @f.inc
    assert_equal @f.value, 5.2
  end
end