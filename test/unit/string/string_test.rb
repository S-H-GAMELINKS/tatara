require "test_helper"
require "tatara"

class StringTest < Minitest::Test

  def test_init_tatara_string
    @s = Tatara::String.new
    refute_nil @s
    assert_equal "", @s.value
  end

  def test_assignment_tatara_string
    @s = Tatara::String.new
    @s.value = "42"
    assert_equal "42", @s.value
    @s.val = "4.2"
    assert_equal "4.2", @s.val
  end

  def test_toi_tatara_string
    @s = Tatara::String.new
    @s.value = "42"
    assert_equal "42", @s.value
    @i = @s.to_i
    assert_equal @i, 42
  end

  def test_tof_tatara_string
    @s = Tatara::String.new
    @s.value = "4.2"
    assert_equal "4.2", @s.value
    @s = @s.to_f.round(2)
    assert_equal 4.2, @s
  end

  def test_plus_equal_tatara_string
    @s = Tatara::String.new
    @s.value = "42"
    assert_equal "42", @s.value
    @s.value += "hoge"
    assert_equal "42hoge", @s.value
    @s.val += "hello"
    assert_equal "42hogehello", @s.val
  end

  def test_clear_tatara_string
    @s = Tatara::String.new
    @s.value = "42"
    assert_equal "42", @s.value
    @s.clear
    assert_equal "", @s.value
  end

  def test_equal_tatara_string
    @s = Tatara::String.new
    assert_equal "", @s.value
    @s.value = "42"
    assert @s.value == "42"
    assert @s.val == "42"
    assert @s.equal? "42"
  end

  def test_return_object_init_tatara_string
    @i = Tatara::String.new << "42"
    assert_equal Tatara::String, @i.class
    assert_equal "42", @i.val
  end

  def test_index_access_tatara_string
    @s = Tatara::String.new << "hello"
    assert_equal "hello", @s.val
    assert_equal "h", @s[0]
    assert_equal "e", @s[1]
  end

  def test_slice_tatara_string
    @s = Tatara::String.new << "hello"
    assert_equal "hello", @s.val
    assert_equal "hel", @s.slice(0, 3)
    assert_equal "hell", @s.slice(0, 4)
  end

  def test_slice_des_tatara_string
    @s = Tatara::String.new << "hello"
    assert_equal "hello", @s.val
    @s.slice!(0, 3)
    assert_equal "hel", @s.val
  end
end