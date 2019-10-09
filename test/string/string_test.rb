require "test_helper"
require "tatara/tatara"

class StringTest < Minitest::Test

  def test_init_tatara_string
    @s = Tatara::String.new
    refute_nil @s
    assert_equal @s.value, ""
  end

  def test_assignment_tatara_string
    @s = Tatara::String.new
    @s.value = "42"
    assert_equal @s.value, "42"
    assert_equal "42", @s.val
  end

  def test_toi_tatara_string
    @s = Tatara::String.new
    @s.value = "42"
    assert_equal @s.value, "42"

    @i = @s.to_i
    assert_equal @i, 42
  end

  def test_plus_equal_tatara_string
    @s = Tatara::String.new
    @s.value = "42"
    assert_equal @s.value, "42"
    @s.value += "hoge"
    assert_equal @s.value, "42hoge"
  end

  def test_clear_tatara_string
    @s = Tatara::String.new
    @s.value = "42"
    assert_equal @s.value, "42"
    @s.clear
    assert_equal @s.value, ""
  end

  def test_equal_tatara_string
    @s = Tatara::String.new
    assert_equal @s.value, ""
    @s.value = "42"
    assert @s.value == "42"
  end
end