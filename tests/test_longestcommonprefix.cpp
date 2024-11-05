#include "test_include.h"

class TestLongestCommonPrefix : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<std::string> input = {"flower","flow","flight"};
      std::string expected = "fl";
      std::string value = Problems::longest_common_prefix(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<std::string> input = {"dog","racecar","car"};
      std::string expected = "";
      std::string value = Problems::longest_common_prefix(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_daddy() {
      std::vector<std::string> input = {"dad","daddy","dadda","dada"};
      std::string expected = "dad";
      std::string value = Problems::longest_common_prefix(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_emptyVec() {
      std::vector<std::string> input = {};
      std::string expected = "";
      std::string value = Problems::longest_common_prefix(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_emptyString1() {
      std::vector<std::string> input = {"","hello"};
      std::string expected = "";
      std::string value = Problems::longest_common_prefix(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_emptyString2() {
      std::vector<std::string> input = {"hello",""};
      std::string expected = "";
      std::string value = Problems::longest_common_prefix(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestLongestCommonPrefix() : Test("LongestCommonPrefix",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Daddy", &test_daddy},
       {"Empty Vector", &test_emptyVec},
       {"Empty String 1", &test_emptyString1},
       {"Empty String 2", &test_emptyString2}})
    {}
    
};