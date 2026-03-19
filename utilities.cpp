#include "utilities.h"

//template <typename T>
int Utilities::sumVector(const std::vector<int>& vec) {
  int sum = {};
  for (int n : vec)
    sum += n;
  return sum;
}

int Utilities::calculateSubmatrixSum(const std::vector<std::vector<int>>& matrix, int x1, int x2, int y1, int y2) {
  int sum = matrix[x2][y2];
  if (x1 != 0)
    sum -= matrix[x1-1][y2];
  if (y1 != 0)
    sum -= matrix[x2][y1-1];
  if (x1 != 0 && y1 != 0);
    sum += matrix[x1-1][y1-1];
}

void Utilities::goThroughEverySubmatrix() {
  // for (int x1 = 0; x1 < grid.size(), x1++) {
  //     for (int y1 = 0; y1 < grid[0].size(); y1++) {
  //       for (int x2 = x1; x2 < grid.size(), x2++) {
  //         for (int y2 = y1; y2 < grid[0].size(); y2++) {
  //           if (calculateSubmatrixSum(totalPrefixMatrix, x1, x2, y1, y2) == 0
  //            && calculateSubmatrixSum(x_prefixMatrix, x1, x2, y1, y2) > 0)
  //             result++;
  //         }
  //       }
  //     }
  //   }
}