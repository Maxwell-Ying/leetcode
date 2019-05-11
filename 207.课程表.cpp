#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourse, vector<pair<int, int>> & prerequisites) {
        if (numCourse <= 1 || prerequisites.size() <= 1) {
            return true;
        }
        unordered_map<int, vector<int>> graph;
        for (auto i : prerequisites) {
            graph[i.second].push_back(i.first);
        }
        bool changed = true;
        vector<int> finish_signal = vector<int> (numCourse, 0);
        while(changed){
            changed = false;
            for (auto i =0; i<numCourse; i++) {
                if (finish_signal[i]) {
                    continue;
                }
                auto iter = graph.find(i);
                if (iter == graph.end()) {
                    finish_signal[i] = 1;
                    changed = true;
                    continue;
                }
                bool maybe = true;
                for (auto j: iter->second) {
                    if (!finish_signal[j]) {
                        maybe = false;
                        break;
                    }
                }
                if (maybe) {
                    changed = true;
                    finish_signal[i] = 1;
                }
            }
        }
        return check(finish_signal);
    }

    bool check(vector<int> & signals) {
        for (auto const & i : signals) {
            if (! i) {
                return false;
            }
        }
        return true;
    }

    vector<int> getFinished(vector<pair<int, int>> & prerequisites) {
        vector<int> finished;
        vector<int> post;
        for (auto i: prerequisites) {
            post.push_back(i.second);
        }
        for (auto i: prerequisites) {
            if (find(post.begin(), post.end(), i.first) == post.end()) {
                finished.push_back(i.first);
            }
        }
        return finished;
    }
};

int main() {
    Solution s;
    vector<pair<int, int>> data;
    data.push_back(make_pair(0, 2));
    data.push_back(make_pair(1, 2));
    data.push_back(make_pair(2, 0));
    auto res = s.canFinish(3, data);
    cout << res << endl;
    return 0;
}