require "test_helper"
require "tatara/tatara"

class VecfTest < Minitest::Test

  def test_init_tatara_vecf
    refute_nil Tatara::Vecf.new
  end
end
