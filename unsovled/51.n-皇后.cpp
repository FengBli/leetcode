/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
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
    bool pass(vector<vector<bool>> &bds, int row, int col, int n) {

        int vsum = 0;
        int dsum = 0;
        int ddsum = 0;

        for(int i = row; i >-1; --i) {
            vsum += bds[i][col];
        }

        int j = (row<col)?row:col;
        for(int i = 0; i <= j; ++i) {
            dsum += bds[row-i][col-i];
        }

        j = (row<(n-col))?row:(n-col);
        for(int i =0; i <= j; ++i) {
            ddsum += bds[row-i][col+i];
        }

        if (vsum > 1 || dsum > 1 || ddsum > 1)
            return false;
        return true;
    }

    void check(vector<vector<bool>> &bds, int row, int n, vector<vector<string>> &res) {

        for(int i = 0; i < n; ++i) {
            bds[row][i] = true;
            if(pass(bds, row, i, n)) {
                if(row < n-1)
                    check(bds, row+1, n, res);
                else{
                    vector<string> rr;
                    for(auto r : bds) {
                        string rs = "";
                        for(auto item : r) {
                            if(item) rs += "Q";
                            else rs += ".";
                        }
                        rr.push_back(rs);
                    }
                    res.push_back(rr);
                } 
            }
            bds[row][i] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> bds;
        for(int i = 0; i < n; ++i){
            vector<bool> bd(n, false);
            bds.emplace_back(bd);
        }

        vector<vector<string>> res;
        check(bds, 0, n, res);
        bds.clear();

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
    int n = 0;
    cin >> n;
    auto res = s.solveNQueens(n);

    for(auto row : res) {
        for(auto item : row) {
            cout << item << endl;
        }
        cout << "========================" << endl;
    }
    
}
#endif