/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"

#define PB push_back
#define PF push_front
#define MP make_pair
#define se second
#define fi first
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define REP(x, l, u) for(ll x = l; x < u; x++)
#define RREP(x, l, u) for(ll x = l; x >= u; x--)

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

string to_string (string s) { return '"' + s + '"'; }
string to_string (const char *s) { return to_string ((string) s); }
string to_string (bool b) { return (b ? "true" : "false"); }

template<typename A, typename B>
string to_string (pair<A, B> p) { return "(" + to_string (p.first) + ", " + to_string (p.second) + ")"; }

template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for( const auto &x : v) {
        if(!first) {res += ", ";}
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out () { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out (T...);
}

#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]", debug_out(__VA_ARGS__)
#else
#define dbg(...) {}
#endif
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

vector<string> stringToStringVector(string input) {
    vector<string> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        item = item.substr(1, item.length() - 2);
        output.push_back(item);
    }
    return output;
}

vector<vector<int>> stringToIntegerVectorVector(string input) {
    vector<vector<int>> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ']';

    getline(ss, item, delim);
    if(item.size())
        output.push_back(stringToIntegerVector(item + "]"));

    while(getline(ss, item, delim)) {
        item = item.substr(1, item.size()-1);
        output.push_back(stringToIntegerVector(item + "]"));
    }
    return output;
}

// @lc code=start
class Solution {
public:
    // TLE: O(n^4)
    int fourSumCount_bf(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        cerr << "size = " << n << endl;
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if(A[i] + B[j] + C[k] + D[l] == 0) res++;
                    }
                }
            }
        }
        return res;
    }

    // TLE: O(n^3 logn)
    int fourSumCount_bf2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int res = 0;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    int d = -1 * (A[i] + B[j] + C[k]);
                    auto low = std::lower_bound(D.begin(), D.end(), d);
                    auto up = std::upper_bound(D.begin(), D.end(), d);
                    res += (up - low);
                }
            }
        }
        return res;
    }

    // AC 5%time,
    int fourSumCount_foo(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int res = 0;
        if(n == 0) return 0;


        vector<int> AB, CD;
        for(int i = 0; i < n; ++i) {
            for( int j = 0; j < n; ++j) {
                AB.push_back(A[i]+ B[j]);
                CD.push_back(C[i]+ D[j]);
            }
        }
        map<int, int> ABcnt, CDcnt;
        for(int i = 0; i < AB.size(); i++) {
            if(ABcnt.count(AB[i]) == 0) ABcnt[AB[i]] = 1;
            else ABcnt[AB[i]]++;
            if(CDcnt.count(CD[i]) == 0) CDcnt[CD[i]] = 1;
            else CDcnt[CD[i]]++;
        }

        int min = ABcnt.begin()->first + CDcnt.begin()->first;
        int max = ABcnt.rbegin()->first + CDcnt.rbegin()->first;

        if(min > 0 || max < 0) return 0;

        for(auto p : ABcnt) {
            int key = p.first;
            int oc = p.second;
            if(CDcnt.count(-1*key)) res += (CDcnt[-1*key] * oc);
        }

        return res;
    }

    // AC, 5% time, 37% space
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int res = 0;
        if(n == 0) return res;

        map<int, int> m;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int key = A[i] + B[j];
                if(m.count(key)) m[key] += 1;
                else m[key] = 1;
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int key = -1 *(C[i] + D[j]);
                if(m.count(key)) res += m[key];
            }
        }
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

    string s1, s2, s3, s4;
    Solution s;
    while( cin >> s1 >> s2 >> s3 >> s4 ) {
        vi a = stringToIntegerVector(s1);
        vi b = stringToIntegerVector(s2);
        vi c = stringToIntegerVector(s3);
        vi d = stringToIntegerVector(s4);
        auto res = s.fourSumCount(a, b, c, d);
        dbg(res);
    }
    return 0;
}
/*
[1,2]
[-2,-1]
[-1,2]
[0,2]
[-8,-7,-14,-5,5,-24,-16,-24,-23,6,3,-26,-10,-14,-22,-11,-30,-2,-15,-18,-31,-1,-16,-22,-23,-24,-22,-16,-24,-15,-21,-18,-8,-7,7,-20,-32,-16,-24,5,3,-31,-18,2,-2,-11,-21,-26,-15,-14,1,10,0,-2,2,-10,3,-12,-10,-30,8,-31,2,-2,-4,-17,-24,-25,6,-11,-4,-29,5,-20,-16,-23,2,-27,6,-10,-2,-29,-15,9,-13,-20,8,-2,-17,6,-5,-26,6,-9,-29,-32,-27,-20,-7,-28]
[-9,-6,-6,-24,-4,-25,0,-17,1,-10,-18,4,1,8,-28,3,8,4,-18,-18,-10,0,1,-23,-10,-8,-18,-13,-30,-8,-24,1,-24,5,-15,-19,-6,-7,2,-10,-24,-9,-15,-2,-28,-3,-24,7,-22,-9,-18,-4,-5,-28,-5,-22,-31,-2,0,-20,-9,-14,-32,-12,8,-22,-15,4,-9,-26,2,-5,-20,-13,-12,-13,-20,-8,-32,6,-4,-29,-5,4,-21,-13,-26,5,6,-25,-31,-15,10,3,5,5,-10,1,-7,8]
[-6,6,-14,0,-2,-7,-16,0,-25,-28,0,0,-18,-15,4,-7,-26,-21,-3,-5,9,-14,6,-5,-26,-25,-27,-1,10,-13,7,-2,1,6,-12,7,-24,9,5,-27,8,-3,-12,-31,-27,-9,-10,-8,-27,-2,-20,-27,-13,0,8,-1,-25,0,10,-14,-23,-2,5,-28,-22,5,-12,-14,-15,8,-9,-6,-9,-22,-10,-31,-9,-24,-16,-13,-26,-5,-32,-29,9,-3,-10,8,-15,-31,-5,-18,5,-20,-2,10,-18,3,-1,-31]
[-5,4,-4,-20,-32,7,-12,-15,-26,-15,6,2,-24,-14,-31,-11,-29,-5,-1,5,-29,-1,-26,-17,-12,-14,-12,6,-28,-28,9,-29,-22,-1,-31,1,-4,-24,-25,-18,8,-21,-29,0,5,-21,-10,-4,-25,-15,-32,-29,-15,-31,-25,6,-30,-23,7,-6,4,-32,9,-11,7,3,-21,-30,-25,-1,-13,-11,-24,-27,-12,-24,-27,-22,-31,-4,-20,-31,7,2,-25,-3,-12,-24,10,10,-9,-17,-22,-1,-16,-11,6,10,-20,5]
[0]
[0]
[0]
[0]

*/