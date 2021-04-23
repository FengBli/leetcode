#include <iostream>
#include <vector>
// #include <pair>
#include <queue>
using namespace std;

using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;

ostream& operator<< (ostream& os, const vector<pair<int, int>> &a) {
    for(pair<int, int> aa : a) {
        os << "(" << aa.first << ", " << aa.second << ")";
    }
    return os;
}

class Solution {
private:
    

    bool isValid(const int i, const int j, const int m, const int n) const {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    vpi getNeighbors(int i, int j, const vvc &grid, const int m, const int n) {
        vvi directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vpi res;
        for(vi d : directions) {
            int ii = i + d[0];
            int jj = j + d[1];
            if(isValid(ii, jj, m, n) && grid[ii][jj] == '1') {
                res.emplace_back(ii, jj);
            }
        }
        cout << "Neighbors of (" << i << "," << j << ") are " << res << endl;
        return res;
    }

    void bfs(vvi &visited, int i, int j, const vvc &grid, const int m, const int n) {
        queue<pii> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        while(!q.empty()) {
            pii p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            for(auto neighbor : getNeighbors(i, j, grid, m, n)) {
                int i = neighbor.first;
                int j = neighbor.second;
                if(visited[i][j] == false) {
                    visited[i][j] = true;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    int numIslands(vvc& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n= grid[0].size();
        if(n == 0) return 0;

        vvi visited(m, vi(n, 0));
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(visited[i][j] == false && grid[i][j] == '1') {
                    res++;
                    cout << "Visiting (" << i << ", " << j << ")" << endl;
                    bfs(visited, i, j, grid, m, n);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    vvc grid = {{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
    cout << solution.numIslands(grid) << endl;
    return 0;
}


/*
[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
[  ["1","1","0","0","0"],  ["1","1","0","0","0"],  ["0","0","1","0","0"],  ["0","0","0","1","1"]]
*/