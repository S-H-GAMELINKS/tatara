require "test_helper"
require "tatara/tatara"

class FloatVectorTest < Minitest::Test

  def test_init_tatara_float_vector
    refute_nil Tatara::FloatVector.new
  end

  def test_tatara_float_vector_first
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal @f.first, 4.2
  end

  def test_tatara_float_vector_last
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal @f.last, 4.2
    @f.emplace_back(5.5)
    assert_equal @f.last, 5.5
  end

  def test_tatara_float_vector_bracket
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal @f[0], 4.2
    @f[0] = 5.5
    assert_equal @f[0], 5.5
  end

  def test_tatara_float_vector_size
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal @f.size, 1
  end

  def test_tatara_float_vector_clear
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal @f.size, 1
    @f.clear
    assert_equal @f.size, 0
  end

  def test_tatara_float_vector_sum
    @f = Tatara::FloatVector.new

    3.times { @f.emplace_back(4.2) }

    assert_equal @f.sum.round(2), 12.6
  end
end
