/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int res = 0;
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

    void check(vector<vector<bool>> &bds, int row, int n) {

        for(int i = 0; i < n; ++i) {
            bds[row][i] = true;
            if(pass(bds, row, i, n)) {
                if(row < n-1)
                    check(bds, row+1, n);
                else{
                    this->res++;
                } 
            }
            bds[row][i] = false;
        }
    }

    int totalNQueens(int n) {
        vector<vector<bool>> bds;
        for(int i = 0; i < n; ++i){
            vector<bool> bd(n, false);
            bds.emplace_back(bd);
        }

        this->res = 0;
        check(bds, 0, n);
        bds.clear();
        return this->res;
    }
};

int main() {
    
    for(int n = 0; n < 10; ++n) {
        Solution s = Solution();
        int res = s.totalNQueens(n);
        cout << "NQueens(" << n << ")=" << res << endl;
        
    }

}
// @lc code=end

