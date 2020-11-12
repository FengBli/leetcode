/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"

#define PB push_back
#define PF push_front
#define MP make_pair
#define se second
#define fi first
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define REP(x, l, u) for(ll x = l; x < u; x++)
#define RREP(x, l, u) for(ll x = l; x >= u; x--)

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

string to_string (string s) { return '"' + s + '"'; }
string to_string (const char *s) { return to_string ((string) s); }
string to_string (bool b) { return (b ? "true" : "false"); }

template<typename A, typename B>
string to_string (pair<A, B> p) { return "(" + to_string (p.first) + ", " + to_string (p.second) + ")"; }

template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for( const auto &x : v) {
        if(!first) {res += ", ";}
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out () { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out (T...);
}

#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]", debug_out(__VA_ARGS__)
#else
#define dbg(...) {}
#endif

// @lc code=start
class Solution {
public:
    // AC
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        int **dp = (int**) malloc(sizeof(int*)*(m+1));
        for(int i = 0; i < m+1; ++i) {
            dp[i] = (int*) malloc(sizeof(int)*(n+1));
            memset(dp[i], 0, sizeof(int)*(n+1));
        }
        for(int i = 0; i < n+1; ++i) {
            dp[0][i] = i;
        }
        for(int i = 0; i < m+1; ++i) {
            dp[i][0] = i;
        }

        for(int i = 1; i < m+1; ++i) {
            for(int j = 1; j < n+1; ++j) {
                if(word1.at(i-1) == word2.at(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int a = (dp[i-1][j] < dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
                    int b = (a < dp[i-1][j-1]) ? a : dp[i-1][j-1];
                    dp[i][j] = b + 1;
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end


int main() {

    #ifdef LOCAL
        fr("./0_in.tc");
        fw("./0_out.tc");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string str1, str2;
    Solution s;
    // while( cin >> str1 >> str2 ) {
    //     auto res = s.minDistance(str1, str2);
    //     cout << res << endl;
    // }
        auto res = s.minDistance(" ", "");
        cout << res << endl;
    return 0;
}