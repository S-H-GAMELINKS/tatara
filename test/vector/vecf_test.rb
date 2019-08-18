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
end
