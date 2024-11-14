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

void printTestResult(std::string source, std::string name, std::string message) {
  std::cout << source << " =:= " << name << " => " << message << std::endl;
}

/**
 * Print result when all tests of this class are run
 */
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

/**
 * Checks verbosity setting before printing
 */
void Test::printResult(bool passed) {
  if (!passed || this->verbosity > 0)
    printResult_v1(passed, this->source);
}

/**
 * Checks verbosity setting to decide how to print
 */
bool Test::runTest(std::string name, testPtr test) {
  TEST_RETURN t = test();
  if (!t.passed || this->verbosity > 1)
    printTestResult(this->source, name, t.message);
  return t.passed;
}

void Test::runAll() {
  bool passed = true;
  for (auto const& test : this->tests) {
    if(!runTest(test.first, test.second))
      passed = false;
  }
  printResult(passed);
}

void Test::runOne(std::string testName) {
  auto it = this->tests.find(testName);
  if (it == this->tests.end())
    throw(testName + " is not a test in class " + this->source);
  Test::runTest(testName, it->second);
}

std::vector<std::string> Test::getTestNames() {
  std::vector<std::string> result;
  for (auto test : tests) {
    result.push_back(test.first);
  }
  return result;
}