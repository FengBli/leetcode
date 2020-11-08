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

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vi string2vector(string input) {
    vi res;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        res.push_back(stoi(item));
    }
    return res;
}

class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        vector<pair<int, int>> ps;
        int res = -1;

        int n = scores.size();
        for(int i = 0; i < n; ++i) {
            ps.emplace_back(scores[i], ages[i]);
        }

        sort(ps.begin(), ps.end(), [](auto &a, auto &b) {
            if(a.first != b.first)
                return a.first < b.first;
            else 
                return a.second < b.second;
        });
        
        cout << "s\ta" << endl;
        for(auto it = ps.begin(); it < ps.end(); ++it) {
            cout << it->first << "\t" << it->second << endl;
        }

        int temp_sum = ps.begin()->first;
        auto prev = ps.begin();
        for(auto it = (++ps.begin()); it < ps.end(); ++prev, ++it) {
            if(it->second <= prev->second)
                temp_sum += (*it).first;
            else {
                res = (res > temp_sum) ? res : temp_sum;
                temp_sum = (*it).first;
            }
        }

        res = (res > temp_sum) ? res : temp_sum;
        return res;
    }
};

#ifdef LOCAL
int main() {
    fr("/home/sept/Music/leetcode/tc.in");
    fw("/home/sept/Music/leetcode/tc.out");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;

    string s1, s2;
    while(cin >> s1 >> s2) {
        // cin >> s1;
        // cin >> s2;
        vi a = string2vector(s1);
        vi b = string2vector(s2);
        auto res = s.bestTeamScore(a, b);
        cout << "res = " << res << endl;
        cout << "===================" << endl;
    }
    
}
#endif