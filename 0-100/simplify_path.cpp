#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <deque>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> q;
        string s;
        path += "/";
        for (auto i : path) {
            if (i == '/') {
                if (s == "..") {
                    if (!q.empty()) {
                        q.pop_back();
                    }
                } else if (s == ".") {
                    ;
                } else if (!s.empty()) {
                    q.push_back(s);
                }
                s.clear();
            } else {
                s.push_back(i);
            }
        }
        s.clear();
        while (!q.empty()) {
            s+="/"+q.front();
            q.pop_front();
        }
        if (s.empty()) {
            return "/";
        }
        return s;
    }
};

string data1 = "/../";

int main() {
    Solution s;
    cout << s.simplifyPath(data1) << endl;
    return 0;
}