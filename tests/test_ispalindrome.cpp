#include "test_include.h"

class TestIsPalindrome : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string input = "A man, a plan, a canal: Panama";
      bool expected = true;
      bool value = Problems::is_palindrome(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string input = "race a car";
      bool expected = false;
      bool value = Problems::is_palindrome(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::string input = " ";
      bool expected = true;
      bool value = Problems::is_palindrome(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_internetexample1() {
      std::string input = "Mr. Owl ate my metal worm";
      bool expected = true;
      bool value = Problems::is_palindrome(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_internetexample2() {
      std::string input = "Do geese see God?";
      bool expected = true;
      bool value = Problems::is_palindrome(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_internetexample3() {
      std::string input = "Was it a car or a cat I saw?";
      bool expected = true;
      bool value = Problems::is_palindrome(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_almostpalindrome1() {
      std::string input = "ontotonto";
      bool expected = false;
      bool value = Problems::is_palindrome(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_almostpalindrome2() {
      std::string input = "detected";
      bool expected = false;
      bool value = Problems::is_palindrome(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_almostpalindrome3() {
      std::string input = "thought";
      bool expected = false;
      bool value = Problems::is_palindrome(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestIsPalindrome() : Test("IsPalindrome",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"Internet Example 1", &test_internetexample1},
       {"Internet Example 2", &test_internetexample2},
       {"Internet Example 3", &test_internetexample3},
       {"Almost Palindrome 1", &test_almostpalindrome1},
       {"Almost Palindrome 2", &test_almostpalindrome2},
       {"Almost Palindrome 3", &test_almostpalindrome3}})
    {}
    
};