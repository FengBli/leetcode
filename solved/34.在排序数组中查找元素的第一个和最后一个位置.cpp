/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    vector<int>::const_iterator binary_search_first(const vector<int> &nums, vector<int>::const_iterator l, vector<int>::const_iterator r,  int target) {

        if(l >= r) return (((*l) == target) ? l : nums.end());

        auto mt = l + (r-l)/2;
        if(*mt >= target) {
            auto t = binary_search_first(nums, l, mt-1, target);

            if(t != nums.end()) return t;
            else if(*mt == target) return mt;
            else return nums.end();
        }else{
            return binary_search_first(nums, mt+1, r, target);
        }
    }

    vector<int>::const_iterator binary_search_last(const vector<int>& nums, vector<int>::const_iterator l, vector<int>::const_iterator r, int target) {
        if(l >= r) return (*l) == target ? l : nums.end();

        auto mt = l + (r - l) / 2;
        if(*mt <= target) {
            auto t = binary_search_last(nums, mt+1, r, target);

            if(t != nums.end()) return t;
            else if(*mt == target) return mt;
            else return nums.end();
        } else {
            return binary_search_last(nums, l, mt-1, target);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return vector<int> {-1, -1};
        auto it = binary_search_first(nums, nums.begin(), nums.end()-1, target);
        auto jt = binary_search_last(nums, nums.begin(), nums.end()-1, target);
        if(it == nums.end() || jt == nums.end()) { return vector<int> {-1, -1};}
        return vector<int>{static_cast<int>(it - nums.begin()), static_cast<int>(jt - nums.begin())};
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
    int target;

    Solution s;
    while( cin >> str >> target) {
        auto nums = stringToIntegerVector(str);

        auto res = s.searchRange(nums, target);
        dbg(res);
    }
    return 0;
}

/*

[1,2,3,4,5,5,5,5,6,7,8] 6
[1,2,3,4,5,5,5,5,6,7,8] 0

*/