/*
 * @lc app=leetcode.cn id=1268 lang=cpp
 *
 * [1268] 搜索推荐系统
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());

        int n = searchWord.size();

        vector<string> candicate_prod;
        for(auto p : products) {
            if (p.at(0) == searchWord.at(0))
                    candicate_prod.push_back(p);
        }

        if(0 == candicate_prod.size()) {
            for (int i = 0; i < n; ++i)
                res.push_back(vector<string>());
            return res;
        }

        
        for(int i = 0; i < n; ++i) {
            vector<string> r;
            const string prefix = searchWord.substr(0, i+1);
            int cnt = 0;
            for(auto p : candicate_prod) {
                if (cnt < 3) {
                    if(p.substr(0,i+1) == prefix) {
                        r.push_back(p);
                        cnt++;
                    }
                } else {
                    break;
                }
            }
            res.push_back(r);
        }

        return res;
    }
};

// int main() {
//     vector<string> products {
//         "havana"
//     };
    
//     // {
//     //     "mobile",
//     //     "mouse",
//     //     "moneypot",
//     //     "monitor",
//     //     "mousepad"
//     // };

//     Solution s;
//     auto res = s.suggestedProducts(products, "tatiana");

//     for(auto a : res) {
//         for(auto s : a) {
//             cout << s << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
// @lc code=end

