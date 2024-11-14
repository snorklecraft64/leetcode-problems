#include "test_include.h"

class TestMinSubarraySum : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<int> input = {2,3,1,2,4,3};
      int target = 7;
      int expected = 2;
      int value = Problems::min_subarray_sum(input, target);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<int> input = {1,4,4};
      int target = 4;
      int expected = 1;
      int value = Problems::min_subarray_sum(input, target);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::vector<int> input = {1,1,1,1,1,1,1,1};
      int target = 11;
      int expected = 0;
      int value = Problems::min_subarray_sum(input, target);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_lengthone1() {
      std::vector<int> input = {1};
      int target = 2;
      int expected = 0;
      int value = Problems::min_subarray_sum(input, target);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_lengthone2() {
      std::vector<int> input = {4};
      int target = 2;
      int expected = 1;
      int value = Problems::min_subarray_sum(input, target);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestMinSubarraySum() : Test("MinSubarraySum",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"Length One 1", &test_lengthone1},
       {"Length One 2", &test_lengthone2}})
    {}
    
};