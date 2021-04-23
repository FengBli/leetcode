// AC
#pragma GCC optimize("Ofast")
#define DBG_MACRO_NO_WARNING
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <set>
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
    int hammingWeight(uint32_t n) {
        int res = 0;

        while(n > 0) {
            res += (n&1);
            n >>= 1;
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

    uint32_t a;
    Solution s;
    while( cin >> a ) {
        dbg(a);
        auto res = s.hammingWeight(a);
        cout << " res = " << res << endl;
    }
    return 0;
}