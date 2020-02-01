require "test_helper"
require "tatara"

class AnyTest < Minitest::Test

  def test_init_tatara_any
    @a = Tatara::Any.new
    refute_nil @a
    assert_equal nil, @a.value
  end
end