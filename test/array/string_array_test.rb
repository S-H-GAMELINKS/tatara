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

  def test_tatara_string_array_last
    @array = Tatara::StringArray.new
    @array.push("42")
    assert_equal "42", @array.last
    @array.push("55")
    assert_equal "55", @array.last
  end

  def test_tatara_string_array_bracket
    @array = Tatara::StringArray.new
    @array.push("42")
    assert_equal "42", @array[0]
    @array[0] = "55"
    assert_equal "55", @array[0]
  end
end