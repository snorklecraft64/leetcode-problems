#include "test_include.h"

class TestConcatenatedSubstrings : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string s = "barfoothefoobarman";
      std::vector<std::string> words = {"foo","bar"};
      std::vector<int> expected = {0,9};
      std::vector<int> value = Problems::concatenated_substrings(s, words);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string s = "wordgoodgoodgoodbestword";
      std::vector<std::string> words = {"word","good","best","word"};
      std::vector<int> expected;
      std::vector<int> value = Problems::concatenated_substrings(s, words);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::string s = "barfoofoobarthefoobarman";
      std::vector<std::string> words = {"bar","foo","the"};
      std::vector<int> expected = {6,9,12};
      std::vector<int> value = Problems::concatenated_substrings(s, words);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestConcatenatedSubstrings() : Test("ConcatenatedSubstrings",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3}})
    {}
    
};