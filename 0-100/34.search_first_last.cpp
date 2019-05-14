#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
      return vector<int>{-1, -1};
    }

    int begin = searchFloat(nums, target-0.5);
    int end = searchFloat(nums, target + 0.5);
    
    if (begin == end) {
      return vector<int>{-1, -1};
    }
    return vector<int>{begin+1, end};
  }
  int searchFloat(vector<int>& nums, float target) {
    if (target < nums[0]) {
      return -1;
    }
    if (target > nums[nums.size()-1]) {
      return nums.size() -1;
    }
    size_t begin = 0, end = nums.size()-1;
    size_t mid = (begin+end)/2;
    while (mid != begin) {
      if (nums[begin]< target && nums[mid]> target) {
        end = mid;
      } else {
        begin = mid;
      }
      mid = (begin+end)/2;
    }
    return begin;
  }
};

vector<int> data1{5,7,7,8,8,10};
int data2=8;

int main() {
  Solution s;
  auto tmp = s.searchRange(data1, data2);
  cout << tmp[0] << " " << tmp[1] << endl;
  return 0;
}