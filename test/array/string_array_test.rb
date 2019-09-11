require "test_helper"
require "tatara/tatara"

class StringArrayTest < Minitest::Test
  def test_init_tatara_string_array
    refute_nil Tatara::StringArray.new
  end

  def test_tatara_string_array_first
    @array = Tatara::StringArray.new
    @array.push("42")
    assert_equal "42", @array.first
  end
end