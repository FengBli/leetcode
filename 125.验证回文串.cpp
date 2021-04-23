/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (46.56%)
 * Likes:    370
 * Dislikes: 0
 * Total Accepted:    223K
 * Total Submissions: 473.5K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
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
#include <ctype.h>

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

// @lc code=start
class Solution {
private:
    bool shouldSkipped(char c) { 
        return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
    }
public:

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i <= j) {
            while(shouldSkipped(s[i])) ++i;
            while(shouldSkipped(s[j])) --j;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            --j;
        }
        return true;
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

    while( std::getline(std::cin, str) ) {
        auto res = s.isPalindrome(str);
        std::cout << (res ? "YES" : "NO") << std::endl;
    }
    return 0;
}