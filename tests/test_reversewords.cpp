#include "test_include.h"

class TestReverseWords : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string input = "the sky is blue";
      std::string expected = "blue is sky the";
      std::string value = Problems::reverse_words(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string input = "  hello world  ";
      std::string expected = "world hello";
      std::string value = Problems::reverse_words(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::string input = "a good   example";
      std::string expected = "example good a";
      std::string value = Problems::reverse_words(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_long() {
      std::string input = " I don't  really like people that vote  only based on their identity politics. This country has worse  economic disparity than the gilded age, and instead of talking about their tax policy we argue about which candidate is the worst person.          ";
      std::string expected = "person. worst the is candidate which about argue we policy tax their about talking of instead and age, gilded the than disparity economic worse has country This politics. identity their on based only vote that people like really don't I";
      std::string value = Problems::reverse_words(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_empty() {
      std::string input = "";
      std::string expected = "";
      std::string value = Problems::reverse_words(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_whitespace() {
      std::string input = "   ";
      std::string expected = "";
      std::string value = Problems::reverse_words(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestReverseWords() : Test("ReverseWords",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"Long Rant", &test_long},
       {"Empty", &test_empty},
       {"Whitespace", &test_whitespace}})
    {}
    
};