#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> tmp;

    sort(candidates.begin(), candidates.end());

    getcombination(candidates, target, 0, tmp, ret);

    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());

    return ret;
  }

  void getcombination(const vector<int> & candidates, int target, int start, vector<int>& tmp, vector<vector<int>> & ret) {
    if (target == 0) {
      ret.push_back(tmp);
      return;
    }

    if (start >= candidates.size()) {
      return;
    }

    while (start < candidates.size() && candidates[start] <= target) {
      tmp.push_back(candidates[start]);
      getcombination(candidates, target - candidates[start], start+1, tmp, ret);
      tmp.pop_back();
      start ++;
    }
  }
};

vector<int> data1{10,1,2,7,6,1,5};
int data2 = 8;

int main() {
  Solution s;
  auto tmp = s.combinationSum2(data1, data2);
  for (auto i : tmp) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}