require "test_helper"
require "tatara/tatara"

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
    ("A".."K").each{|i| @s << i}
    val = "A"
    @s.map{|s| 
      assert_equal val, s
      val.succ!
    }
  end

  def test_destructive_map_tatara_string_vector
    @s = Tatara::StringVector.new
    ("A".."K").each{|s| @s << s}
    @s.map!{|s| s.succ}
    val = "B"
    @s.map{|s|
      assert_equal val, s
      val.succ!
    }
  end

  def test_each_tatara_string_vector
    @s = Tatara::StringVector.new
    ("A".."K").each{|s| @s << s.to_s}
    val = "A"
    @s.each{|s|
      assert_equal val, s
      val.succ!
    }
  end
end
