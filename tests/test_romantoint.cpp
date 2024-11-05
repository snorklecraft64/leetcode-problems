#include "test_include.h"

class TestRomanToInt : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string input = "III";
      int expected = 3;
      int value = Problems::roman_to_int(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string input = "LVIII";
      int expected = 58;
      int value = Problems::roman_to_int(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::string input = "MCMXCIV";
      int expected = 1994;
      int value = Problems::roman_to_int(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_random1() {
      std::vector<p_string_int> inpAndExpect = {p_string_int("DCCLVII", 757),
                                                p_string_int("CMXXXVI", 936),
                                                p_string_int("CDLXXXIX", 489),
                                                p_string_int("DXCVI", 596),
                                                p_string_int("CCXXIII", 223),
                                                p_string_int("DCCCLX", 860),
                                                p_string_int("LXVIII", 68),
                                                p_string_int("CCLIX", 259),
                                                p_string_int("DCCXLVIII", 748),
                                                p_string_int("DCXXII", 622)};
      int value;
      for (auto& pair : inpAndExpect) {
        value = Problems::roman_to_int(pair.first);
        if(pair.second != value)
          return Test::formatReturn(false, value, pair.second);
      }
      
      return Test::formatReturn(true, 0, 0);
    }

    static TEST_RETURN test_random2() {
      std::vector<p_string_int> inpAndExpect = {p_string_int("CMXXVI", 926),
                                                p_string_int("DCCXXIII", 723),
                                                p_string_int("DCLXXII", 672),
                                                p_string_int("CCCLVIII", 358),
                                                p_string_int("CXCIV", 194),
                                                p_string_int("III", 3),
                                                p_string_int("CDIX", 409),
                                                p_string_int("CCXX ", 220),
                                                p_string_int("CMXCVIII", 998),
                                                p_string_int("CMXI", 911)};
      int value;
      for (auto& pair : inpAndExpect) {
        value = Problems::roman_to_int(pair.first);
        if(pair.second != value)
          return Test::formatReturn(false, value, pair.second);
      }
      
      return Test::formatReturn(true, 0, 0);
    }

    static TEST_RETURN test_singles() {
      std::vector<p_string_int> inpAndExpect = {p_string_int("I", 1),
                                                p_string_int("V", 5),
                                                p_string_int("X", 10),
                                                p_string_int("L", 50),
                                                p_string_int("C", 100),
                                                p_string_int("D", 500),
                                                p_string_int("M", 1000)};
      int value;
      for (auto& pair : inpAndExpect) {
        value = Problems::roman_to_int(pair.first);
        if(pair.second != value)
          return Test::formatReturn(false, value, pair.second);
      }
      
      return Test::formatReturn(true, 0, 0);
    }

    static TEST_RETURN test_doubles() {
      std::vector<p_string_int> inpAndExpect = {p_string_int("IV", 4),
                                                p_string_int("IX", 9),
                                                p_string_int("XL", 40),
                                                p_string_int("XC", 90),
                                                p_string_int("CD", 400),
                                                p_string_int("CM", 900)};
      int value;
      for (auto& pair : inpAndExpect) {
        value = Problems::roman_to_int(pair.first);
        if(pair.second != value)
          return Test::formatReturn(false, value, pair.second);
      }
      
      return Test::formatReturn(true, 0, 0);
    }

  public:

    TestRomanToInt() : Test("RomanToInt",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"10 Random 1", &test_random1},
       {"10 Random 2", &test_random2},
       {"Singles", &test_singles},
       {"Doubles", &test_doubles}})
    {}
    
};