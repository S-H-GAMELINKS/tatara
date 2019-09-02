require "test_helper"
require "tatara/tatara"

class VecfTest < Minitest::Test

  def test_init_tatara_vecf
    refute_nil Tatara::Vecf.new
  end

  def test_tatara_vecf_first
    @f = Tatara::Vecf.new
    @f.emplace_back(4.2)
    assert_equal @f.first, 4.2
  end

  def test_tatara_vecf_last
    @f = Tatara::Vecf.new
    @f.emplace_back(4.2)
    assert_equal @f.last, 4.2
    @f.emplace_back(5.5)
    assert_equal @f.last, 5.5
  end

  def test_tatara_vecf_bracket
    @f = Tatara::Vecf.new
    @f.emplace_back(4.2)
    assert_equal @f[0], 4.2
    @f[0] = 5.5
    assert_equal @f[0], 5.5
  end

  def test_tatara_vecf_size
    @f = Tatara::Vecf.new
    @f.emplace_back(4.2)
    assert_equal @f.size, 1
  end

  def test_tatara_vecf_clear
    @f = Tatara::Vecf.new
    @f.emplace_back(4.2)
    assert_equal @f.size, 1
    @f.clear
    assert_equal @f.size, 0
  end

  def test_tatara_vecf_sum
    @f = Tatara::Vecf.new

    3.times { @f.emplace_back(4.2) }

    assert_equal @f.sum, 12.8
  end
end
