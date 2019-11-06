require "test_helper"
require "tatara"

class FloatArrayTest < Minitest::Test
  def test_init_tatara_float_array
    refute_nil Tatara::FloatArray.new
  end

  def test_tatara_float_array_first
    @array = Tatara::FloatArray.new
    @array.push(4.2)
    assert_equal 4.2, @array.first
  end

  def test_tatara_float_array_last
    @array = Tatara::FloatArray.new
    @array.push(4.2)
    assert_equal 4.2, @array.last
    @array.push(5.5)
    assert_equal 5.5, @array.last
  end

  def test_tatara_float_array_bracket
    @array = Tatara::FloatArray.new
    @array.push(4.2)
    assert_equal 4.2, @array[0]
    @array[0] = 5.5
    assert_equal 5.5, @array[0]
  end

  def test_tatara_float_array_size
    @array = Tatara::FloatArray.new
    @array.push(4.2)
    assert_equal 1, @array.size
  end

  def test_tatara_float_array_clear
    @array = Tatara::FloatArray.new
    @array.push(4.2)
    assert_equal 1, @array.size
    @array.clear
    assert_equal 0, @array.size
  end

  def test_push_operator_tatara_float_array
    @array = Tatara::FloatArray.new
    @array << 4.2
    assert_equal 1, @array.size
    assert_equal 4.2, @array.first
  end

  def test_map_tatara_float_array
    @f = Tatara::FloatArray.new
    (1..10).each{|f| @f << f}
    val = 1 
    @f.map{|f| 
      assert_equal val, f
      val += 1
    }
  end

  def test_decrement_map_tatara_float_array
    @f = Tatara::FloatArray.new
    (1..10).each{|f| @f << f.to_f}
    @f.map!{|f| f * 2.0}
    val = 2.0 
    @f.map{|f| 
      assert_equal val, f
      val += 2.0
    }
  end
end