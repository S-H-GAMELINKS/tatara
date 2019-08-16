require "test_helper"
require "tatara/tatara"

class TataraTest < Minitest::Test
  def test_that_it_has_a_version_number
   refute_nil ::Tatara::VERSION
  end

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
end
