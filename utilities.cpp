#include "utilities.h"

//template <typename T>
int Utilities::sumVector(const std::vector<int>& vec) {
  int sum = {};
  for (int n : vec)
    sum += n;
  return sum;
}