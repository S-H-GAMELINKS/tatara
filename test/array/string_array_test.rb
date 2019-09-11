require "test_helper"
require "tatara/tatara"

class StringArrayTest < Minitest::Test
  def test_init_tatara_string_array
    refute_nil Tatara::StringArray.new
  end
end