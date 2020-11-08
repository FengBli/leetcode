/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TODO
    vector<int> bin_search(vector<int> &nums, int left, int right, int target){

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return bin_search(nums, 0, nums.size(), target);
    }
};
// @lc code=end

