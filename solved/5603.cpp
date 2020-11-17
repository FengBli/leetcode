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

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) {
            return false;
        }

        char ac[26] = {false}, bc[26] = {false};
        vector<int> af(26, 0), bf(26, 0);
        for(char c: word1) {
            ac[c - 'a'] = true;
            af[c - 'a'] += 1;
        }
        for (char c : word2) {
            bc[c - 'a'] = true;
            bf[c - 'a'] += 1;
        }

        sort(af.begin(), af.end());
        sort(bf.begin(), bf.end());

        for(int i = 0; i < 26; ++i) {
            if(ac[i] != bc[i]) return false;
        }

        for(int i = 0 ; i < bf.size(); ++i) {
            if(bf[i] != af[i]) return false;
        }

        return true;
    }
};