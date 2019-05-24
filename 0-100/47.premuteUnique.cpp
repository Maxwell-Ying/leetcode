// Given a collection of integers, return all possible permutations.


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        int new_item = nums[get.size()];
        if (i>0 && new_item == get[i-1]) {
          continue;
        }
        new_last.insert(new_last.begin()+i, new_item);
        ret.push_back(new_last);
      }
    }
    auto vret = vector<vector<int>>(ret.begin(), ret.end());
    sort(vret.begin(), vret.end());
    vret.erase(unique(vret.begin(), vret.end()), vret.end());
    return vret;
  }
};

int main() {
  return 0;
}