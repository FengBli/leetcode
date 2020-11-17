/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] 无矛盾的最佳球队
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

vector<string> stringToStringVector(string input) {
    vector<string> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        item = item.substr(1, item.length() - 2);
        output.push_back(item);
    }
    return output;
}

vector<vector<int>> stringToIntegerVectorVector(string input) {
    vector<vector<int>> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ']';

    getline(ss, item, delim);
    if(item.size())
        output.push_back(stringToIntegerVector(item + "]"));

    while(getline(ss, item, delim)) {
        item = item.substr(1, item.size()-1);
        output.push_back(stringToIntegerVector(item + "]"));
    }
    return output;
}

// @lc code=start
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

        // find LIS of ages
        vector<int> lis(n+1, 0);
        lis[1] = ps[0].first;
        int idx = 1;
        for(int i = 2; i <= n; ++i) {
            auto p = ps[i-1];
            int score = p.first;
            int age = p.second;

            int max = 0;
            for(int j = 0; j < i-1; ++j) {
                auto pp = ps[j];
                int s = pp.first;
                int a = pp.second;
                if(a <= age) {
                    max = (max > lis[j+1]) ? max : lis[j+1];
                }
            }
            lis[i] = max + score;
        }
        
        for(int i = 0; i < lis.size(); i++) {
            res = (res > lis[i]) ? res : lis[i];
        }
        return res;
    }
};
// @lc code=end


int main() {

    #ifdef LOCAL
        fr("0_in.tc");
        fw("0_out.tc");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string s1, s2;
    Solution s;
    while( cin >> s1 >> s2 ) {
        vi scores = stringToIntegerVector(s1);
        vi ages = stringToIntegerVector(s2);
        auto res = s.bestTeamScore(scores, ages);
        cout << res << endl;
    }
    return 0;
}