/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
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
    // AC
    int islandPerimeter(vector<vector<int>>& grid) {

        int nei[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<int> v1(n+2, 0);
        vector<int> v2(n+2, 0);

        for(int i = 0; i < m; ++i) {
            grid[i].insert(grid[i].begin(), 0);
            grid[i].push_back(0);
        }

        grid.insert(grid.begin(), v1);
        grid.push_back(v2);


        for(int i = 1; i < m+1; ++i) {
            for(int j = 1; j < n+1; ++j) {
                for(int x = 0; x < 4; ++x) {
                    if(grid[i][j] == 1 && grid[i+nei[x][0]][j+nei[x][1]] == 0)
                        res += 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end


int main() {

    #ifdef LOCAL
        fr("./0_in.tc");
        fw("./0_out.tc");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string str;
    Solution s;
    vector<vi> grid {{1}};
    auto res = s.islandPerimeter(grid);
    cout << res;
    // while( cin >> str ) {
    //     auto res = s.islandPerimeter(grid);
    // }
    return 0;
}