/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#pragma GCC optimize("Ofast")
#define DBG_MACRO_NO_WARNING
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>
#include <algorithm>
#include <sstream>
#include <cmath>

#ifdef LOCAL
#include "dbg.h"
#endif

#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define vi vector<int>

using namespace std;

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        const int S = 10000;

        vector<int> primes;
        int nsqrt = std::sqrt(n);
        vector<char> is_prime(nsqrt + 1, true);
        for (int i = 2; i <= nsqrt; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= nsqrt; j += i)
                    is_prime[j] = false;
            }
        }

        int result = 0;
        vector<char> block(S);
        for (int k = 0; k * S < n; k++) {
            fill(block.begin(), block.end(), true);
            int start = k * S;
            for (int p : primes) {
                int start_idx = (start + p - 1) / p;
                int j = max(start_idx, p) * p - start;
                for (; j < S; j += p)
                    block[j] = false;
            }
            if (k == 0)
                block[0] = block[1] = false;
            for (int i = 0; i < S && start + i < n; i++) {
                if (block[i])
                    result++;
            }
        }
        return result;
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
        auto res = s.countPrimes(str);
        dbg(res);
    }
    return 0;
}