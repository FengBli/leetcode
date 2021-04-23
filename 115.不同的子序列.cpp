/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
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
private:
	using vvi = std::vector<std::vector<int>>;
	using vi = std::vecotr<int>;

public:
	/* TODO */
    int numDistinct(string s, string t) {
       	int m = s.size();
	  	int n = t.size();
	
	   	vvi dp(m+1, vi(n+1, 0));
	   	dp[1][1] = (s[0] == t[0] ? 1 : 0);
	   	for(int i = 1; i <= m; ++i) {
			for(int j = i; j <= n; ++j) {
				
    			    
    		}
		}

		return 0;
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
    string str, ttr;
    Solution s;
    while( cin >> str >> ttr) {
        auto res = s.numDistinct(str, ttr);
    }
    return 0;
}
