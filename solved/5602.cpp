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

class Solution {
public:
    int minOperations_v1(vector<int>& nums, int x) {
        int left = 1;
        int n = nums.size();
        int right = n - 1;
        int xx = x;
        int res = INT_MAX;
        for(int i = -1; i < n; ++i) {
            if(i != -1)
                xx -= nums[i];
            
            if(xx == 0) {
                res = (res < (i+1)) ? res : i+1;
            }

            if(xx < 0) break;

            int xxx = xx;
            for(int j = n-1; j > i; --j) {
                xxx -= nums[j];
                int t = i+1 + (n - j);
                if(xxx == 0){ 
                    res < t ? res : t;
                    break;
                }
                if(xxx < 0) break;
            }
        }

        return res == INT_MAX ? -1 : res;
    }

    int minOperations(vector<int>& nums, int x) {
        vector<int> prefix_sum, suffix_sum;
        int sum = 0;
        prefix_sum.push_back(0);
        for(auto it = nums.begin(); it != nums.end(); ++it) {
            sum += *it;
            prefix_sum.push_back(sum);
        }
        
        if(*prefix_sum.rbegin() < x ) {
            return -1;
        }

        sum = 0;
        for(auto it = nums.rbegin(); it != nums.rend(); ++it) {
            sum += *it;
            suffix_sum.push_back(sum);
        }

        int res = INT_MAX;
        for(auto it = prefix_sum.begin(), it2 = suffix_sum.end(); it != prefix_sum.end(); ++it, --it2) {
            if(*it == x) {
                int r = (it - prefix_sum.begin());
                res = (res < r) ? res : r;
            }
            if(*it > x) break;
            auto itt = lower_bound(suffix_sum.begin(), it2, x - (*it));
            if((*itt) == (x - (*it))) {
                int l = it - prefix_sum.begin();
                int rr = itt - suffix_sum.begin() + 1;
                int r = l + rr;

                res = (res < r) ? res : r;
            }
        }
        return res == INT_MAX ? -1 : res;
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
    int n;
    string str;
    Solution s;
    while(cin >> str >> n) {
        auto nums = stringToIntegerVector(str);
        auto res = s.minOperations(nums, n);
        cout << res << endl;
    }
    return 0;
}