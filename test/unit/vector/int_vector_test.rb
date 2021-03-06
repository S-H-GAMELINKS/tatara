require "test_helper"
require "tatara"

class IntVectorTest < Minitest::Test

  def test_init_tatara_int_vector
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    @i.emplace_back(5)
    assert_equal 42, @i.first
    assert_equal 5, @i.last
  end

  def test_tatara_int_vector_first
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 42, @i.first
  end

  def test_tatara_int_vector_last
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 42, @i.last
    @i.emplace_back(5)
    assert_equal 5, @i.last
  end

  def test_tatara_int_vector_bracket
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 42, @i[0]
    @i[0] = 5
    assert_equal 5, @i[0]
  end

  def test_tatara_int_vector_size
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 1, @i.size
  end

  def test_tatara_int_vector_clear
    @i = Tatara::IntVector.new
    @i.emplace_back(42)
    assert_equal 1, @i.size
    @i.clear
    assert_equal 0, @i.size
  end

  def test_tatara_int_vector_sum
    @i = Tatara::IntVector.new

    3.times { @i.emplace_back(42) }

    assert_equal 126, @i.sum
  end

  def test_push_operator_tatara_int_vector
    @i = Tatara::IntVector.new
    @i << 42
    assert_equal 42, @i.first
    assert_equal 1, @i.size
  end

  def test_map_tatara_int_vector
    @i = Tatara::IntVector.new
    (1..10).each(&@i.method(:<<))
    val = 1 
    @i.map{|i| 
      assert_equal val, i
      val += 1
    }
  end

  def test_destructive_map_tatara_int_vector
    @i = Tatara::IntVector.new
    (1..10).each(&@i.method(:<<))
    @i.map!{|i| i * 2}
    val = 2
    @i.map{|i|
      assert_equal val, i
      val += 2
    }
  end

  def test_each_tatara_int_vector
    @i = Tatara::IntVector.new
    (1..10).each(&@i.method(:<<))
    val = 1
    @i.each{|i|
      assert_equal val, i
      val += 1
    }
  end

  def test_each_with_index_tatara_int_vector
    @i = Tatara::IntVector.new
    (1..10).each(&@i.method(:<<))
    val = 1
    index = 0
    @i.each_with_index{|v, i|
      assert_equal val, v
      assert_equal index, i
      val += 1
      index += 1
    }
  end

  def test_intersection_method_int_vector
    @i1 = Tatara::IntVector.new

    (1..10).each(&@i1.method(:<<))

    @i2 = Tatara::IntVector.new

    (10..20).each(&@i2.method(:<<))

    @i = @i1.intersection @i2

    @i.map{|i| assert_equal 10, i }
  end

  def test_intersection_operator_int_vector
    @i1 = Tatara::IntVector.new

    (1..10).each(&@i1.method(:<<))

    @i2 = Tatara::IntVector.new

    (10..20).each(&@i2.method(:<<))

    @i = @i1 & @i2

    @i.map{|i| assert_equal 10, i }
  end

  def test_sort_method_int_vector
    data = [4, 9, 1]
    @i = Tatara::IntVector.new
    data.each(&@i.method(:<<))
    @sorted = @i.sort
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @sorted[i]
      assert_equal false, v == @i[i]
    }
  end

  def test_destructive_sort_method_int_vector
    data = [4, 9, 1]
    @i = Tatara::IntVector.new
    data.each(&@i.method(:<<))
    @i.sort!
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @i[i]
    }
  end

  def test_reverse_method_int_vector
    data = [4, 1, 9]
    @i = Tatara::IntVector.new
    data.each(&@i.method(:<<))
    @reversed = @i.reverse
    data.reverse!
    data.each_with_index{|v, i|
      assert_equal v, @reversed[i]
    }
  end

  def test_destructitve_reverse_method_int_vector
    data = [4, 1, 9]
    @i = Tatara::IntVector.new
    data.each(&@i.method(:<<))
    @i.reverse!
    data.reverse!
    data.each_with_index{|v, i|
      assert_equal v, @i[i]
    }
  end

  def test_uniq_method_int_vector
    data = [1, 2, 3, 3]
    @i = Tatara::IntVector.new
    data.each(&@i.method(:<<))
    @i = @i.uniq
    data.uniq!
    data.each_with_index{|v, i|
      assert_equal v, @i[i]
    }    
  end

  def test_destructive_uniq_method_int_vector
    data = [1, 2, 3, 3]
    @i = Tatara::IntVector.new
    data.each(&@i.method(:<<))
    @i.uniq!
    data.uniq!
    data.each_with_index{|v, i|
      assert_equal v, @i[i]
    }    
  end

  def test_to_array_method_int_vector
    data = [1, 2, 3]
    @i = Tatara::IntVector.new
    data.each(&@i.method(:<<))
    result = @i.to_array
    assert_equal Array, result.class
    data.each_with_index{|v, i|
      assert_equal v, @i[i]
      assert_equal v, result[i]
    }
  end

  def test_slice_int_vector
    data = [1, 2, 3, 4, 5]
    @i = Tatara::IntVector.new
    data.each(&@i.method(:<<))
    @i = @i.slice(1, 3)
    data = data.slice(1, 3)
    data.each_with_index{|v, i|
      assert_equal v, @i[i]
    }
  end

  def test_destructive_slice_int_vector
    data = [1, 2, 3, 4, 5]
    @i = Tatara::IntVector.new
    data.each(&@i.method(:<<))
    @i.slice!(1, 3)
    data = data.slice(1, 3)
    data.each_with_index{|v, i|
      assert_equal v, @i[i]
    }
  end

  def test_to_json_int_vector
    @i = Tatara::IntVector.new
    (1..10).each(&@i.method(:<<))
    json = @i.to_json
    assert_equal String, json.class
    data = JSON.parse(json)
    assert_equal Array, data.class
  end

  def test_import_array_int_vector
    @i = Tatara::IntVector.new
    data = [1, 2, 3]
    @i.import_array data
    assert_equal 3, @i.size
    data.each_with_index{|v, i|
      assert_equal v, @i[i]
    }
  end

  def test_import_json_int_vector
    @i = Tatara::IntVector.new
    json = "[1, 2, 3]"
    @i.import_json json
    data = JSON.parse json
    assert_equal 3, @i.size
    data.each_with_index{|v, i|
      assert_equal v, @i[i]
    }
  end
end
