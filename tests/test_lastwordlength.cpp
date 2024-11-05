#include "test_include.h"

class TestLastWordLength : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string input = "Hello World";
      int expected = 5;
      int value = Problems::length_of_last_word(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string input = "   fly me   to   the moon  ";
      int expected = 4;
      int value = Problems::length_of_last_word(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::string input = "luffy is still joyboy";
      int expected = 6;
      int value = Problems::length_of_last_word(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestLastWordLength() : Test("LastWordLength",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2}})
    {}
    
};