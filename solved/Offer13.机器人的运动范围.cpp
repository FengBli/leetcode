// AC
#pragma GCC optimize("Ofast")
#define DBG_MACRO_NO_WARNING
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <climits>
#include <algorithm>
#include <sstream>

#ifdef LOCAL
#include "dbg.h"
#endif

#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define vi vector<int>

using namespace std;

class Solution {
public:
    bool coordinateSum(int i, int j, int k) {
        int sum = 0;

        while ( i ) {
            sum += i % 10;
            i /= 10;
        }
        while ( j ) {
            sum += j % 10;
            j /= 10;
        }

        return sum <= k;
    }

    bool check(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int movingCount(int m, int n, int k) {
        int res = 0;
        if (k == 0) return 1;
        // if (k == 1) return 2;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> can;
        can.emplace(0, 0);
        visited[0][0] = true;

        int r[] = {1, -1, 0, 0};
        int c[] = {0, 0, -1, 1};
        while(!can.empty()) {

            auto p = can.front();
            int i = p.first;
            int j = p.second;
            can.pop();
            res++;

            for (int ii = 0; ii < 4; ++ii) {
                int x = i + r[ii];
                int y = j + c[ii];

                if(check(x, y, m, n) && visited[x][y] == false && coordinateSum(x, y, k)) {
                    visited[x][y] = true;
                    can.emplace(x, y);
                }
            }
        }

        return res;
    }
};



int main() {

    #ifdef LOCAL
        fr("0_in.tc");
        fw("0_out.tc");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string str;
    int m, n, k;
    Solution s;
    while( cin >> m >> n >> k) {
        auto res = s.movingCount(m, n, k);
        cout << "res = " << res << endl;
    }
    return 0;
}