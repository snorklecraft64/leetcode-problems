#include "test_include.h"

class TestCandy : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<int> ratings = {1,0,2};
      int expected = 5;
      int value = Problems::candy(ratings);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<int> ratings = {1,2,2};
      int expected = 4;
      int value = Problems::candy(ratings);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_discuss1() {
      std::vector<int> ratings = {100, 80, 70, 60, 70, 80, 90, 100, 90, 80, 70, 60, 60};
      int expected = 35;
      int value = Problems::candy(ratings);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_discuss2() {
      std::vector<int> ratings = {6, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 1, 0};
      int expected = 42;
      int value = Problems::candy(ratings);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_discuss3() {
      std::vector<int> ratings = {20000, 20000, 16001, 16001, 16002, 16002, 16003, 16003, 16004, 16004, 16005, 16005, 16006, 16006, 16007, 16007, 16008, 16008, 16009, 16009, 16010, 16010, 16011, 16011, 16012, 16012, 16013, 16013, 16014, 16014, 16015, 16015, 16016, 16016, 16017, 16017, 16018, 16018, 16019, 16019, 16020, 16020, 16021, 16021, 16022, 16022, 16023, 16023, 16024, 16024};
      int expected = 74;
      int value = Problems::candy(ratings);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestCandy() : Test("Candy",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Discussion Example 1", &test_discuss1},
       {"Discussion Example 2", &test_discuss2},
       {"Discussion Example 3", &test_discuss3}})
    {}
    
};