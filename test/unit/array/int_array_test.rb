require "test_helper"
require "tatara"

class IntArrayTest < Minitest::Test
  def test_init_tatara_int_array
    refute_nil Tatara::IntArray.new
  end

  def test_tatara_int_array_first
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 42, @array.first
  end

  def test_tatara_int_array_last
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 42, @array.last
    @array.push(55)
    assert_equal 55, @array.last
  end

  def test_tatara_int_array_bracket
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 42, @array[0]
    @array[0] = 55
    assert_equal 55, @array[0]
  end

  def test_tatara_int_array_size
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 1, @array.size
  end

  def test_tatara_int_array_clear
    @array = Tatara::IntArray.new
    @array.push(42)
    assert_equal 1, @array.size
    @array.clear
    assert_equal 0, @array.size
  end

  def test_push_operator_tatara_int_array
    @array = Tatara::IntArray.new
    @array << 42
    assert_equal 1, @array.size
    assert_equal 42, @array.first
  end

  def test_map_tatara_int_array
    @i = Tatara::IntArray.new
    (1..10).each{|i| @i << i}
    val = 1 
    @i.map{|i| 
      assert_equal val, i
      val += 1
    }
  end

  def test_destructive_map_tatara_int_array
    @i = Tatara::IntArray.new
    (1..10).each{|i| @i << i}
    @i.map!{|i| i * 2}
    val = 2 
    @i.map{|i| 
      assert_equal val, i
      val += 2
    }
  end

  def test_each_tatara_int_array
    @i = Tatara::IntArray.new
    (1..10).each{|i| @i << i}
    val = 1
    @i.map{|i| 
      assert_equal val, i
      val += 1
    }
  end

  def test_each_with_index_tatara_int_array
    @i = Tatara::IntArray.new
    (1..10).each{|i| @i << i}
    val = 1
    index = 0
    @i.each_with_index{|v, i|
      assert_equal val, v
      assert_equal index, i
      val += 1
      index += 1
    }
  end

  def test_duplicate_method_int_array
    @i1 = Tatara::IntArray.new

    (1..10).each{|i| @i1 << i}

    @i2 = Tatara::IntArray.new

    (10..20).each{|i| @i2 << i}

    @i = @i1.duplicate @i2

    @i.map{|i| assert_equal 10, i }
  end

  def test_duplicate_operator_int_array
    @i1 = Tatara::IntArray.new

    (1..10).each{|i| @i1 << i}

    @i2 = Tatara::IntArray.new

    (10..20).each{|i| @i2 << i}

    @i = @i1 & @i2

    @i.map{|i| assert_equal 10, i }
  end
end