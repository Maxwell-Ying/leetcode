// You are given an n x n 2D matrix representing an image.
// 给定一个 n × n 的二维矩阵表示一个图像。
// 将图像顺时针旋转 90 度。
// Rotate the image by 90 degrees (clockwise).
// in place
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int half_size = matrix.size() / 2;
    for (auto i=0; i<half_size; i++) {
      int left = i, right = matrix.size() -1 -i, top = left, bottom = right;
      int tmp;
      for (auto j=left; j< right; j++) {
        int other = matrix.size() - 1 - j;
        tmp = matrix[top][j];
        matrix[top][j] = matrix[other][left];
        matrix[other][left] = matrix[bottom][other];
        matrix[bottom][other] = matrix[j][right];
        matrix[j][right] = tmp;
      }
      print_matrix(matrix);
    }
  }
  void print_matrix(vector<vector<int>> & matrix) {
    for (const auto & i : matrix) {
      for (const auto j: i) {
        cout << j << " ";
      }
      cout << endl;
    }
  }
};



int main() {
  vector<vector<int>> data1;
  data1.push_back(vector<int>{1,2,3});
  data1.push_back(vector<int>{4,5,6});
  data1.push_back(vector<int>{7,8,9});
  Solution s;
  s.rotate(data1);
  return 0;
}
