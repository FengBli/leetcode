/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#pragma GCC optimize("Ofast")
#define DBG_MACRO_NO_WARNING
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;

#ifdef LOCAL
#include "dbg.h"
#endif

#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define REP(x, l, u) for(ll x = l; x < u; x++)

using ll = long long;
using ull = unsigned long long;
using vvi = vector<vector<int>>;
using vvs = std::vector<std::vector<std::string>>;
using pii = std::pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

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

vector<vector<string> > stringToStringVectorVector(string input) {
    vector<vector<string> > output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ']';
    getline(ss, item, delim);
    if(!item.empty()) {
        output.push_back(stringToStringVector(item + "]"));
    }
    while(getline(ss, item, delim)) {
        item = item.substr(1, item.length() - 1);
        output.push_back(stringToStringVector(item + "]"));
    }
    return output;
}

ostream& operator<<(ostream& output, const vector<int> & nums) {
    for(auto i : nums) {
        output << i << " ";
    }
    return output;
}

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == target) return vector<int> {i + 1, j + 1};
            else if(sum > target) j--;
            else i++;
        }
        return vector<int> {-1, -1};
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
    int n;
    while( cin >> str >> n) {
        vi nums = stringToIntegerVector(str);
        auto res = s.twoSum(nums, n);
        cout << res << endl;
    }
    return 0;
}