/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */
// TODO
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
#include "./dbg.h"
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
    bool isValidSerialization(string preorder) {
        vector<string> symbols;
        
        int p = 0, i = 0;
        for(;i < preorder.length(); i++) {
            if(preorder[i] == ',') {
                symbols.push_back(preorder.substr(p, i - p));
                p = i + 1;
            }
        }
        symbols.push_back(preorder.substr(p, i - p));
        dbg(symbols);

        int cnt = symbols.size();
        if(cnt < 3) return false;
        
        vector<string> s(cnt, "");
        int idx = 0;
        i = 0;
        string c = symbols[idx];
        
        while(idx < cnt) {
            cout << "c = " << c << ", ";
            if(i >= 2 && c == "#" && s[i-1] == "#" && s[i-2] != "#") {
                i -= 2;
                s[i] = "#";
            } else {
                s[i++] = c;
                c = symbols[++idx];
            }
            for(int k = 0; k <= i; ++k) {
                cout << s[k] << " ";
            }
            cout << ", i = " << i << endl;
        }
        return i == 0 && s[i] == "#";
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
        auto res = s.isValidSerialization(str);
        cout << res << endl;
        cout << "----------------------------------------------------" << endl;
    }
    return 0;
}
