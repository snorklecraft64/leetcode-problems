#include "test.h"


Test::Test() {
  this->source = "null";
  this->tests = {};
}
Test::Test(std::string source, std::map<std::string, testPtr> tests, int v){
  this->source = source;
  this->tests = tests;
  this->verbosity = v;
}
Test::~Test() {}

//int Test::runOne(int test) {
//  if (test < numTests) {
//        return 0;
//      }
//      return -1;
//}
void printTestResult(std::string source, std::string name, std::string message) {
  std::cout << source << " =:= " << name << " => " << message << std::endl;
}

void printResult_v1(bool passed, std::string source) {
  for (auto c : source)
    std::cout << "-";
  std::cout << std::endl;
  if (passed)
    std::cout << source << " =:= All tests passed" << std::endl;
  else
    std::cout << source << " =:= ---One or more tests failed---" << std::endl;
  for (auto c : source)
    std::cout << "-";
  std::cout << std::endl;
}

void Test::printResult(bool passed, std::string source) {
  if (!passed || this->verbosity > 0)
    printResult_v1(passed, source);
}

bool Test::runTest(std::string source, std::string name, testPtr test) {
  TEST_RETURN t = test();
  if (this->verbosity > 1)
    printTestResult(source, name, t.message);
  else if (!t.passed)
    printTestResult(source, name, t.message);
  return t.passed;
}

void Test::runAll() {
  bool passed = true;
  for (auto const& test : this->tests) {
    if(!runTest(this->source, test.first, test.second))
      passed = false;
  }
  printResult(passed, this->source);
}

void Test::runOne(std::string testName) {
  auto it = this->tests.find(testName);
  if (it == this->tests.end())
    throw(testName + " is not a test in class " + this->source);
  Test::runTest(this->source, testName, it->second);
}
