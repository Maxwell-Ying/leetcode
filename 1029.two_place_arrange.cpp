#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int total = 0;
    int length = costs.size()/2;
    int city0=0, city1=0;
    sort(costs.begin(), costs.end(), 
    [](vector<int>&a, vector<int> &b) {return a[0]-a[1]>b[0]-b[1];});
    for (auto i=0; i<length; i++) {
      total += costs[i][1];
    }
    for (auto i=length; i<costs.size(); i++) {
      total += costs[i][0];
    }
    return total;
  }
};

