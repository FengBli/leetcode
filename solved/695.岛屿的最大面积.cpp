/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
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
private:
    int bfs(int i, int j, const vector<vector<int>> grid, vector<vector<bool>>& visited) {
        vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
        int res = 0;
        std::stack<pair<int, int>> s;
        s.push(make_pair(i, j));

        while(!s.empty()) {
            pair<int, int> p = s.top();
            int i_ = p.first;
            int j_ = p.second;

            s.pop();
            if(visited[i_][j_]) continue;
            visited[i_][j_] = true;
            res += 1;

            for(vector<int> &nei : directions) {
                int ii = i_ + nei[0];
                int jj = j_ + nei[1];
                if(visited[ii][jj] == false && grid[ii][jj] == 1) {
                    s.push(make_pair(ii, jj));
                }
            }
        }
        return res;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        if(row == 0) return 0;

        int col = grid[0].size();
        if(col == 0) return 0;

        for(auto &v: grid) {
            v.insert(v.begin(), 0);
            v.push_back(0);
        }

        grid.insert(grid.begin(), vector<int>(col+2, 0));
        grid.push_back(vector<int>(col+2, 0));

        vector<vector<bool>> visited(row+2, vector<bool>(col+2, false));

        int res = 0;
        for(int i = 1; i <= row; ++i) {
            for(int j = 1; j <= col; ++j) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    int r = bfs(i, j, grid, visited);
                    res = (res > r) ? res : r;                  
                }
            }
        }
        return res;
    }
};
// @lc code=end
/*
[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
*/


int main() {

    #ifdef LOCAL
        fr("0_in.tc");
        fw("0_out.tc");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    string str;
    Solution s;
    while( cin >> str ) {
        vector<vector<int>> grid = stringToIntegerVectorVector(str);

        auto res = s.maxAreaOfIsland(grid);
        cout << res << endl;
    }
    return 0;
}
