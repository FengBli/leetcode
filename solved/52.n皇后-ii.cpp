/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
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
    int res = 0;
    vector<vector<bool>> bds;
    bool pass(int row, int col, int n) {

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

        j = (row<(n-col-1))?row:(n-col-1);
        for(int i =0; i <= j; ++i) {
            ddsum += bds[row-i][col+i];
        }

        if (vsum > 1 || dsum > 1 || ddsum > 1)
            return false;
        return true;
    }

    void check(int row, int n) {
        for(int i = 0; i < n; ++i) {
            bds[row][i] = true;
            if(pass(row, i, n)) {
                if(row < n-1)
                    check(row+1, n);
                else{
                    this->res++;
                } 
            }
            bds[row][i] = false;
        }
    }

    int totalNQueens(int n) {
        this->bds.clear();
        this->res = 0;

        for(int i = 0; i < n; ++i){
            vector<bool> bd(n, false);
            bds.emplace_back(bd);
        }

        check(0, n);
        return this->res;
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
    int str;
    Solution s;
    while( cin >> str ) {
        auto res = s.totalNQueens(str);
        cout << "nQueens(" << str << ") = " << res << endl;
    }
    return 0;
}