#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int add_up = 0;
    string ret;
    int max_size = max(num1.size(), num2.size()) + 1;
    num1.resize(max_size, '0');
    num2.resize(max_size, '0');
    for (auto i=0; i<max_size; i++) {
      int re = num1[i] - '0' + num2[i] - '0' + add_up;
      ret.push_back(static_cast<char> (re%10+'0'));
      add_up = re/10;
    }
    if (ret.back() == '0') ret.pop_back();
    reverse(ret.begin(), ret.end());
    return ret;
  }
};