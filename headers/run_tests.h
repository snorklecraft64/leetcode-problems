#include "all_tests.h"
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>

std::unordered_map<std::string, Test> tests = {{"TrapRain", TestTrapRain()},
                                               {"Candy", TestCandy()},
                                               {"RomanToInt", TestRomanToInt()},
                                               {"IntToRoman", TestIntToRoman()},
                                               {"LastWordLength", TestLastWordLength()},
                                               {"LongestCommonPrefix", TestLongestCommonPrefix()},
                                               {"ReverseWords", TestReverseWords()},
                                               {"ZigZagConversion", TestZigZagConversion()},
                                               {"NeedleInHaystack", TestNeedleInHaystack()},
                                               {"FullJustify", TestFullJustify()},
                                               {"IsPalindrome", TestIsPalindrome()},
                                               {"IsSubsequence", TestIsSubsequence()}};
std::string helpMessage = "\n"
"  -a    run all tests\n"
"        use as first argument to run all tests of all problems\n"
"        use after problem name to run all tests for that problem\n"
"\n"
"  -p    define problem to test\n"
"        next argument should be name of problem\n"
"        followed by either '-a' or name of test\n"
"\n"
"  -v    set verbosity\n"
"        next argument should be an integer from 0 to 2 inclusive\n"
"      0 => only print on failure\n"
"      1 => don't print individual test results unless failure\n"
"      2 => print all test results and total results\n";

void runAllTests();
void setVerbosity(int v);