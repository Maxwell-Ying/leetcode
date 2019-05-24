#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ret;
    sort(intervals.begin(), intervals.end());
    if (intervals.empty()) {
      return ret;
    }
    vector<int> pool = intervals.front();
    for (auto i: intervals) {
      if (!(i[0]>pool[1] || pool[0]>i[1])) {
        pool = vector<int>{min(i[0], pool[0]), max(i[1], pool[1])};
      } else {
        ret.push_back(pool);
        pool = i;
      }
    }
    ret.push_back(pool);
    return ret;
  }
};