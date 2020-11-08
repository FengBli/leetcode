/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
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
    // TLE, O(n*n)
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        if(s.size() == 0)
            return res;
        bitset<256> chs;
        int size = s.size();
        for(int i = 0; i < size; ++i) {
            chs.reset();
            int r = 0;
            for(int j = i; j < size; ++j) {
                char c = s.at(j);
                int ascii = (int) c;
                if(chs[ascii] == false) {
                    chs.set(ascii);
                    r += 1;
                    res = (res > r) ? res : r;
                } else {
                    break;
                }
            }
        }
        return res;
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

    Solution s;
    string str;
    while(getline(cin, str)) {
        auto res = s.lengthOfLongestSubstring(str);
        cout << res << endl;
    }
    return 0;
}
#endif