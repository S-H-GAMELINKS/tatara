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
    (1..10).each(&@f.method(:<<))
    val = 1 
    @f.map{|f| 
      assert_equal val, f
      val += 1
    }
  end

  def test_decrement_map_tatara_float_array
    @f = Tatara::FloatArray.new
    (1..10).each(&@f.method(:<<))
    @f.map!{|f| f * 2.0}
    val = 2.0 
    @f.map{|f| 
      assert_equal val, f
      val += 2.0
    }
  end

  def test_each_tatara_float_array
    @f = Tatara::FloatArray.new
    (1..10).each(&@f.method(:<<))
    val = 1.0 
    @f.each{|f| 
      assert_equal val, f
      val += 1.0
    }
  end

  def test_each_with_index_tatara_float_array
    @f = Tatara::FloatArray.new
    (1..10).each(&@f.method(:<<))
    val = 1.0
    index = 0
    @f.each_with_index{|v, i|
      assert_equal val, v
      assert_equal index, i
      val += 1
      index += 1
    }
  end

  def test_intersection_method_float_array
    @f1 = Tatara::FloatArray.new

    (1..10).each(&@f1.method(:<<))

    @f2 = Tatara::FloatArray.new

    (10..20).each(&@f2.method(:<<))

    @f = @f1.intersection @f2

    @f.map{|i| assert_equal 10.0, i }
  end

  def test_intersection_operator_float_array
    @f1 = Tatara::FloatArray.new

    (1..10).each(&@f1.method(:<<))

    @f2 = Tatara::FloatArray.new

    (10..20).each(&@f2.method(:<<))

    @f = @f1 & @f2

    @f.map{|f| assert_equal 10.0, f }
  end

  def test_sort_method_float_array
    @f = Tatara::FloatArray.new
    data = [4, 9, 1]
    data.each(&@f.method(:<<))
    @f = @f.sort
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }
  end

  def test_destructive_sort_method_float_array
    @f = Tatara::FloatArray.new
    data = [4, 9, 1]
    data.each(&@f.method(:<<))
    @f.sort!
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }
  end

  def test_reverse_method_float_array
    data = [4, 1, 9]
    @f = Tatara::FloatArray.new
    data.each(&@f.method(:<<))
    @f.reverse!
    data.reverse!
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }
  end

  def test_uniq_method_float_array
    data = [1.1, 2.2, 3.3, 3.3]
    @f = Tatara::FloatArray.new
    data.each(&@f.method(:<<))
    @f = @f.uniq
    data.uniq!
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }    
  end

  def test_destructive_uniq_method_float_array
    data = [1.1, 2.2, 3.3, 3.3]
    @f = Tatara::FloatArray.new
    data.each(&@f.method(:<<))
    @f.uniq!
    data.uniq!
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }    
  end

  def test_to_array_method_float_array
    data = [1.0, 2.0, 3.0]
    @f = Tatara::FloatArray.new
    data.each(&@f.method(:<<))
    result = @f.to_array
    assert_equal Array, result.class
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
      assert_equal v, result[i]
    }
  end

  def test_slice_float_array
    data = [1, 2, 3, 4, 5]
    @f = Tatara::FloatArray.new
    data.each(&@f.method(:<<))
    @f = @f.slice(1, 3)
    data = data.slice(1, 3)
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }
  end

  def test_destructive_slice_float_array
    data = [1, 2, 3, 4, 5]
    @f = Tatara::FloatArray.new
    data.each(&@f.method(:<<))
    @f.slice!(1, 3)
    data = data.slice(1, 3)
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }
  end

  def test_to_json_float_array
    @f = Tatara::FloatArray.new
    (1..10).each(&@f.method(:<<))
    json = @f.to_json
    assert_equal String, json.class
    data = JSON.parse(json)
    assert_equal Array, data.class
  end

  def test_import_array_float_array
    @f = Tatara::FloatArray.new
    data = [1.0, 2.0, 3.0]
    @f.import_array data
    assert_equal 3, @f.size
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }
  end

  def test_import_json_float_array
    @f = Tatara::FloatArray.new
    json = "[1.0, 2.0, 3.0]"
    @f.import_json json
    data = JSON.parse json
    assert_equal 3, @f.size
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }
  end
end