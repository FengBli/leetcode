/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
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
    string reorganizeString(string S) {
        int n = S.size();

        map<char, int> m;
        for(char c : S) {
            if(m.count(c) > 0) m[c]++;
            else m[c] = 1;
        }
        string newS = "";
        multimap<int, char> mm;
        for(auto p : m) {
            int cnt = p.second;
            mm.emplace(cnt, p.first);
            if(cnt > (n+1)/2) return "";
        }

        for(auto it = mm.rbegin(); it != mm.rend(); ++it) {
            int cnt = it->first;
            char c = it->second;
            for(int i = 0; i < cnt; ++i) {
                newS += c;
            }
        }

        string res = "";
        auto it = newS.begin();
        auto jt = it + (n+1)/2;
        while(jt != newS.end()){
            res += (*it);
            res += *jt;
            it++;
            jt++;
        }
        if (n%2 == 1) res += *it;
        return res;

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
    string str;
    Solution s;
    while( cin >> str ) {
        auto res = s.reorganizeString(str);
        cout << res << endl;

    }
    return 0;
}