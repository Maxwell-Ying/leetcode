/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
give an array of int and a target , find two int in nums whose sum is target, and return their locate.
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (auto i=0; i<nums.size(); i++) {
      auto get = map.find(target - nums[i]);
      if (get == map.end()) {
        map[nums[i]] = i;
      } else {
        return vector<int>{map[target-nums[i]], i};
      }
    }
    return vector<int> {0, 0};
  }
};

vector<int> data1{2,7,8,21};
int tar = 9;

int main() {
  Solution s;
  vector<int>a = s.twoSum(data1, tar);
  cout << a[0] << " " << a[1] << endl;
  return 0;
}