#include "run_tests.h"

int main(int argc, char* argv[]) {
  try {
  if (argc < 2) 
    throw(std::string("at least one argument needed - use '--help' for more info"));

  if (std::string(argv[1]) == "--help") {
    std::cout << helpMessage << std::endl;
    return 0;
  }
  
  if (std::string(argv[1]) == "-a") {
    if (argc > 2) {
      if (std::string(argv[2]) == "-v") {
        if (argc > 3) {
          setVerbosity(std::stoi(argv[3]));
        }
      }
      else
        throw(std::string("only -v is allowed after -a is first"));
    }

    runAllTests();
  }
  else {
    int i = 1;
    bool isProblem = false;
    Test currClass = Test();
    bool isTest = false;
    bool isV = false;
    while (i < argc) {
      if (isProblem) {
        auto it = tests.find(argv[i]);
        if (it == tests.end())
          throw(std::string(argv[i]) + " is not a recognized problem");

        currClass = it->second;

        isTest = true;
        isProblem = false;
      }
      else if (isTest) {
        std::string argument(argv[i]);
        if (argument == "-a")
          currClass.runAll();
        else {
          currClass.runOne(argument);
        }

        isTest = false;
      }
      else if (isV) {
        setVerbosity(std::stoi(argv[i]));
        isV = false;
      }
      else if (std::string(argv[i]) == "-p")
        isProblem = true;
      else if (std::string(argv[i]) == "-v")
        isV = true;
      else {
        throw("argument unrecognized -> \"" + std::string(argv[i]) + "\"");
      }

      i++;
    }
    if (isProblem)
      throw(std::string("class name must be given after -c"));
    if (isTest)
      throw(std::string("either -a or a test name must be given after class name"));
  }
  }
  catch (std::string message) {
    std::cout << "failure: " << message;
  }
  catch (std::invalid_argument error) {
    std::cout << "failure: gave non-integer after -v";
  }
}

void runAllTests() {
  for (auto& test : tests) {
    test.second.runAll();
  }
}

void setVerbosity(int v) {
  for (auto& test : tests) {
    test.second.setVerbosity(v);
  }
}