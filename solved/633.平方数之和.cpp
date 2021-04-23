/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

#pragma GCC optimize("Ofast")
#define DBG_MACRO_NO_WARNING
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#endif

#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define REP(x, l, u) for(ll x = l; x < u; x++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

// @lc code=start
// AC: 双指针
// 注：两个数可以相同
// 再注：注意此处用ceil函数的话，可能导致下一步平方和上溢出
class Solution {
public:
    bool judgeSquareSum(int c) {
        int s = (int) ceil(sqrt(c));
        int i  = 0, j = s;
        while(i <= j) {
            int cur_sum = i * i + j * j;
            printf("%d^2 + %d^2 = %d\n", i, j, cur_sum);
            if( cur_sum == c ) return true;
            if(cur_sum < c) i++;
            else j--;
        }
        return false;
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
    int n;
    Solution s;
    while( cin >> n ) {
        auto res = s.judgeSquareSum(n);
        cout << res << endl;
    }
    return 0;
}