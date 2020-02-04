require "test_helper"
require "tatara"

class AnyTest < Minitest::Test

  def test_init_tatara_any
    @a = Tatara::Any.new
    refute_nil @a
    assert_nil @a.value
  end

  def test_assignment_tatara_any
    @a = Tatara::Any.new
    assert_nil @a.value
    @a.value = 42
    assert_equal 42, @a.value
    @a.value = 4.2
    assert_equal 4.2, @a.value
    @a.value = "hello"
    assert_equal "hello", @a.value
  end

  def test_plus_tatara_any
    @a = Tatara::Any.new
    assert_nil @a.value
    @a.value = 42
    assert_equal 63, @a.value + 21
    @a.value = "hello"
    assert_equal "hellohello", @a.value + "hello"
    @a.value = 4.2
    assert_equal 6.3, (@a.value + 2.1).round(2)
  end

  def test_minus_tatara_any
    @a = Tatara::Any.new
    assert_nil @a.value
    @a.value = 42
    assert_equal 21, @a.value - 21
    @a.value = "hello"
    assert_raises(NoMethodError) { @a.value - "hello" }
    @a.value = 4.2
    assert_equal 2.1, (@a.value - 2.1).round(2)
  end
end