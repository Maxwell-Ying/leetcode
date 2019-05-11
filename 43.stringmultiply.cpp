#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return string("0");
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    vector<int> tmp(num1.size() +num2.size(), 0);

    int mid = 0;

    for (auto i=0; i<num1.size(); i++) {
      for (auto j=0; j<num2.size(); j++) {
        mid = (num1[i] - '0') * (num2[j] - '0');
        tmp[i+j] += mid%10;
        tmp[i+j+1] += mid/10;
      }
    }

    for (auto i=0; i<tmp.size()-1; i++) {
      if (tmp[i]>=10) {
        tmp[i+1] += tmp[i]/10;
        tmp[i] %= 10;
      }
    }

    if (tmp.back() == 0) {
      tmp.pop_back();
    }

    reverse(tmp.begin(), tmp.end());

    string ret;
    for (auto i : tmp) {
      ret.push_back(static_cast<char>(i+'0'));
    }
    return ret;
  }
};

string data1("123");
string data2("234");

int main() {
  Solution s;
  cout << s.multiply(data1, data2) << endl;
  return 0;
}