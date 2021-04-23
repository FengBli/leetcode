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

ostream& operator<<(ostream& os, const vector<string>& a) { 
    for (string s : a) {
        os << s << " ";
    }
    return os;
}

class Solution {
public:
    int max_(int a, int b, int c) {
        int ab = a > b ? a : b;
        return ab > c ? ab : c;
    }

    bool check(vector<string> s, vector<string> t) {
        int ss = s.size();
        int tt = t.size();

        int i = 0;
        int j = 1;
        while(i < tt && s[i] == t[i]) ++i;
        while(j < tt && s[ss-j] == t[tt-j]) ++j;
        return i >= j; 
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        std::string delimiter = " ";
        vector<string> v1, v2;

        size_t pos = 0;
        std::string token;
        while ((pos = sentence1.find(delimiter)) != std::string::npos) {
            token = sentence1.substr(0, pos);
            v1.push_back(token);
            sentence1.erase(0, pos + delimiter.length());
        }
        v1.push_back(sentence1);


        while ((pos = sentence2.find(delimiter)) != std::string::npos) {
            token = sentence2.substr(0, pos);
            v2.push_back(token);
            sentence2.erase(0, pos + delimiter.length());
        }
        v2.push_back(sentence2);

        int v11 = v1.size();
        int v22 = v2.size();
        if(v11 > v22) return check(v1, v2);
        else return check(v2, v1);
    }
};
