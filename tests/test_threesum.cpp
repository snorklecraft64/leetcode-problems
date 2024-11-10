#include "test_include.h"

class TestThreeSum : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<int> input = {-1,0,1,2,-1,-4};
      std::vector<std::vector<int>> expected = {{-1,-1,2},{-1,0,1}};
      std::vector<std::vector<int>> value = Problems::three_sum(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<int> input = {0,1,1};
      std::vector<std::vector<int>> expected = {};
      std::vector<std::vector<int>> value = Problems::three_sum(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::vector<int> input = {0,0,0};
      std::vector<std::vector<int>> expected = {{0,0,0}};
      std::vector<std::vector<int>> value = Problems::three_sum(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestThreeSum() : Test("ThreeSum",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3}})
    {}
    
};