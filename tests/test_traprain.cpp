#include "test_include.h"

class TestTrapRain : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
      int expected = 6;
      int value = Problems::trap_rainwater(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<int> input = {4,2,0,3,2,5};
      int expected = 9;
      int value = Problems::trap_rainwater(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_wholebucket() {
      std::vector<int> input = {5,4,2,3,2,1,4,5};
      int expected = 14;
      int value = Problems::trap_rainwater(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_stepdown() {
      std::vector<int> input = {10,9,8,9,8,7,8,7,6,7,6,5,6,5,4,5,4,3,4,3,2,3,2,1,2,1,0,1,0};
      int expected = 9;
      int value = Problems::trap_rainwater(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_stepup() {
      std::vector<int> input = {0,1,0,1,2,1,2,3,2,3,4,3,4,5,4,5,6,5,6,7,6,7,8,7,8,9,8,9,10};
      int expected = 9;
      int value = Problems::trap_rainwater(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_multibucket() {
      std::vector<int> input = {5,4,3,2,1,0,1,2,3,4,5,4,3,2,1,0,1,2,3,4,5,4,3,2,1,0,1,2,3,4,5};
      int expected = 75;
      int value = Problems::trap_rainwater(input);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestTrapRain() : Test("TrapRain",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Whole Bucket", &test_wholebucket},
       {"Step Down", &test_stepdown},
       {"Step Up", &test_stepup},
       {"Multiple Buckets", &test_multibucket}})
    {}
    
};