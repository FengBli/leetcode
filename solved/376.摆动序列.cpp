/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
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

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

vector<string> stringToStringVector(string input) {
    vector<string> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        item = item.substr(1, item.length() - 2);
        output.push_back(item);
    }
    return output;
}

vector<vector<int>> stringToIntegerVectorVector(string input) {
    vector<vector<int>> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ']';

    getline(ss, item, delim);
    if(item.size())
        output.push_back(stringToIntegerVector(item + "]"));

    while(getline(ss, item, delim)) {
        item = item.substr(1, item.size()-1);
        output.push_back(stringToIntegerVector(item + "]"));
    }
    return output;
}

// @lc code=start
class Solution {
public:
    // AC: DP解法。 
    int wiggleMaxLength_mine(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        vector<int> posDp(n, 1); // 定义posDp[i]为以ai结尾，并且尾部趋势为上升的最长摆动序列的长度
        vector<int> negDp(n, 1); // 定义类似

        auto posIt = posDp.begin();
        auto negIt = negDp.begin();

        for(int i = 0; i < n; i++) {
            int posMax = 0;
            int negMax = 0;
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    posMax = posMax > posDp[j] ? posMax : posDp[j]; // 找到上一个以上升结尾的子序列长度，与当前元素拼接
                } else if(nums[j] > nums[i]) {
                    negMax = negMax > negDp[j] ? negMax : negDp[j];
                }
                negDp[i] = posMax + 1;
                posDp[i] = negMax + 1;
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            res = (res > posDp[i]) ? res : posDp[i];
            res = (res > negDp[i]) ? res : negDp[i];
        }
        dbg(nums, res);
        return res;
    }


    // AC 题解，重新定义dp数组，
    int wiggleMaxLength(const std::vector<int> &nums) {
        int n = nums.size();
        if(n < 2) return n;

        std::vector<int> upDp(n, 1); // up[i]定义为以a[0..i]构造出的最长的结尾为上升的摆动序列的长度
        std::vector<int> downDp(n, 1);

        for(int i = 1; i < n; ++i) {
            if(nums[i]  < nums[i-1]) {
                downDp[i] = downDp[i-1];
                upDp[i] = max(downDp[i-1]+1, upDp[i-1]);
            } else if( nums[i] > nums[i-1]) {
                upDp[i] = upDp[i-1];
                downDp[i] = max(upDp[i-1]+1, downDp[i-1]);
            } else {
                upDp[i] = upDp[i-1];
                downDp[i] = downDp[i-1];
            }
        }

        return downDp[n-1] > upDp[n-1] ? downDp[n-1] : upDp[n-1];
    }
};
// @lc code=end


int main() {

    #ifdef LOCAL
        fr("0_in.tc");
        fw("0_out.tc");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string str;
    Solution s;
    while( cin >> str ) {
        auto nums = stringToIntegerVector(str);
        auto res = s.wiggleMaxLength(nums);
        cout << res << endl;
    }
    return 0;
}