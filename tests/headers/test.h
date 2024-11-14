#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "utilities.h"

struct TEST_RETURN {
  bool passed;
  std::string message;
};

typedef TEST_RETURN (*testPtr)();

class Test {
  private:
    std::string source;
    std::map<std::string, testPtr> tests;
    int verbosity;

    /**
     * Print formatted result of all tests being run
     */
    void printResult(bool passed);

    /**
     * Run the function 'test' from
     */
    bool runTest(std::string name, testPtr test);

    /**
     * Format fail message according to type
     */
    static std::string formatFail(int value, int expected) {
      return "---Failed---> Expected ( " + std::to_string(expected) + " ) but got ( " + std::to_string(value) + " ).";
    }
    static std::string formatFail(bool value, bool expected) {
      // use streams to convert bool to "true" or "false"
      std::ostringstream oss;
      oss << std::boolalpha << "---Failed---> Expected ( " << expected << " ) but got ( " << value << " ).";
      return oss.str();
    }
    static std::string formatFail(std::string value, std::string expected) {
      return "---Failed---> Expected ( " + expected + " ) but got ( " + value + " ).";
    }
    template<typename T>
    static std::string formatFail(std::vector<T> value, std::vector<T> expected) {
      return "---Failed---> Expected ( " + Utilities::vectorToString(expected) + " ) but got ( " + Utilities::vectorToString(value) + " ).";
    }
    template<typename T, typename U>
    static std::string formatFail(std::pair<T,U> value, std::pair<T,U> expected) {
      return "---Failed---> Expected ( " + std::to_string(expected.first) + " , " + std::to_string(expected.second) + " ) but got ( " + std::to_string(value.first) + " , " + std::to_string(value.second) + " ).";
    }

  public:

    Test();
    Test(std::string source, std::map<std::string, testPtr> tests, int v = 2);
    ~Test();

    /**
     * Create TEST_RETURN based on whether the test passed, the returned value, and the expected value
     */
    template<typename T>
    static TEST_RETURN formatReturn(bool passed, T value, T expected) {
      TEST_RETURN t;
      if (passed) {
        t.passed = true;
        t.message = "Passed";
      }
      else {
        t.passed = false;
        t.message = formatFail(value, expected);
      }
      return t;
    }

    void setVerbosity(int v) { this->verbosity = v; }

    std::vector<std::string> getTestNames();

    // maybe try to implement this someday
    // intended to be a general purpose run test function for ease of test implementation
    //template<typename I, typename R>
    //static R run(I input, R (*func)(I)) {
    //  return func(input);
    //}

    /**
     * Run all tests
     */
    void runAll();
    /**
     * Run test with the name 'testName'
     */
    void runOne(std::string testName);
};

///**
// * inline overload for formatReturn to allow use of string
// */
//template<> inline
//TEST_RETURN Test::formatReturn(bool passed, std::string value, std::string expected) {
//  TEST_RETURN t;
//  if (passed) {
//    t.passed = true;
//    t.message = "Passed";
//  }
//  else {
//    t.passed = false;
//    t.message = "---Failed---> Expected \"" + expected + "\" but got \"" + value + "\".";
//  }
//  return t;
//}