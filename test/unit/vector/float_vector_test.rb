require "test_helper"
require "tatara"

class FloatVectorTest < Minitest::Test

  def test_init_tatara_float_vector
    refute_nil Tatara::FloatVector.new
  end

  def test_tatara_float_vector_first
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal 4.2, @f.first
  end

  def test_tatara_float_vector_last
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal 4.2, @f.last
    @f.emplace_back(5.5)
    assert_equal 5.5, @f.last
  end

  def test_tatara_float_vector_bracket
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal 4.2, @f[0]
    @f[0] = 5.5
    assert_equal 5.5, @f[0]
  end

  def test_tatara_float_vector_size
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal 1, @f.size
  end

  def test_tatara_float_vector_clear
    @f = Tatara::FloatVector.new
    @f.emplace_back(4.2)
    assert_equal 1, @f.size
    @f.clear
    assert_equal 0, @f.size
  end

  def test_tatara_float_vector_sum
    @f = Tatara::FloatVector.new

    3.times { @f.emplace_back(4.2) }

    assert_equal 12.6, @f.sum.round(2)
  end

  def test_push_operator_tatara_float_vector
    @f = Tatara::FloatVector.new
    @f << 4.2
    assert_equal 4.2, @f.first
    assert_equal 1, @f.size
  end

  def test_map_tatara_float_vector
    @f = Tatara::FloatVector.new
    (1..10).each(&@f.method(:<<))
    val = 1.0
    @f.map{|i| 
      assert_equal val, i
      val += 1
    }
  end

  def test_destructive_map_tatara_float_vector
    @i = Tatara::FloatVector.new
    (1..10).each(&@i.method(:<<))
    @i.map!{|i| i * 2.0}
    val = 2.0
    @i.map{|i|
      assert_equal val, i
      val += 2.0
    }
  end

  def test_each_tatara_float_vector
    @i = Tatara::FloatVector.new
    (1..10).each(&@i.method(:<<))
    val = 1.0
    @i.each{|i|
      assert_equal val, i
      val += 1.0
    }
  end

  def test_each_with_index_tatara_float_vector
    @f = Tatara::FloatVector.new
    (1..10).each(&@f.method(:<<))
    val = 1.0
    index = 0
    @f.each_with_index{|v, i|
      assert_equal val, v
      assert_equal index, i
      val += 1.0
      index += 1
    }
  end

  def test_duplicate_method_float_vector
    @f1 = Tatara::FloatVector.new

    (1..10).each(&@f1.method(:<<))

    @f2 = Tatara::FloatVector.new

    (10..20).each(&@f2.method(:<<))

    @f = @f1.duplicate @f2

    @f.map{|f| assert_equal 10.0, f }
  end

  def test_duplicate_operator_float_vector
    @f1 = Tatara::FloatVector.new

    (1..10).each(&@f1.method(:<<))

    @f2 = Tatara::FloatVector.new

    (10..20).each(&@f2.method(:<<))

    @f = @f1 & @f2

    @f.map{|f| assert_equal 10.0, f }
  end

  def test_sort_method_float_vector
    data = [4.2, 9.3, 1.2]
    @f = Tatara::FloatVector.new
    data.each(&@f.method(:<<))
    @sorted = @f.sort
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @sorted[i]
      assert_equal false, v == @f[i]
    }
  end

  def test_destructive_sort_method_float_vector
    data = [4.2, 9.3, 1.2]
    @f = Tatara::FloatVector.new
    data.each(&@f.method(:<<))
    @f.sort!
    data.sort!
    data.each_with_index{|v, i|
      assert_equal v, @f[i]
    }
  end
end
