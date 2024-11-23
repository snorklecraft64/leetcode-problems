#include "test_include.h"

class TestMinWindowSubstring : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string s = "ADOBECODEBANC";
      std::string t = "ABC";
      std::string expected = "BANC";
      std::string value = Problems::min_window_substring(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string s = "a";
      std::string t = "a";
      std::string expected = "a";
      std::string value = Problems::min_window_substring(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::string s = "a";
      std::string t = "aa";
      std::string expected = "";
      std::string value = Problems::min_window_substring(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_noTinS() {
      std::string s = "abcwcbawbcaw";
      std::string t = "qoi";
      std::string expected = "";
      std::string value = Problems::min_window_substring(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_multipleSame() {
      std::string s = "abcccabbbcabcabcabcabc";
      std::string t = "aaabbbc";
      std::string expected = "abcabcab";
      std::string value = Problems::min_window_substring(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_discuss1() {
      std::string s = "aaaaaaaaaaaabbbbbcdd";
      std::string t = "abcdd";
      std::string expected = "abbbbbcdd";
      std::string value = Problems::min_window_substring(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_discuss2() {
      std::string s = "caccaacaaaabbcaccaccc";
      std::string t = "acccacbccc";
      std::string expected = "caaaabbcaccaccc";
      std::string value = Problems::min_window_substring(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_discuss3() {
      std::string s = "cbbbacccccbbbacbabbabacbabbbabaacbaccccbcbcbcca";
      std::string t = "abcbcabaacccababacbabcacbc";
      std::string expected = "acbabbabacbabbbabaacbaccccbcbc";
      std::string value = Problems::min_window_substring(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_discuss4() {
      std::string s = "babb";
      std::string t = "baba";
      std::string expected = "";
      std::string value = Problems::min_window_substring(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestMinWindowSubstring() : Test("MinWindowSubstring",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"No t in s", &test_noTinS},
       {"Multiple Same", &test_multipleSame},
       {"Discussion Example 1", &test_discuss1},
       {"Discussion Example 2", &test_discuss2},
       {"Discussion Example 3", &test_discuss3},
       {"Discussion Example 4", &test_discuss4}})
    {}
    
};