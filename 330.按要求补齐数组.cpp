/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */
#pragma GCC optimize("Ofast")
#define DBG_MACRO_NO_WARNING
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>
#include <algorithm>
#include <sstream>

#ifdef LOCAL
#include "dbg.h"
#endif

#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define vi vector<int>

using namespace std;


// @lc code=start
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        map<int> nn(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i <= log2(n)+1; ++i) {
            if(nn.count(i) > 0) {

            } else {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

