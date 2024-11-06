#include "test_include.h"
#include <ostream>

class TestFullJustify : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<std::string> input = {"This", "is", "an", "example", "of", "text", "justification."};
      std::vector<std::string> expected =  {"This    is    an", "example  of text", "justification.  "};
      std::vector<std::string> value = Problems::full_justify(input, 16);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<std::string> input = {"What","must","be","acknowledgment","shall","be"};
      std::vector<std::string> expected =  {"What   must   be", "acknowledgment  ", "shall be        "};
      std::vector<std::string> value = Problems::full_justify(input, 16);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::vector<std::string> input = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
      std::vector<std::string> expected =  {"Science  is  what we", "understand      well", "enough to explain to", "a  computer.  Art is", "everything  else  we", "do                  "};
      std::vector<std::string> value = Problems::full_justify(input, 20);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_smallwidth() {
      std::vector<std::string> input = {"what","do","you","do","when","a","wood","chuck","comes","to","chuck","all","your","wood"};
      std::vector<std::string> expected =  {"what ","do   ","you  ", "do   ","when ","a    ","wood ","chuck","comes","to   ","chuck","all  ","your ","wood "};
      std::vector<std::string> value = Problems::full_justify(input, 5);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_bigwidth() {
      std::vector<std::string> input = {"what","do","you","do","when","a","wood","chuck","comes","to","chuck","all","your","wood"};
      std::vector<std::string> expected =  {"what do you do when a wood chuck comes to chuck all your wood                                       "};
      std::vector<std::string> value = Problems::full_justify(input, 100);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_perfect() {
      std::vector<std::string> input = {"what","do","you","do","when","a","wood","chuck","comes","to","chuck","all","your","wood"};
      std::vector<std::string> expected =  {"what do you do when a wood chuck comes to chuck all your wood"};
      std::vector<std::string> value = Problems::full_justify(input, 61);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_stress() {
      std::vector<std::string> input = {"what","do","you","do","when","a","wood","chuck","comes","to","chuck","all","your","wood?","I","would","chuck","that","wood","chuck","as","far","as","I","could,","to","chuck","wood","someplace","else"};
      std::vector<std::string> expected =  {"what    do","you     do","when     a","wood chuck","comes   to","chuck  all","your wood?","I    would","chuck that","wood chuck","as  far as","I   could,","to   chuck","wood      ","someplace ","else      "};
      std::vector<std::string> value = Problems::full_justify(input, 10);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestFullJustify() : Test("FullJustify",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"Small Width", &test_smallwidth},
       {"Big Width", &test_bigwidth},
       {"Perfect Justice", &test_perfect},
       {"Stress Test", &test_stress}})
    {}
    
};