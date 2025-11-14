#include "test_include.h"

class TestRemoveElement : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<int> input = {3,2,2,3};
      int expected = 2;
      int value = Problems::remove_element(input, 3);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<int> input = {0,1,2,2,3,0,4,2};
      int expected = 5;
      int value = Problems::remove_element(input, 2);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestRemoveElement() : Test("RemoveElement",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2}})
    {}
};