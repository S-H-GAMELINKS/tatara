require "test_helper"
require "tatara"

class StringArrayTest < Minitest::Test
  def test_init_tatara_string_array
    refute_nil Tatara::StringArray.new
  end

  def test_tatara_string_array_first
    @array = Tatara::StringArray.new
    @array.push("42")
    assert_equal "42", @array.first
  end

  def test_tatara_string_array_last
    @array = Tatara::StringArray.new
    @array.push("42")
    assert_equal "42", @array.last
    @array.push("55")
    assert_equal "55", @array.last
  end

  def test_tatara_string_array_bracket
    @array = Tatara::StringArray.new
    @array.push("42")
    assert_equal "42", @array[0]
    @array[0] = "55"
    assert_equal "55", @array[0]
  end

  def test_tatara_string_array_size
    @array = Tatara::StringArray.new
    @array.push("42")
    assert_equal 1, @array.size
  end

  def test_tatara_string_array_clear
    @array = Tatara::StringArray.new
    @array.push("42")
    assert_equal 1, @array.size
    @array.clear
    assert_equal 0, @array.size
  end

  def test_push_operator_tatara_string_array
    @array = Tatara::StringArray.new
    @array << "42"
    assert_equal 1, @array.size
    assert_equal "42", @array.first
  end

  def test_map_tatara_string_array
    @s = Tatara::StringArray.new
    ("A".."K").each(&@s.method(:<<))
    val = "A" 
    @s.map{|s| 
      assert_equal val, s
      val.succ!
    }
  end

  def test_destructive_map_tatara_string_array
    @s = Tatara::StringArray.new
    ("A".."K").each(&@s.method(:<<))
    @s.map!{|s| s.succ!}
    val = "B" 
    @s.map{|s| 
      assert_equal val, s
      val.succ!
    }
  end

  def test_each_tatara_string_array
    @s = Tatara::StringArray.new
    ("A".."K").each(&@s.method(:<<))
    val = "A" 
    @s.map{|s| 
      assert_equal val, s
      val.succ!
    }
  end

  def test_each_with_index_tatara_string_array
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

  def test_intersection_method_string_array
    @s1 = Tatara::StringArray.new

    ("A".."K").each(&@s1.method(:<<))

    @s2 = Tatara::StringArray.new

    ("K".."T").each(&@s2.method(:<<))

    @s = @s1.intersection @s2

    @s.map{|s| assert_equal "K", s }
  end

  def test_intersection_operator_string_array
    @s1 = Tatara::StringArray.new

    ("A".."K").each(&@s1.method(:<<))

    @s2 = Tatara::StringArray.new

    ("K".."T").each(&@s2.method(:<<))

    @s = @s1 & @s2

    @s.map{|s| assert_equal "K", s }
  end

  def test_sort_method_string_array
    @s = Tatara::StringArray.new
    data = ["4", "9", "1"]
    data.each(&@s.method(:<<))
    @s = @s.sort
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }
  end

  def test_destructive_sort_method_string_array
    @s = Tatara::StringArray.new
    data = ["4", "9", "1"]
    data.each(&@s.method(:<<))
    @s.sort!
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }
  end

  def test_reverse_method_string_array
    data = ["4", "1", "9"]
    @s = Tatara::StringArray.new
    data.each(&@s.method(:<<))
    @s = @s.reverse
    data.reverse!
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }
  end

  def test_destructive_reverse_method_string_array
    data = ["4", "1", "9"]
    @s = Tatara::StringArray.new
    data.each(&@s.method(:<<))
    @s.reverse!
    data.reverse!
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }
  end

  def test_uniq_method_string_array
    data = ["1", "2", "3", "3"]
    @s = Tatara::StringArray.new
    data.each(&@s.method(:<<))
    @s = @s.uniq
    data.uniq!
    data.each_with_index{|v, i|
      assert_equal v, @s[i]
    }    
  end
end