require "test_helper"
require "tatara/tatara"

class TataraTest < Minitest::Test
  def test_that_it_has_a_version_number
   # refute_nil ::Tatara::VERSION
  end

  def test_init_tatara_veci
    refute_nil Tatara::Veci.new
  end
end
