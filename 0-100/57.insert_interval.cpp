#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ret;    
    vector<int> pool = newInterval;
    bool flag = false;
    for (auto i : intervals) {
      if (i[1] < pool[0]) {
        ret.push_back(i);
      } else if (i[0] > pool[1]) {
        if (!flag) {
          ret.push_back(pool);
          flag = true;
        }
        ret.push_back(i);
      } else {
        pool = merge(i, pool);
      }
      // cout << pool[0] << " " << pool[1] << endl;
    }
    if (!flag) {
      ret.push_back(pool);
    }
    return ret;
  }

  vector<int> merge(vector<int> a, vector<int> b) {
    return vector<int> {min(a[0], b[0]), max(a[1], b[1])};
  }
};