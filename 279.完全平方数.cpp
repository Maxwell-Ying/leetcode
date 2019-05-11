/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n < 4) {
            return n;
        }
        vector<int> sqs;
        int i=1;
        int sq = 1;
        while(sq <= n) {
            sqs.push_back(sq);
            i += 1;
            sq += 2*i+1;
        }
        return getnumber(sqs, n, i-1);
    }

    int getnumber(vector<int> sqs, int n, int maxi) {
        if (n < 4) {
            return n;
        }
        
    }
};

