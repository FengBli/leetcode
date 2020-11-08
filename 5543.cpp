#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, set<int>> occ;
        for(int i = 0; i < 26; ++i) {
            occ.emplace(make_pair('a'+i, set<int>()));
        }

        int n = s.size();
        for(int i = 0; i < n; ++i) {
            occ[s.at(i)].insert(i);
        }

        int max = -1;
        for(char i = 'a'; i <= 'z'; ++i) {
            auto oc = occ[i];
            if(oc.size() > 1) {
                int re = *oc.rbegin() - *oc.begin() - 1;
                max = ((max > re) ? max : re);
            }

        }
        return max;
    }
};

// int main() {
//     // set<int> a;
//     // a.insert(7);
//     // a.insert(5);

//     // for(auto p = a.begin(); p != a.end(); ++p)
//     //     cout << *p << endl;

//     Solution s;
//     int a = s.maxLengthBetweenEqualCharacters("cabbac");
//     cout << a << endl;
//     return 0;
// }