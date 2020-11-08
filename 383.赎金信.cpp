/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> r, m;
        for(char c: ransomNote) {
            if(r.find(c) == r.end()) 
                r.insert(make_pair(c, 1));
            else
                r[c]++;
        }

        for(char c: magazine) {
            if(m.find(c) == m.end()) {
                m.insert(make_pair(c, 1));
            } else {
                m[c]++;
            }
        }

        bool res = true;
        for(auto p : r) {
            char c = p.first;
            int t = p.second;

            if(m[c] < t) {
                res = false;
                break;
            }
        }

        return res;
    }
};
// @lc code=end

