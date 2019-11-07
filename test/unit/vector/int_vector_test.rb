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
    (1..10).each{|i| @i << i}
    val = 1 
    @i.map{|i| 
      assert_equal val, i
      val += 1
    }
  end

  def test_destructive_map_tatara_int_vector
    @i = Tatara::IntVector.new
    (1..10).each{|i| @i << i}
    @i.map!{|i| i * 2}
    val = 2
    @i.map{|i|
      assert_equal val, i
      val += 2
    }
  end

  def test_each_tatara_int_vector
    @i = Tatara::IntVector.new
    (1..10).each{|i| @i << i}
    val = 1
    @i.each{|i|
      assert_equal val, i
      val += 1
    }
  end

  def test_each_with_index_tatara_int_vector
    @i = Tatara::IntVector.new
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

  def test_duplicate_method_int_vector
    @i1 = Tatara::IntVector.new

    (1..10).each{|i| @i1 << i}

    @i2 = Tatara::IntVector.new

    (10..20).each{|i| @i2 << i}

    @i = @i1.duplicate @i2

    @i.map{|i| assert_equal 10, i }
  end
end
