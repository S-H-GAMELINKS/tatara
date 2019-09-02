require "test_helper"
require "tatara/tatara"

class VecsTest < Minitest::Test

  def test_init_tatara_vecs
    refute_nil Tatara::Vecs.new
  end

  def test_tatara_vecs_first
    @f = Tatara::Vecs.new
    @f.emplace_back("42")
    assert_equal @f.first, "42"
  end

  def test_tatara_vecs_last
    @f = Tatara::Vecs.new
    @f.emplace_back("42")
    assert_equal @f.last, "42"
    @f.emplace_back("5")
    assert_equal @f.last, "5"
  end

  def test_tatara_vecs_bracket
    @f = Tatara::Vecs.new
    @f.emplace_back("42")
    assert_equal @f[0], "42"
    @f[0] = "5"
    assert_equal @f[0], "5"
  end

  def test_tatara_vecs_size
    @f = Tatara::Vecs.new
    @f.emplace_back("42")
    assert_equal @f.size, 1
  end

  def test_tatara_vecs_clear
    @f = Tatara::Vecs.new
    @f.emplace_back("42")
    assert_equal @f.size, 1
    @f.clear
    assert_equal @f.size, 0
  end

  def test_tatara_vecs_sum
    @s = Tatara::Vecs.new

    3.times { @s.emplace_back("42") }

    assert_equal @s.sum, "424242"
  end
end
