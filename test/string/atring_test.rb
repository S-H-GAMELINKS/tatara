require "test_helper"
require "tatara/tatara"

class StringTest < Minitest::Test

  def test_init_tatara_string
    refute_nil Tatara::String.new
  end
end