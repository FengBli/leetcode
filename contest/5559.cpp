//
// Created by Bailin Feng on 2020/11/28.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> p(n, 0), q(n, 0);
        int res = INT_MAX;
        for(int i = 0 ; i < n; ++i) {
            int a = 0, b = 0;
            int v = nums[i];
            for(int j = 0; j < i; ++j) {
                if(nums[j] >= v) a++;
            }
            for(int j = i+1; j < n; ++j) {
                if(nums[j] <= v) b++;
            }
            res = min(res, a+b);
        }
        return res;
    }
};