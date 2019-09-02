require "test_helper"
require "tatara/tatara"

class VeciTest < Minitest::Test

  def test_init_tatara_veci
    @f = Tatara::Veci.new
    @f.emplace_back(42)
    @f.emplace_back(5)
    assert_equal @f.first, 42
    assert_equal @f.last, 5
  end

  def test_tatara_veci_first
    @f = Tatara::Veci.new
    @f.emplace_back(42)
    assert_equal @f.first, 42
  end

  def test_tatara_veci_last
    @f = Tatara::Veci.new
    @f.emplace_back(42)
    assert_equal @f.last, 42
    @f.emplace_back(5)
    assert_equal @f.last, 5
  end

  def test_tatara_veci_bracket
    @f = Tatara::Veci.new
    @f.emplace_back(42)
    assert_equal @f[0], 42
    @f[0] = 5
    assert_equal @f[0], 5
  end

  def test_tatara_veci_size
    @f = Tatara::Veci.new
    @f.emplace_back(42)
    assert_equal @f.size, 1
  end

  def test_tatara_veci_clear
    @f = Tatara::Veci.new
    @f.emplace_back(42)
    assert_equal @f.size, 1
    @f.clear
    assert_equal @f.size, 0
  end

  def test_tatara_veci_sum
    @f = Tatara::Veci.new

    3.times do
      @f.emplace_back(42)
    end

    assert_equal @f.sum, 128
  end
end
