#include <iostream>
#include <string>
#include <map>
#include <chrono>
#include <type_traits>

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

    //static void printStart(std::string source, std::string name);
    //static void printEnd(std::string message);
    void printResult(bool passed, std::string source);
  
    bool runTest(std::string source, std::string name, testPtr test);

  public:

    Test();
    Test(std::string source, std::map<std::string, testPtr> tests, int v = 2);
    ~Test();

    template<typename T>
    static TEST_RETURN formatReturn(bool passed, T value, T expected) {
      TEST_RETURN t;
      if (passed) {
        t.passed = true;
        t.message = "Passed";
      }
      else {
        t.passed = false;
        t.message = "---Failed---> Expected ( " + std::to_string(expected) + " ) but got ( " + std::to_string(value) + " ).";
      }
      return t;
    }

    void setVerbosity(int v) { this->verbosity = v; }

    // maybe try to implement this someday
    // intended to be a general purpose run test function
    //template<typename I, typename R>
    //static R run(I input, R (*func)(I)) {
    //  return func(input);
    //}

    void runAll();
    void runOne(std::string testName);
};

template<> inline
TEST_RETURN Test::formatReturn(bool passed, std::string value, std::string expected) {
  TEST_RETURN t;
  if (passed) {
    t.passed = true;
    t.message = "Passed";
  }
  else {
    t.passed = false;
    t.message = "---Failed---> Expected \"" + expected + "\" but got \"" + value + "\".";
  }
  return t;
}