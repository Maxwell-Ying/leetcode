#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> basic;
    vector<int> nums;
    string ret;
    int b = 1;
    for (auto i=1; i<=n; i++) {
      nums.push_back(i);
      b *= i;
      basic.push_back(b);
    }
    basic.pop_back();
    reverse(basic.begin(), basic.end());
    for (auto i=0; i<n; i++) {
      int x = k/basic[i];
      ret.push_back('0'+nums[x]);
      nums.erase(nums.begin()+x);
      k = k%basic[i];
    }
    return ret;
  }
};
