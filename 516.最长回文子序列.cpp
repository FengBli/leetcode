/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
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
    int longestPalindromeSubseq(string s) {
        int N = s.size();

        if(N <= 1) return N;

        int **dp = (int**) malloc(sizeof(int*)*(N+1));
        for(int i = 0; i < N+1; ++i) {
            dp[i] = (int*) malloc(sizeof(int)*(N+1));
            memset(dp[i], 0, sizeof(int)*(N+1));
        }

        for(int i = 0; i < N-1; i++) {
            dp[i][i] = 1;
            if(s.at(i) == s.at(i+1)) 
                dp[i][i+1] = 2;
            else 
                dp[i][i+1] = 1;
        }

        dp[N-1][N-1] = 1;

        for(int i = N-1; i >= 0; --i) {
            for(int j = i+2; j < N; ++j) {
                if(s.at(i) == s.at(j)) {
                    int a = dp[i][j-1];
                    int b = dp[i+1][j];
                    int c = (a > b) ? a : b;
                    int d = 2 + dp[i+1][j-1];
                    dp[i][j] = (c > d) ? c : d;
                } else {
                    int a = dp[i][j-1];
                    int b = dp[i+1][j];
                    dp[i][j] = ((a > b) ? a : b);
                }
            }
        }
        return dp[0][N-1];
    }
};
// @lc code=end

int main() {

    #ifdef LOCAL
        fr("./tc.in");
        fw("./tc.out");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string str;
    Solution s;
    while( cin >> str ) {
        auto res = s.longestPalindromeSubseq(str);
        cout << res << endl;
    }
    return 0;
}