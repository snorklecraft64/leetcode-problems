#include "test_include.h"

class TestNeedleInHaystack : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string haystack = "sadbutsad";
      std::string needle = "sad";
      int expected = 0;
      int value = Problems::needle_in_haystack(haystack, needle);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string haystack = "leetcode";
      std::string needle = "leeto";
      int expected = -1;
      int value = Problems::needle_in_haystack(haystack, needle);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_long() {
      std::string haystack = "Who even knows why, but at this point in my life I'm just like \"fuck it, I'll drink 4 cokes a day and let it be as it may\". Not really the best outlook tbh.";
      std::vector<p_string_int> inpAndExpect = {p_string_int("knows", 9),
                                                p_string_int("at this", 24),
                                                p_string_int("life", 44),
                                                p_string_int("fuck it", 64),
                                                p_string_int("4 cokes", 84),
                                                p_string_int("tbh", 152),
                                                p_string_int("whomst", -1),
                                                p_string_int("lol", -1)};
      int value;
      for (auto& pair : inpAndExpect) {
        value = Problems::needle_in_haystack(haystack, pair.first);
        if(pair.second != value)
          return Test::formatReturn(false, value, pair.second);
      }
      
      return Test::formatReturn(true, 0, 0);
    }

    static TEST_RETURN test_needlelarger() {
      std::string haystack = "leet";
      std::string needle = "leetcode";
      int expected = -1;
      int value = Problems::needle_in_haystack(haystack, needle);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_emptyhaystack() {
      std::string haystack = "";
      std::string needle = "leet";
      int expected = -1;
      int value = Problems::needle_in_haystack(haystack, needle);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_emptyneedle() {
      std::string haystack = "leet";
      std::string needle = "";
      int expected = -1;
      int value = Problems::needle_in_haystack(haystack, needle);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestNeedleInHaystack() : Test("NeedleInHaystack",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Find Mult in Long", &test_long},
       {"Needle Larger", &test_needlelarger},
       {"Empty Haystack", &test_emptyhaystack},
       {"Empty Needle", &test_emptyneedle}})
    {}
    
};