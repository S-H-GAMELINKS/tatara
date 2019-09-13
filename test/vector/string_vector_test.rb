require "test_helper"
require "tatara/tatara"

class StringVectorTest < Minitest::Test

  def test_init_tatara_string_vector
    refute_nil Tatara::StringVector.new
  end

  def test_tatara_string_vector_first
    @f = Tatara::StringVector.new
    @f.emplace_back("42")
    assert_equal @f.first, "42"
  end

  def test_tatara_string_vector_last
    @f = Tatara::StringVector.new
    @f.emplace_back("42")
    assert_equal @f.last, "42"
    @f.emplace_back("5")
    assert_equal @f.last, "5"
  end

  def test_tatara_string_vector_bracket
    @f = Tatara::StringVector.new
    @f.emplace_back("42")
    assert_equal @f[0], "42"
    @f[0] = "5"
    assert_equal @f[0], "5"
  end

  def test_tatara_string_vector_size
    @f = Tatara::StringVector.new
    @f.emplace_back("42")
    assert_equal @f.size, 1
  end

  def test_tatara_string_vector_clear
    @f = Tatara::StringVector.new
    @f.emplace_back("42")
    assert_equal @f.size, 1
    @f.clear
    assert_equal @f.size, 0
  end

  def test_tatara_string_vector_sum
    @s = Tatara::StringVector.new

    3.times { @s.emplace_back("42") }

    assert_equal @s.sum, "424242"
  end
end
