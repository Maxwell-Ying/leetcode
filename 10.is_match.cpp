#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    if (s.empty()) {
      if (p.size() % 2) {
        return false;
      }
      for (auto i=0; i<p.size(); i+=2) {
        if (p[i+1] != '*') {
          return false;
        }
      }
      return true;
    }
    if (p.size() == 0) {
      return false;
    }
    if (p.size() >= 2 && p[1] == '*') {
      return (equal(p[0], s[0]) && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
    }
    return equal(p[0], s[0]) && isMatch(s.substr(1), p.substr(1));
  }

  bool equal(char a, char b) {
    return a == '.' || b == '.' || a == b;
  }
};

string data1("aab");
string data2("c*a*b");

int main() {
  Solution s;
  cout << s.isMatch(data1, data2);
  return 0;
}