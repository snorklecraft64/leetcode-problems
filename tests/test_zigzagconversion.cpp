#include "test_include.h"

class TestZigZagConversion : public Test {
  private:

    static TEST_RETURN test_leetcode1() {
      std::string input = "PAYPALISHIRING";
      std::string expected = "PAHNAPLSIIGYIR";
      std::string value = Problems::zigzag_conversion(input, 3);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode2() {
      std::string input = "PAYPALISHIRING";
      std::string expected = "PINALSIGYAHRPI";
      std::string value = Problems::zigzag_conversion(input, 4);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_leetcode3() {
      std::string input = "A";
      std::string expected = "A";
      std::string value = Problems::zigzag_conversion(input, 1);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_helloworld() {
      std::string input = "Hello,World!";
      std::string expected = "HWe,o!lordll";
      std::string value = Problems::zigzag_conversion(input, 4);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_longrant() {
      std::string input = "IamtypinginZigZagrightnow,shouldbeinabout20rows";
      std::string expected = "Ioabumattn2yi0peribondwglsiunoZhisg,Zwaognrtihg";
      std::string value = Problems::zigzag_conversion(input, 20);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_2rows() {
      std::string input = "tworows";
      std::string expected = "tooswrw";
      std::string value = Problems::zigzag_conversion(input, 2);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_toomanyrows() {
      std::string input = "toomanyrows!";
      std::string expected = "to!osmwaonry";
      std::string value = Problems::zigzag_conversion(input, 7);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

    static TEST_RETURN test_empty() {
      std::string input = "";
      std::string expected = "";
      std::string value = Problems::zigzag_conversion(input, 3);
      bool passed = expected == value;
      return Test::formatReturn(passed, value, expected);
    }

  public:

    TestZigZagConversion() : Test("ZigZagConversion",
      {{"Leetcode Example 1", &test_leetcode1},
       {"Leetcode Example 2", &test_leetcode2},
       {"Leetcode Example 3", &test_leetcode3},
       {"Hello World", &test_helloworld},
       {"Long Rant", &test_longrant},
       {"Two Rows", &test_2rows},
       {"Too Many Rows", &test_toomanyrows},
       {"Empty", &test_empty}})
    {}
    
};