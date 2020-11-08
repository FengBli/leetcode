/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // vector<int> sortedSquares(vector<int>& A) {
    //     vector<int> res;
    //     for(auto it = A.begin(); it < A.end(); ++it) {
    //         res.push_back((*it)*(*it));
    //     }
    //     std::sort(res.begin(), res.end());

    //     return res;
    // }

    std::vector<int> sortedSquares(std::vector<int> &A) {
        std::vector<int> res;

        auto p = A.begin();
        auto q = --A.end();
        int a, b;
        while(p != q) {
            a = *p;
            b = *q;
            if(a*a > b*b) {
                res.emplace(res.begin(), a*a);
                p++;
            } else {
                res.emplace(res.begin(), b*b);
                q--;
            }
        }
        res.emplace(res.begin(), (*p)*(*p));

        return res;

    }
};


// @lc code=end

