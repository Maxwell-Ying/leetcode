/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return ;
        }
        int i;
        for (i=nums.size()-1; i>0; i--) {
            if (nums[i-1] < nums[i]) {
                break;
            }
        }
        int tmp;
        if (i == 0) {
            sort(nums.begin(), nums.end());
        } else {
            i-=1;
            for (int j=nums.size()-1; j>i; j--) {
                if (nums[j]>nums[i]) {
                    tmp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = tmp;
                    sort(nums.begin()+i+1, nums.end());
                    return;
                }
            }
        }
    }
};

vector<int> dataset {1,3,2};

int main() {
    Solution s;
    s.nextPermutation(dataset);
    for (auto i : dataset) {
        cout << i << " " ;
    }
    cout << endl;
    int tmp;
    cin>> tmp;
    return 0;
}

