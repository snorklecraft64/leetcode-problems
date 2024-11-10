#include "test_include.h"

class TestMaxWater : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<int> input = {1,8,6,2,5,4,8,3,7};
      int expected = 49;
      int value = Problems::max_water(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<int> input = {1,1};
      int expected = 1;
      int value = Problems::max_water(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_stepsup() {
      std::vector<int> input = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
      int expected = 100;
      int value = Problems::max_water(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_stepsdown() {
      std::vector<int> input = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
      int expected = 100;
      int value = Problems::max_water(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }
    
    static TEST_RETURN test_stepsupdown() {
      std::vector<int> input = {1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1};
      int expected = 50;
      int value = Problems::max_water(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_allsame() {
      std::vector<int> input = {2,2,2,2,2,2,2,2,2,2,2};
      int expected = 20;
      int value = Problems::max_water(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_zero() {
      std::vector<int> input = {0,0};
      int expected = 0;
      int value = Problems::max_water(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestMaxWater() : Test("MaxWater",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Steps Up", &test_stepsup},
       {"Steps Down", &test_stepsdown},
       {"Steps Up-Down", &test_stepsupdown},
       {"All Same", &test_allsame},
       {"Zero", &test_zero}})
    {}
    
};