/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
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
struct comp_1 {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
        double aa = sqrt(a[0]*a[0] + a[1]*a[1]); 
        double bb = sqrt(b[0]*b[0] + b[1]*b[1]);
        return aa < bb;
    }
};

class Solution {
public:
    // TLE at #83 testcase, T(n) = O(nlog(n))
    vector<vector<int>> kClosest_sort(vector<vector<int>>& points, int K) {
        auto comp = [](vector<int> a, vector<int> b) { 
            double aa = sqrt(a[0]*a[0] + a[1]*a[1]); 
            double bb = sqrt(b[0]*b[0] + b[1]*b[1]);
            return aa < bb;
        };

        sort(points.begin(), points.end(), comp);

        auto ptr = points.begin();
        int n = 0;
        while(n++ < K) ptr++;

        return vector<vector<int>>(points.begin(), ptr);
    }

    double distance(vector<int> a) {
        return sqrt(a[0] * a[0] + a[1] * a[1]);
    }

    // AC, T(n) = O(n)
    vector<vector<int>> kClosest(vector<vector<int>> points, int K) {
        int i = 0;

        auto it = points.begin();
        while(i++ < K) it++;

        multimap<double, vector<int>> ms;

        for(int i = 0; i < K; i++) {
            double dis = distance(points[i]);
            ms.emplace(dis, points[i]);
        }

        for(int i = K; i < points.size(); i++) {
            auto point = points[i];
            double dis = distance(point);

            if(dis < ms.rbegin()->first) {
                ms.emplace(dis, point);
                ms.erase(--ms.end());
            }
        }

        vector<vector<int>> res;
        for(auto it = ms.begin(); it != ms.end(); ++it) {
            res.push_back(it->second);
        }

        return res;
    }
};
// @lc code=end


int main() {

    #ifdef LOCAL
        fr("./0tc.in");
        fw("./0tc.out");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string str;
    int k;

    Solution s;
    while( cin >> str >> k) {
        vector<vi> points = stringToIntegerVectorVector(str);
        auto res = s.kClosest(points, k);
        dbg(res);
    }
    return 0;
}