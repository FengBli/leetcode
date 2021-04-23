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

class Solution {
public:
    int reverse_(int a) { 
        int reva = 0;
        int aa = a;
        while(aa) {
            reva = reva * 10 + (aa%10);
            aa /= 10;
        } 
        return reva;
    }

    int countNicePairs(vector<int>& nums) {
        int s = nums.size();
        map<int, int> r;
        for(auto i : nums) {
            r[i - reverse_(i)] += 1;
        } 
        long long res = 0;
        for(auto it = r.begin(); it != r.end(); it++) {
            long long cnt = it->second;
            res += ((cnt * (cnt-1))/2 % 1000000007);
            res %= 1000000007;
        }
        return res;
    }
};