#include "test_include.h"

class TestLongestNonrepeatingSubstring : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string input = "abcabcbb";
      int expected = 3;
      int value = Problems::longest_nonrepeating_substring(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string input = "bbbbb";
      int expected = 1;
      int value = Problems::longest_nonrepeating_substring(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::string input = "pwwkew";
      int expected = 3;
      int value = Problems::longest_nonrepeating_substring(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_length0() {
      std::string input = "";
      int expected = 0;
      int value = Problems::longest_nonrepeating_substring(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_length1() {
      std::string input = "p";
      int expected = 1;
      int value = Problems::longest_nonrepeating_substring(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_uniquecharacters() {
      std::string input = "abcdefghi";
      int expected = 9;
      int value = Problems::longest_nonrepeating_substring(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_alternatingcharacters() {
      std::string input = "abababababab";
      int expected = 2;
      int value = Problems::longest_nonrepeating_substring(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_big() {
      std::string input = "If someone knocks on my door at 3am, I'm getting my shotgun out of my safe. I'm not taking the chance again. I'll got to jail if I have to, but you ain't taking my stuff.";
      int expected = 10;
      int value = Problems::longest_nonrepeating_substring(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestLongestNonrepeatingSubstring() : Test("LongestNonrepeatingSubstring",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"Length 0", &test_length0},
       {"Length 1", &test_length1},
       {"String of Unique Characters", &test_uniquecharacters},
       {"String of Alternating Characters", &test_alternatingcharacters},
       {"Big String", &test_big}})
    {}
    
};