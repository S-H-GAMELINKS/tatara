require "test_helper"
require "tatara/tatara"

class IntVectorTest < Minitest::Test

  def test_init_tatara_int_vector
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    @i.emplace_back(5)
    assert_equal 42, @i.first
    assert_equal 5, @i.last
  end

  def test_tatara_int_vector_first
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 42, @i.first
  end

  def test_tatara_int_vector_last
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 42, @i.last
    @i.emplace_back(5)
    assert_equal 5, @i.last
  end

  def test_tatara_int_vector_bracket
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 42, @i[0]
    @i[0] = 5
    assert_equal 5, @i[0]
  end

  def test_tatara_int_vector_size
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 1, @i.size
  end

  def test_tatara_int_vector_clear
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 1, @i.size
    @i.clear
    assert_equal 0, @i.size
  end

  def test_tatara_int_vector_sum
    @i = Tatara::IntVector.new

    3.times { @i.emplace_back(42) }

    assert_equal 126, @i.sum
  end
end
