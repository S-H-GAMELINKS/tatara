require "test_helper"
require "tatara"

class StringVectorTest < Minitest::Test

  def test_init_tatara_string_vector
    refute_nil Tatara::StringVector.new
  end

  def test_tatara_string_vector_first
    @s = Tatara::StringVector.new
    @s.emplace_back("42")
    assert_equal "42", @s.first
  end

  def test_tatara_string_vector_last
    @s = Tatara::StringVector.new
    @s.emplace_back("42")
    assert_equal "42", @s.last
    @s.emplace_back("5")
    assert_equal "5", @s.last
  end

  def test_tatara_string_vector_bracket
    @s = Tatara::StringVector.new
    @s.emplace_back("42")
    assert_equal "42", @s[0]
    @s[0] = "5"
    assert_equal "5", @s[0]
  end

  def test_tatara_string_vector_size
    @s = Tatara::StringVector.new
    @s.emplace_back("42")
    assert_equal 1, @s.size
  end

  def test_tatara_string_vector_clear
    @s = Tatara::StringVector.new
    @s.emplace_back("42")
    assert_equal 1, @s.size
    @s.clear
    assert_equal 0, @s.size
  end

  def test_tatara_string_vector_sum
    @s = Tatara::StringVector.new

    3.times { @s.emplace_back("42") }

    assert_equal @s.sum, "424242"
  end

  def test_push_operator_tatara_string_vector
    @s = Tatara::StringVector.new
    @s << "42"
    assert_equal "42", @s.first
    assert_equal 1, @s.size
  end

  def test_map_tatara_float_vector
    @s = Tatara::StringVector.new
    ("A".."K").each(&@s.method(:<<))
    val = "A"
    @s.map{|s| 
      assert_equal val, s
      val.succ!
    }
  end

  def test_destructive_map_tatara_string_vector
    @s = Tatara::StringVector.new
    ("A".."K").each(&@s.method(:<<))
    @s.map!{|s| s.succ}
    val = "B"
    @s.map{|s|
      assert_equal val, s
      val.succ!
    }
  end

  def test_each_tatara_string_vector
    @s = Tatara::StringVector.new
    ("A".."K").each(&@s.method(:<<))
    val = "A"
    @s.each{|s|
      assert_equal val, s
      val.succ!
    }
  end

  def test_each_with_index_tatara_int_vector
    @s = Tatara::StringVector.new
    ("A".."K").each(&@s.method(:<<))
    val = "A"
    index = 0
    @s.each_with_index{|v, i|
      assert_equal val, v
      assert_equal index, i
      val.succ!
      index += 1
    }
  end

  def test_intersection_method_string_vector
    @s1 = Tatara::StringVector.new

    ("A".."K").each(&@s1.method(:<<))

    @s2 = Tatara::StringVector.new

    ("K".."T").each(&@s2.method(:<<))

    @s = @s1.intersection @s2

    @s.map{|i| assert_equal "K", i }
  end

  def test_intersection_operator_string_vector
    @s1 = Tatara::StringVector.new

    ("A".."K").each(&@s1.method(:<<))

    @s2 = Tatara::StringVector.new

    ("K".."T").each(&@s2.method(:<<))

    @s = @s1 & @s2

    @s.map{|i| assert_equal "K", i }
  end

  def test_sort_method_string_vector
    data = ["4", "9", "1"]
    @s = Tatara::StringVector.new
    data.each(&@s.method(:<<))
    @sorted = @s.sort
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @sorted[i]
      assert_equal false, v == @s[i]
    }
  end

  def test_destructive_sort_method_string_vector
    data = ["4", "9", "1"]
    @s = Tatara::StringVector.new
    data.each(&@s.method(:<<))
    @s.sort!
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }
  end

  def test_reverse_method_string_vector
    data = ["4", "1", "9"]
    @s = Tatara::StringVector.new
    data.each(&@s.method(:<<))
    @reversed = @s.reverse
    data.reverse!
    data.each_with_index{|v, i|
      assert_equal v, @reversed[i]
    }
  end

  def test_destructive_reverse_method_string_vector
    data = ["4", "1", "9"]
    @s = Tatara::StringVector.new
    data.each(&@s.method(:<<))
    @s.reverse!
    data.reverse!
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }
  end

  def test_uniq_method_int_vector
    data = ["1", "2", "3", "3"]
    @s = Tatara::StringVector.new
    data.each(&@s.method(:<<))
    @s = @s.uniq
    data.uniq!
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }    
  end

  def test_destructive_uniq_method_int_vector
    data = ["1", "2", "3", "3"]
    @s = Tatara::StringVector.new
    data.each(&@s.method(:<<))
    @s.uniq!
    data.uniq!
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }    
  end

  def test_to_array_method_string_vector
    data = ["1", "2", "3"]
    @s = Tatara::StringVector.new
    data.each(&@s.method(:<<))
    result = @s.to_array
    assert_equal Array, result.class
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
      assert_equal v, result[i]
    }
  end

  def test_slice_string_vector
    data = ["1", "2", "3", "4", "5"]
    @s = Tatara::StringVector.new
    data.each(&@s.method(:<<))
    @s = @s.slice(1, 3)
    data = data.slice(1, 3)
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }
  end
end
