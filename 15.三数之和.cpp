/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int a, b, c;
        for(int i = 0; i < n-2; ++i) {
            a = nums[i];
            for(int j = 1; j < (n-i)/2; ++j) {
                b = nums[j];
                c = nums[n-j];
                if(a+b+c==0)
                    cout << a << " " << b << " " << c << endl;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums{-1, 0, 1, 2, -1, -4};
    s.threeSum(nums);
    
    return 0;
}

// @lc code=end

