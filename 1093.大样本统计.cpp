/*
 * @lc app=leetcode.cn id=1093 lang=cpp
 *
 * [1093] 大样本统计
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double min, max, mean, med, most;
        long long cnt = 0;
        bool flag = true;
        long long cnt_max = 0;
        long long cnt_prefix_sum[256] = {0};
        for(int i = 0; i < 256; ++i) {

            if(flag) {
                if(count[i] != 0) {
                    min = i;
                    flag = false;
                }
                cnt_prefix_sum[i] = count[i];
            } else {
                cnt_prefix_sum[i] = cnt_prefix_sum[i-1] + count[i];
            }

            if(count[i] != 0)
                max = i;
            
            if(count[i] > cnt_max) {
                most = i;
                cnt_max = count[i];
            }

            mean += i * count[i];
            cnt += count[i];
        }

        mean /= (cnt * 1.0);

        long long med_idx = cnt / 2;
        flag = (bool) (cnt % 2);

        for(int i = 0; i < 256; i++) {
            if(med_idx < cnt_prefix_sum[i]) {
                med = i;
                break;
            } else if(flag == 0 && cnt_prefix_sum[i] == med_idx) {
                med = i + 0.5;
                break;
            }
        }

        vector<double> res;

        res.push_back(min);
        res.push_back(max);
        res.push_back(mean);
        res.push_back(med);
        res.push_back(most);

        return res;
    }
};

// int main() {
//     vector<int> cnt {0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//     Solution s;
//     auto res = s.sampleStats(cnt);
//     for(auto a : res) {
//         cout << a << endl;
//     }
//     return 0;
// }
// @lc code=end

