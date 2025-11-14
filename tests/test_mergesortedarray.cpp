#include "test_include.h"

class TestMergeSortedArray : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::vector<int> nums1 = {1,2,3,0,0,0};
      int m = 3;
      std::vector<int> nums2 = {2,5,6};
      int n = 3;
      std::vector<int> expected = {1,2,2,3,5,6};
      Problems::merge_sorted_array(nums1, m, nums2, n);
      bool passed = nums1 == expected;
      return Test::formatReturn(passed, nums1, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::vector<int> nums1 = {1};
      int m = 1;
      std::vector<int> nums2 = {0};
      int n = 0;
      std::vector<int> expected = {1};
      Problems::merge_sorted_array(nums1, m, nums2, n);
      bool passed = nums1 == expected;
      return Test::formatReturn(passed, nums1, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::vector<int> nums1 = {0};
      int m = 0;
      std::vector<int> nums2 = {1};
      int n = 1;
      std::vector<int> expected = {1};
      Problems::merge_sorted_array(nums1, m, nums2, n);
      bool passed = nums1 == expected;
      return Test::formatReturn(passed, nums1, expected);
    }

  public:

    TestMergeSortedArray() : Test("MergeSortedArray",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3}})
    {}
    
};