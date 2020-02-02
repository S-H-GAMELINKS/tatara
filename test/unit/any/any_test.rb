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
end