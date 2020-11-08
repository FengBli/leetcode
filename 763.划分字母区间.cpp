/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
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
    vector<int> partitionLabels(string S) {
        int size = S.size();
        vector<pair<int, int>> ss(26, make_pair(-1, -1));
        
        for( int i = 0; i < size; ++i) {
            char c = S.at(i);
            int idx = c - 'a';

            if(ss[idx].first == -1) {
                ss[idx].first = i;
            } else {
                ss[idx].second = i;
            }
        }

        sort(ss.begin(), ss.end(), [] (const auto &a, const auto &b) {
            return a.first < b.first;
        });

        vector<int> res;

        int sp = 0;
        int ep = -1;
        
        for(int i = 0; i < 26; ++i) {
            int a = ss[i].first;
            if(a != -1) {
                int b = (ss[i].second == -1) ? a : ss[i].second;
                if( a < ep ) {
                    ep = (ep > b) ? ep : b;
                } else {
                    res.push_back(ep - sp + 1);
                    sp = a;
                    ep = b;
                }
            }
        }
        res.erase(res.begin());
        res.push_back(ep - sp + 1);

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
    while(cin >> str) {
        auto res = s.partitionLabels(str);
        dbg(res);
    }

    

}
