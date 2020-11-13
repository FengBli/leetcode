/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
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
private:
    int Min(int a, int b) { return a < b ? a : b; }
public:
    // AC: hard
    // DP, T(n) = O(|ring|^2 * |key|)
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length();

        int **dp = (int**) malloc(sizeof(int*)*m);
        for(int i = 0; i < m; ++i) {
            dp[i] = (int*) malloc(sizeof(int)*n);
            memset(dp[i], 0, sizeof(int)*n);
        }
        int start = 0;
        for(int i = 0; i < m ; ++i) {
            char c = key.at(i);
            for(int j = 0; j < n; ++j) {
                char d = ring.at(j);
                if(c == d) {
                    if (i == 0) {
                        int clockwise = abs(j - start);
                        int antiClockwise = n - abs(j - start);

                        dp[i][j] = Min(clockwise, antiClockwise) + 1;
                    } else {
                        int r = INT_MAX;
                        for(int k = 0; k < n; ++k) {
                            if(dp[i-1][k] == 0) continue;
                            int clockwise = abs(j - k);
                            int antiClockwise = n - abs(j - k);
                            int tmp = Min(clockwise, antiClockwise) + 1;
                            tmp += dp[i-1][k];
                            r = Min(tmp, r);
                        }
                        dp[i][j] = r;

                    }
                }
            }
        }

        int res = INT_MAX;
        for(int i = 0; i < n; ++i) {
            if(dp[m-1][i] == 0) continue;
            res = Min(res, dp[m-1][i]);
        }
        return res;
    }
};
// @lc code=end


int main() {

    #ifdef LOCAL
        fr("../0_in.tc");
        fw("../0_out.tc");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string str, key;
    Solution s;
    while( cin >> str >> key) {
        auto res = s.findRotateSteps(str, key);
        cout << "res = " << res << endl;
    }
    return 0;
}