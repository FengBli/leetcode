/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // AC
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;

        stack<pair<int, int>> pac_xy, alt_xy;

        int m = matrix.size();
        if (0 == m) return res;

        int n = matrix[0].size();
        if (0 == n) return res;

        vector<vector<bool>> pac, alt;
        for(int i = 0; i < m; ++i) {
            pac.emplace_back(vector<bool>(n, false));

            alt.push_back(vector<bool>(n, false));
        }

        for(int i = 0; i < m; ++i) {
            pac_xy.push(make_pair(i, 0));
            alt_xy.push(make_pair(i, n-1));

            pac[i][0] = true;
            alt[i][n-1] = true;
        }

        for(int i = 0; i < n; ++i) {
            pac_xy.push(make_pair(0, i));
            alt_xy.push(make_pair(m-1, i));

            pac[0][i] = true;
            alt[m-1][i] = true;
        }

        while(!pac_xy.empty()) {
            auto xy = pac_xy.top();
            pac_xy.pop();

            int x = xy.first, y = xy.second;

            if(x>0 && (!pac[x-1][y]) && (matrix[x][y] <= matrix[x-1][y])) {
                pac[x-1][y] = true;
                pac_xy.push(make_pair(x-1, y));
            }

            if(x<m-1 && (!pac[x+1][y]) && (matrix[x][y] <= matrix[x+1][y])) {
                pac[x+1][y] = true;
                pac_xy.push(make_pair(x+1, y));
            }

            if(y>0 && (!pac[x][y-1]) && (matrix[x][y] <= matrix[x][y-1])) {
                pac[x][y-1] = true;
                pac_xy.push(make_pair(x, y-1));
            }

            if(y<n-1 && (!pac[x][y+1]) && (matrix[x][y] <= matrix[x][y+1])) {
                pac[x][y+1] = true;
                pac_xy.push(make_pair(x, y+1));
            }

        }

        while(!alt_xy.empty()) {
            auto xy = alt_xy.top();
            alt_xy.pop();

            int x = xy.first, y = xy.second;

            if(x>0 && (!alt[x-1][y]) && (matrix[x][y] <= matrix[x-1][y])) {
                alt[x-1][y] = true;
                alt_xy.push(make_pair(x-1, y));
            }

            if(x<m-1 && (!alt[x+1][y]) && (matrix[x][y] <= matrix[x+1][y])) {
                alt[x+1][y] = true;
                alt_xy.push(make_pair(x+1, y));
                
            }

            if(y>0 && (!alt[x][y-1]) && (matrix[x][y] <= matrix[x][y-1])) {
                alt[x][y-1] = true;
                alt_xy.push(make_pair(x, y-1));
            }

            if(y<n-1 && (!alt[x][y+1]) && (matrix[x][y] <= matrix[x][y+1])) {
                alt[x][y+1] = true;
                alt_xy.push(make_pair(x, y+1));
            }

        }

        for(int i =0; i < m; ++i) {
            for(int j =0; j < n; ++j) {
                cout << (alt[i][j] && pac[i][j]) << " ";

                if(alt[i][j] && pac[i][j]) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    res.push_back(v);
                }
            }
            cout << endl;
        }

        return res;
    }
};
// @lc code=end

