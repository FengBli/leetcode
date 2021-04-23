/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
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
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0; 
        int j = s.size() - 1;
        while( i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            --j;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0; //
        int j = s.size() - 1;
        bool r = true;
        while (i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                dbg(s.substr(i, j-i));
                dbg(s.substr(i+1, j-i));
                return isPalindrome(s.substr(i, j-i)) || isPalindrome(s.substr(i+1, j-i));
            }
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
    while( cin >> str ) {
        // dbg(str);
        
        bool res = s.validPalindrome(str);
        // reverse(str.begin(), str.end());
        // dbg(str);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}