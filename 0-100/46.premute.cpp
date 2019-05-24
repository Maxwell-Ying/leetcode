// Given a collection of distinct integers, return all possible permutations.
// 无重复 全排列

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    deque<vector<int>> ret;
    ret.push_back(vector<int>{nums[0]});
    while (1) {
      vector<int> get = ret.front();
      if (get.size() >= nums.size()) {
        break;
      }
      ret.pop_front();
      for (auto i=0; i<= get.size(); i++) {
        vector<int> new_last = get;
        new_last.insert(new_last.begin()+i, nums[get.size()]);
        ret.push_back(new_last);
      }
    }
    auto vret = vector<vector<int>>(ret.begin(), ret.end());
    sort(vret.begin(), vret.end());
    return vret;
  }
};

