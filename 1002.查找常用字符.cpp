/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
#include <bits/stdc++.h>
#include <limits>

using namespace std;


class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<map<char, int>> cnts;

        for(auto a: A) {
            map<char, int> cnt;
            for(char c: a) {
                if(cnt.find(c) == cnt.end())
                    cnt.insert(make_pair(c, 1));
                else 
                    cnt[c]++;
            }
            cnts.push_back(cnt);
        }



        vector<string> res;
        for(char c = 'a'; c <= 'z'; ++c){
            int cnt = INT_MAX;

            for(auto cc: cnts)
                cnt = (cnt < cc[c]) ? cnt : cc[c];

            for(int i = 0; i < cnt; i++) {
                res.push_back(string(1,c));
            }
        }
        
        return res;
    }
};

int main() {

    vector<string> A {
        "bella", 
        "label",
        "roller"
    };

    Solution s;
    auto res = s.commonChars(A);
    
    for(auto a: res)
        cout << a << " ";
    cout << endl;

    return 0;
}
// @lc code=end

