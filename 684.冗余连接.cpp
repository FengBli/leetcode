/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
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

// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    
        map<int, int> parent;
        for(auto edge : edges) {
            int i = edge[0];
            int j = edge[1];
            parent[i] = i;
            parent[j] = j;
        }
        for(auto edge : edges) {
            int i = edge[0];
            int j = edge[1];
            int ip = find_(parent, i);
            int jp = find_(parent, j);
            if(ip == jp) {
                return edge;
            }
            parent[ip] = jp;
        }
        return edges[edges.size() - 1];
    }

    void union_(map<int, int> &parent, int i, int j) {
        int ip = find_(parent, i);
        int jp = find_(parent, j);
        parent[ip] = jp;
    }

    int find_(map<int, int> &parent, int i) {
        if(i == parent[i]) return i;
        int ip = find_(parent, parent[i]);
        parent[i] = ip;
        return ip;
    }
};
// @lc code=end

