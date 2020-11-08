/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

// @lc code=start
class Solution {
public:

    // 2d DP
    int change_2d(int amount, vector<int>& coins) {
        int m = coins.size();
        int **dp = (int**) malloc(sizeof(int*)*(m+1));
        for(int i = 0; i < m+1; ++i) {
            dp[i] = (int*) malloc(sizeof(int)*(amount+1));
            memset(dp[i], 0, sizeof(int)*(amount+1));
            dp[i][0] = 1;
        }

        for(int i = 1; i < m+1; ++i) {
            for(int j = 1; j < amount+1; ++j) {
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    int temp = 0;
                    for(int k = 0; k <= j/coins[i-1]; ++k)
                        temp += dp[i-1][j-k*coins[i-1]];
                    dp[i][j] = temp;
                }
            }
        }
        return dp[m][amount];
    }

    // 1d DP
    int change_1d(int amount, vector<int> &coins) {
        int m = coins.size();
        int *dp = (int*) malloc(sizeof(int)*(amount+1));
        memset(dp, 0, sizeof(int)*(amount+1));
        dp[0] = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = amount; j > 0; --j) {
                if(coins[i] <= j) {
                    int temp = 0;
                    for(int k = 0; k <= j/coins[i]; ++k) 
                        temp += dp[j-k*coins[i]];
                    dp[j] = temp;
                }
                if(i == m-1)break;
            }
        }
        return dp[amount];
    }

    // reference
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(auto coin : coins) {
            for(int j = coin; j <= amount; ++j) {
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end


int main() {

    #ifdef LOCAL
        fr("./tc.in");
        fw("./tc.out");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string str;
    int a;
    Solution s;
    while( cin >> a >> str) {
        auto nums = stringToIntegerVector(str);
        auto res = s.change(a, nums);
        cout << res << endl;
    }
    return 0;
}