/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
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
    std::string slidingWindow(std::string s, std::string t) {
        unordered_map<char, int> need, windows;
        for(char c : t) need[c]++;

        int left = 0; 
        int right = 0;
        int valid = 0;

        int start = 0;
        int len = INT_MAX;
        while(right < s.size()) {
            char c = s[right];
            right++;

            if(need.count(c)) {
                windows[c]++;
                if(windows[c] == need[c]) {
                    valid++;
                }
            }

            printf("Window: [%d, %d)\n", left, right);

            while(valid == need.size()) { /* window needs shrink */
                if(right - left < len) {
                    start = left;
                    len = right - left;
                }

                char d = s[left];
                left++;

                if(need.count(d)) {
                    if(windows[d] == need[d]) {
                        valid--;
                    }
                    windows[d]--;
                }
                
            }
        }

        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
public:
    // AC
    string minWindow(string s, string t) {
        return slidingWindow(s, t);
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
    string str, str2;
    Solution s;
    while( cin >> str >> str2) {
        auto res = s.minWindow(str, str2);
        cout << res << endl;
    }
    return 0;
}