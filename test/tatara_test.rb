require "test_helper"
require "tatara"

class TataraTest < Minitest::Test
  def test_that_it_has_a_version_number
   refute_nil ::Tatara::VERSION
  end
end
