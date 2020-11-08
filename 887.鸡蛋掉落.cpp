/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
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
    int max(int a, int b) {
        if(a > b) return a;
        else return b;
    }

    int min(int a, int b) {
        if(a < b) return a;
        else return b;
    }

    // TLE
    int superEggDrop_v1(int K, int N) {
        int **dptable = (int**) malloc(sizeof(int*)*(K+1));
        for(int i = 0; i < K+1; ++i) {
            dptable[i] = (int*) malloc(sizeof(int)*(N+1));
            memset(dptable[i], 0, sizeof(int)*(N+1));
        }

        std::function<int(int,int)> dp = [&] (int k, int n) {
            if(k == 1 || n <= 2) {
                return n;
            }

            if(dptable[k][n] != 0) return dptable[k][n];

            int res = INT_MAX;
            for(int i = 1; i <= n; ++i) {
                res = min(res, max(dp(k-1, i-1), dp(k, n-i))+1);
            }
            
            dptable[k][n] = res;
            return res;            
        };

        return dp(K, N);
    }


    int superEggDrop(int K, int N) {

        int **dptable = (int**) malloc(sizeof(int*)*(K+1));
        for(int i = 0; i < K+1; ++i) {
            dptable[i] = (int*) malloc(sizeof(int)*(N+1));
            memset(dptable[i], 0, sizeof(int)*(N+1));
        }

        std::function<int(int,int)> dp = [&] (int k, int n) {
            if(k == 1 || n <= 2) return n;

            if(dptable[k][n] != 0) return dptable[k][n];

            for(int i = 1; i <= n; ++i) {
                int res = dp(k-1, i-1);
                if(res == dp(k, n-i)) {
                    dptable[k][n] = res+1;
                    return res+1;
                }
            }
            return 0;       
        };

        return dp(K, N);        
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
    // string str;
    int K, N;
    Solution s;
    while( cin >> K >> N ) {
        auto res = s.superEggDrop(K, N);
        cout << res << endl;
    }
    return 0;
}