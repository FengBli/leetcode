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

class Solution {
public:
    string predictPartyVictory(string senate) {
        
        vector<int> radiant_pos;
        vector<int> dire_pos;
        int n = senate.size();

        for(int i = 0; i < n; ++i) {
            char c = senate.at(i);
            if(c == 'R') radiant_pos.push_back(i);
            else dire_pos.push_back(i);
        }

        string res = "";
        if(radiant_pos.empty()) return "Dire";
        else if(dire_pos.empty()) return "Radiant";

        while(!radiant_pos.empty() && !dire_pos.empty()) {
            // dbg(senate);
            for(int i = 0; i < n; ++i) {
                char c = senate.at(i);
                if(c == 'R') {
                    auto ban_pos = upper_bound(dire_pos.begin(), dire_pos.end(), i);
                    if(ban_pos == dire_pos.end()) ban_pos = dire_pos.begin();
                    senate[*ban_pos] = '#';
                    dire_pos.erase(ban_pos);
                    if(dire_pos.empty()) {res = "Radiant"; break;}
                } else if(c == 'D'){
                    auto ban_pos = upper_bound(radiant_pos.begin(), radiant_pos.end(), i);
                    if(ban_pos == radiant_pos.end()) {ban_pos = radiant_pos.begin();}
                    senate[*ban_pos] = '#';
                    radiant_pos.erase(ban_pos);
                    if(radiant_pos.empty()) {res = "Dire"; break;}
                }
                
            }
        }
        // dbg(senate);

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

    string str;
    Solution s;
    while( cin >> str ) {
        if(str[0] == '#') continue;
        auto res = s.predictPartyVictory(str);
        cout << res << endl;
        cerr << str << ", winner = " << res << endl;
    }
    return 0;
}