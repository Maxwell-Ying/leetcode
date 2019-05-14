#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int threeSumClosest1(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int current = nums[0] + nums[1] + nums[2];
    int s;
    for (auto i=0; i<nums.size(); i++) {
      for (auto j=i+1; j<nums.size(); j++) {
        for (auto k=j+1; k<nums.size(); k++) {
          s = nums[i] + nums[j] + nums[k];
          if (s== target) {
            return target;
          } else {
            if (abs(s-target) < abs(current - target)) {
              current = s;
            }
          }
        }
      }
    }
    return current;
  }

  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int current = nums[0] + nums[1] + nums[2];
    int s;
    for (auto i=0; i<nums.size()-2; i++) {
      int begin = i+1;
      int end = nums.size()-1;
      while (end > begin) {
        s = nums[begin] + nums[end] + nums[i];
        if (s == target) {
          return target;
        }
        if (abs(s-target) < abs(current-target)) {
          current = s;
        }
        if (s<target) {
          begin ++;
        } else {
          end --;
        }
      }
    }
    return current;
  } 
};

vector<int> data1{1,1,1,0};
int tar = -100;

int main() {
  Solution s;
  cout << s.threeSumClosest(data1, tar) << endl;
  return 0;
}