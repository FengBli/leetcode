/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
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
    string originalDigits(string s) {
        vector<int> cnts(200, 0);
        for(char c : s) {
            cnts[c]++;
        }
        
        vector<int> dcnts(10, 0);

        if(cnts['x']) {
            dcnts[6] = cnts['x'];
            
            cnts['i'] -= cnts['x'];
            cnts['s'] -= cnts['x'];
            cnts['x'] = 0;
        }

        if(cnts['z']) {
            dcnts[0] = cnts['z'];
            cnts['e'] -= cnts['z'];
            cnts['r'] -= cnts['z'];
            cnts['o'] -= cnts['z'];
            cnts['z'] = 0;
        }

        if(cnts['g']) {
            dcnts[8] = cnts['g'];
            cnts['i'] -= cnts['g'];
            cnts['e'] -= cnts['g'];
            cnts['h'] -= cnts['g'];
            cnts['t'] -= cnts['g'];
            cnts['g'] = 0;
        }

        if(cnts['s']) { 
            dcnts[7] = cnts['s'];
            cnts['e'] -= 2 * cnts['s'];
            cnts['v'] -= cnts['s'];
            cnts['n'] -= cnts['s'];
            cnts['s'] = 0;
        }

        if(cnts['h']) {
            dcnts[3] = cnts['h'];
            cnts['t'] -= cnts['h'];
            cnts['e'] -= 2 * cnts['h'];
            cnts['r'] -= cnts['h'];
            cnts['h'] = 0;
        }

        if(cnts['t']) {
            dcnts[2] = cnts['t'];
            cnts['w'] -= cnts['t'];
            cnts['o'] -= cnts['t'];
            cnts['t'] = 0;
        }

        if(cnts['v']) {
            dcnts[5] = cnts['v'];
            cnts['f'] -= cnts['v'];
            cnts['i'] -= cnts['v'];
            cnts['e'] -= cnts['v'];
            cnts['v'] = 0;
        }

        if(cnts['f']) {
            dcnts[4] = cnts['f'];
            cnts['o'] -= cnts['f'];
            cnts['u'] -= cnts['f'];
            cnts['r'] -= cnts['f'];
            cnts['f'] = 0;
        }

        if(cnts['i']) { 
            dcnts[9] = cnts['i'];
            cnts['e'] -= cnts['i'];
        }

        if(cnts['e']) {
            dcnts[1] = cnts['e'];
        }
        
        string res = "";

        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < dcnts[i]; ++j) {
                res += to_string(i);
            }
        }

        return res;
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
        auto res = s.originalDigits(str);
        cout << res << endl;
    }

}