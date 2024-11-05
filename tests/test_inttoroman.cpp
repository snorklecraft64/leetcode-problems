#include "test_include.h"

class TestIntToRoman : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      int input = 3749;
      std::string expected = "MMMDCCXLIX";
      std::string value = Problems::int_to_roman(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      int input = 58;
      std::string expected = "LVIII";
      std::string value = Problems::int_to_roman(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      int input = 1994;
      std::string expected = "MCMXCIV";
      std::string value = Problems::int_to_roman(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_random() {
      std::vector<p_string_int> inpAndExpect = {p_string_int("MMMCL", 3150),
                                                p_string_int("CDXVI",416),
                                                p_string_int("DCCXIII",713),
                                                p_string_int("MCLXXII",1172),
                                                p_string_int("DLXXXIII",583),
                                                p_string_int("MMCDXXXII",2432),
                                                p_string_int("MMMXIX",3019),
                                                p_string_int("MCCXV",1215),
                                                p_string_int("MMCCXXXVI",2236),
                                                p_string_int("DLXX",570)};
      std::string value;
      for (auto& pair : inpAndExpect) {
        value = Problems::int_to_roman(pair.second);
        if(pair.first != value)
          return Test::formatReturn(false, value, pair.first);
      }
      
      return Test::formatReturn(true, 0, 0);
    }

    static TEST_RETURN test_singles() {
      std::vector<p_string_int> inpAndExpect = {p_string_int("M", 1000),
                                                p_string_int("D",500),
                                                p_string_int("C",100),
                                                p_string_int("L",50),
                                                p_string_int("X",10),
                                                p_string_int("V",5),
                                                p_string_int("I",1)};
      std::string value;
      for (auto& pair : inpAndExpect) {
        value = Problems::int_to_roman(pair.second);
        if(pair.first != value)
          return Test::formatReturn(false, value, pair.first);
      }
      
      return Test::formatReturn(true, 0, 0);
    }

    static TEST_RETURN test_doubles() {
      std::vector<p_string_int> inpAndExpect = {p_string_int("CM", 900),
                                                p_string_int("CD",400),
                                                p_string_int("XC",90),
                                                p_string_int("XL",40),
                                                p_string_int("IX",9),
                                                p_string_int("IV",4)};
      std::string value;
      for (auto& pair : inpAndExpect) {
        value = Problems::int_to_roman(pair.second);
        if(pair.first != value)
          return Test::formatReturn(false, value, pair.first);
      }
      
      return Test::formatReturn(true, 0, 0);
    }

  public:

    TestIntToRoman() : Test("IntToRoman",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"10 Random", &test_random},
       {"Singles", &test_singles},
       {"Doubles", &test_doubles}})
    {}
    
};