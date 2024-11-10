#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class Utilities {

  public:
    //template <typename T>
    static int sumVector(const std::vector<int>& vec);

    template<typename T>
    static std::string vectorToString(const std::vector<T>& vec) {
      std::string result;
      result += "{ ";
      for (int i = 0; i < vec.size()-1; i++) {
        result += std::to_string(vec[i]) + ", ";
      }
      result += std::to_string(vec.back()) + " }";
      return result;
    }

    template<typename T>
    static std::string vectorToString(const std::vector<std::vector<T>>& vec) {
      std::string result;
      result += "{ ";
      for (int i = 0; i < vec.size()-1; i++) {
        result += vectorToString(vec[i]) + ", ";
      }
      result += vectorToString(vec.back()) + " }";
      return result;
    }
    
};

/**
 * inline overload for string case
 */
template<> inline
std::string Utilities::vectorToString(const std::vector<std::string>& vec) {
  std::string result = "";
  result += "{ ";
  for (int i = 0; i < vec.size()-1; i++) {
    result = result + "\"" + vec[i] + "\", ";
  }
  result += "\"" + vec.back() + "\" }";
  return result;
}