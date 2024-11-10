#include "test_include.h"

class TestTwoSum2 : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<int> input = {2,7,11,15};
      int target = 9;
      p_int expected(0,1);
      p_int value = Problems::two_sum_2(input, target);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<int> input = {2,3,4};
      int target = 6;
      p_int expected(0,2);
      p_int value = Problems::two_sum_2(input, target);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::vector<int> input = {-1,0};
      int target = -1;
      p_int expected(0,1);
      p_int value = Problems::two_sum_2(input, target);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_equalelements() {
      std::vector<int> input = {2,2,3,3};
      int target = 4;
      p_int expected(0,1);
      p_int value = Problems::two_sum_2(input, target);
      bool passed = expected == value;
      if (!passed)
        return Test::formatReturn(false, value, expected);
      target = 6;
      expected = p_int(2,3);
      value = Problems::two_sum_2(input, target);
      passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_multipletargets() {
      std::vector<int> input = {1,4,7,8,9,12,18,20,22,25,26,30,37,50};
      std::vector<p_int_pint> inpAndExpect = {p_int_pint(11, p_int(1,2)),
                                              p_int_pint(47, p_int(8,9)),
                                              p_int_pint(80, p_int(11,13)),
                                              p_int_pint(63, p_int(10,12)),
                                              p_int_pint(19, p_int(0,6))};
      for (auto& pair : inpAndExpect) {
        auto value = Problems::two_sum_2(input, pair.first);
        if(pair.second != value)
          return Test::formatReturn(false, value, pair.second);
      }
      
      return Test::formatReturn(true, 0, 0);
    }

  public:

    TestTwoSum2() : Test("TwoSum2",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"Equal Elements", &test_equalelements},
       {"Multiple Targets", &test_multipletargets}})
    {}
    
};