/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"

#define PB push_back
#define PF push_front
#define MP make_pair
#define se second
#define fi first
#define LOCAL 1
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
    bool isLongPressedName(string name, string typed) {
        int j = 1;
        int i;

        int nn = name.size();
        int nt = typed.size();

        if(nn > nt || name.at(0) != typed.at(0)) 
            return false;

        for ( i = 1; i < nn; ) {
            if(j < nt && name.at(i) == typed.at(j)) {
                // printf("name[%d]=%c, typed[%d]=%c\n", i, name.at(i), j, typed.at(j));
                j++;
                i++;
            } else {
                if(j < nt && typed.at(j) == typed.at(j-1)) {
                    j++;
                } else {
                    return false;
                }
            }
        }
        // cerr <<"case: [" << name << "], j = " << j << endl;

        for(int i = j; i < nt; ++i) {
            if(typed.at(i) != name.at(nn-1)) {
                // printf("#name[%d]=%c, typed[%d]=%c\n", nn-1, name.at(nn-1), i, typed.at(i));
                return false;
            }
        }

        if (i != nn) {
            return false;
        }
        
        return true;
    }
};
// @lc code=end

#ifdef LOCAL
int main() {
    fr("/home/sept/Music/leetcode/tc.in");
    fw("/home/sept/Music/leetcode/tc.out");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    while(cin >> s1 >> s2) {
        Solution s;
        auto res = s.isLongPressedName(s1, s2);
        cout << res << endl;
    }
    return 0;
    
}
#endif