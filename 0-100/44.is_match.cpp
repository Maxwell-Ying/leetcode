#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    p = replace_multi_star(p);
    if (p.empty()) {
      return s.empty();
    }
    if (s.empty()) {
      return count_if(p.begin(), p.end(), [](char c){return c!='*';}) == 0;
    }
    if (p[0] == '*') {
      if (p.size() == 1) {
        return true;
      }
      auto pos = find(s.begin(), s.end(), p[1]);
      if (pos == s.end()) {
        return false;
      }
      return isMatch(s, p.substr(1)) || isMatch(s.substr(1), p);
    }
    if (eq(s[0], p[0])) {
      return isMatch(s.substr(1), p.substr(1));
    }
    return false;
  }
  bool eq(char a, char b) {
    if (a == '?' || b == '?') {
      return true;
    }
    return a == b;
  }
  string replace_multi_star(string s) {
    string ret;
    for (auto i:s) {
      if (!ret.empty() && i == '*' && ret.back() == '*') {
        continue;
      }
      ret.push_back(i);
    }
    return ret;
  }
};

string a = "acdcb";
string b = "a*c?b";

int main() {
  Solution s;
  cout << s.isMatch(a, b) << endl;
  return 0;
}