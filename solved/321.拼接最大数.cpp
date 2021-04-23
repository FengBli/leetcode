/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
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
    // AC hard难度，耗时1小时10分钟。
    // 步骤：
private:
    vector<int> findKLargestSubarray(vector<int> &nums, int k) {
        if(nums.size() == k) return nums;
        auto start = nums.begin();
        auto end = nums.end() - k + 1;

        vector<int> res;
        for(int kk = 0;kk < k; kk++) {
            auto it = std::max_element(start, end);
            res.push_back(*it);
            start = it + 1;
            end++;
        }
        return res;
    }

    vector<int> myConcat(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 == 0) return nums2;
        if(n2 == 0) return nums1;

        string s1{""};
        string s2{""};
        for(auto num : nums1) {
            s1 += static_cast<char>(num+'0');
        }
        for(auto num : nums2) {
            s2 += static_cast<char>(num+'0');
        }
        

        vector<int> res;
        auto it = nums1.begin();
        auto jt = nums2.begin();
        while(it != nums1.end() && jt != nums2.end()) { 
            if(*it == *jt) {
                int i = it - nums1.begin();
                int j = jt - nums2.begin();
                string is = s1.substr(i, n1 - i);
                string js = s2.substr(j, n2 - j);

                if(is > js) {
                res.push_back(*it);
                it++;
                } else {
                    res.push_back(*jt);
                    jt++;
                }
            } else if(*it > *jt) {
                res.push_back(*it);
                it++;
            } else {
                res.push_back(*jt);
                jt++;
            }
        }

        if(it != nums1.end()) {
            res.insert(res.end(), it, nums1.end());
        } else if(jt != nums2.end()) {
            res.insert(res.end(), jt, nums2.end());
        }

        return res;
    }

    vector<int> myMax(vector<int> &nums1, vector<int> &nums2) {
        string s1{""};
        string s2{""};
        for(auto num : nums1) {
            s1 += static_cast<char>(num+'0');
        }
        for(auto num : nums2) {
            s2 += static_cast<char>(num+'0');
        }

        if(s1 > s2) return nums1;
        else return nums2;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(0 == n1 && 0 == n2) return vector<int>();

        int ii = (n1 > k) ? k : n1;
        vector<int> res(k, 0);
        for(int i = 0; i <= ii; ++i) {
            if(k-i > n2) continue;
            if(i > n1) break;
            vector<int> maxsub1 = findKLargestSubarray(nums1, i);
            vector<int> maxsub2 = findKLargestSubarray(nums2, k-i);
            vector<int> r = myConcat(maxsub1, maxsub2);
            res = myMax(res, r);
        }
        return res;
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
    string str, str2;
    int k;
    Solution s;
    while( cin >> str >> str2 >> k) {
        vi nums1 = stringToIntegerVector(str);
        vi nums2 = stringToIntegerVector(str2);
        auto res = s.maxNumber(nums1, nums2, k);
        dbg(nums1.size() + nums2.size() == k);
        dbg(res);
    }
    return 0;
}

/*
[5,6,8]
[6,4,0]
3
[2,1,7,8,0,1,7,3,5,8,9,0,0,7,0,2,2,7,3,5,5]
[2,6,2,0,1,0,5,4,5,5,3,3,3,4]
35
[3,4,6,5]
[9,1,2,5,8,3]
5
[6,7]
[6,0,4]
5
[3,9]
[8,9]
3
[3,9]
[8,9]
4
[0,0,0]
[1]
2
[]
[1,2,3,4,5]
2
[6,7]
[6,0,4]
5
[]
[1]
1
[5,6,8]
[6,4,0]
3
*/