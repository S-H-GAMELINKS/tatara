require "test_helper"
require "tatara/tatara"

class IntVectorTest < Minitest::Test

  def test_init_tatara_int_vector
    @f = Tatara::IntVector.new
    @f.emplace_back(42)
    @f.emplace_back(5)
    assert_equal @f.first, 42
    assert_equal @f.last, 5
  end

  def test_tatara_int_vector_first
    @f = Tatara::IntVector.new
    @f.emplace_back(42)
    assert_equal @f.first, 42
  end

  def test_tatara_int_vector_last
    @f = Tatara::IntVector.new
    @f.emplace_back(42)
    assert_equal @f.last, 42
    @f.emplace_back(5)
    assert_equal @f.last, 5
  end

  def test_tatara_int_vector_bracket
    @f = Tatara::IntVector.new
    @f.emplace_back(42)
    assert_equal @f[0], 42
    @f[0] = 5
    assert_equal @f[0], 5
  end

  def test_tatara_int_vector_size
    @f = Tatara::IntVector.new
    @f.emplace_back(42)
    assert_equal @f.size, 1
  end

  def test_tatara_int_vector_clear
    @f = Tatara::IntVector.new
    @f.emplace_back(42)
    assert_equal @f.size, 1
    @f.clear
    assert_equal @f.size, 0
  end

  def test_tatara_int_vector_sum
    @f = Tatara::IntVector.new

    3.times { @f.emplace_back(42) }

    assert_equal @f.sum, 126
  end
end
