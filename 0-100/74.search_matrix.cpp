/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchLind(vector<int> &line, int target) {
        int mini = 0; 
        int maxa = line.size() - 1;
        if (line[maxa] == target || line[0] == target) {
            return true;
        }

        int mid, tmp;
        while (maxa - mini > 1) {
            mid = (maxa + mini)/2;
            tmp = line[mid];
            if (tmp == target) {
                return true;
            } else if (tmp > target) {
                maxa = mid;
            } else {
                mini = mid;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int mini = 0; 
        int maxa = matrix.size() - 1;
        if (matrix[mini][0] > target || matrix[maxa][matrix[0].size()-1] < target) {
            return false;
        }
        if (matrix[mini][0] == target || matrix[maxa][matrix[0].size()-1] == target) {
            return true;
        }
        int mid, tmp;
        while (maxa - mini >1) {
            mid = (maxa + mini)/2;
            tmp = matrix[mid][0];
            if (tmp == target) {
                return true;
            } else if (tmp > target) {
                maxa = mid;
            } else {
                mini = mid;
            }
        }
        int lino = mini;
        return searchLind(matrix[lino], target) || 
                (matrix[maxa][0] <= target && searchLind(matrix[maxa], target));
    }
};

vector<vector<int>> dataset{
  {1,   3,  5,  7},
  {10, 11, 16, 20},
  {23, 30, 34, 50}
};

int main() {
    Solution s;
    for (auto i=0; i<55; i++) {
        if (s.searchMatrix(dataset, i)) {
            cout << "found     " << i << endl;
        } else {
            cout <<"not found " << i << endl;
        }
    }
    int tmp;
    cin>> tmp;
}

