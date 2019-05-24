#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int current = 0;
    for (auto i=0; i<nums.size(); i++) {
      if (i > current) {
        return false;
      }
      current = max(current, nums[i] + i);
      if (current >= nums.size()-1) {
        return true;
      }
    }
    return true;
  }
};