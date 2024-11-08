#include "test_include.h"

class TestIsSubsequence : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string s = "abc";
      std::string t = "ahbgdc";
      bool expected = true;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string s = "axc";
      std::string t = "ahbgdc";
      bool expected = false;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_inverted() {
      std::string s = "cba";
      std::string t = "ahbgdc";
      bool expected = false;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_offbyone() {
      std::string s = "abc";
      std::string t = "ahbgd";
      bool expected = false;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_sempty() {
      std::string s = "";
      std::string t = "ahbgdc";
      bool expected = true;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_tempty() {
      std::string s = "abc";
      std::string t = "";
      bool expected = false;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_bothempty() {
      std::string s = "";
      std::string t = "";
      bool expected = true;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_none() {
      std::string s = "abc";
      std::string t = "hjgdlo";
      bool expected = false;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_wordinsentence() {
      std::string s = "hello";
      std::string t = "idontreallyknowwhattowritebuteventuallyswillbehidingsomewhereinhereohthereitwas";
      bool expected = true;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_wholealphabet() {
      std::string s = "abcdefghijklmnopqrstuvwxyz";
      std::string t = "agoatblamescatsdownunderforgratingtheircheezejankilymynanpouredporridgeonaqueersaturdayandtheywereverywettheycomplainedonxloudlythencaughtsomezs";
      bool expected = true;
      bool value = Problems::is_subsequence(s, t);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestIsSubsequence() : Test("IsSubsequence",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Inverted", &test_inverted},
       {"Off By One", &test_offbyone},
       {"S Empty", &test_sempty},
       {"T Empty", &test_tempty},
       {"Both Empty", &test_bothempty},
       {"None in T", &test_none},
       {"Word in Sentence", &test_wordinsentence},
       {"Whole Alphabet", &test_wholealphabet}})
    {}
    
};