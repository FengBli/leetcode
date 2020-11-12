/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
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
    // AC, using stack
    // bool backspaceCompare(string S, string T) {
    //     stack<char>ss, st;

    //     for(char c : S) {
    //         if('#' != c)
    //             ss.push(c);
    //         else if(!ss.empty()) {
    //             ss.pop();
    //         }
    //     }

    //     for(char c : T) {
    //         if('#' != c)
    //             st.push(c);
    //         else if(!st.empty()) {
    //             st.pop();
    //         }
    //     }

    //     if(ss.size() != st.size())
    //         return false;
        
    //     while(!ss.empty()) {
    //         // cout << ss.top() << " " << st.top() << endl;
    //         if (ss.top() != st.top())
    //             return false;
    //         ss.pop();
    //         st.pop();
    //     }
    //     return true;
    // }


    bool backspaceCompare(string S, string T) {
        
        return true;

    }
};
// @lc code=end

#ifdef LOCAL
int main() {
    fr("/home/sept/Music/leetcode/0_in.tc");
    fw("/home/sept/Music/leetcode/0_out.tc");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    string s1, s2;
    while(cin >> s1 >> s2){
        auto res = s.backspaceCompare(s1, s2);
        cout << res << endl;
    }
    
}
#endif