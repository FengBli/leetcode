/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
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


// @lc code=start
class Solution {
private:
    map<int, set<string>> memo;
    set<string> wordset;
    set<int> lenset;
    string target;

    void dp(string s, int i, set<string> &wordDict, set<int> lenSet, vector<string> &res, string output) {
        if(i == 0) {
            res.push_back(output);
            return;
        }

        for(auto l : lenSet) {
            if(i-l+1 < 1) continue;
            string ss = s.substr(i-l+1, l);
            if(wordDict.find(ss) != wordDict.end()){
                string newoutput = (output.size()==0) ? ss : ss + " " + output;

                dp(s, i-l, wordDict, lenSet, res, newoutput);
            }
        }
    }

    void backtrace(int i) {
        if (i == 0) {
            this->memo[i] = {""};
        }

        for(auto l : this->lenset) {
            if(i+1+l > this->target.size()) continue;
            string ss = target.substr(i+1, l);
            if(wordset.find(ss) != wordset.end()) {
                auto prefs = this->memo[i];
                for(string s : prefs) {
                    this->memo[i+l].emplace((s.size() == 0) ? ss : (s + " " + ss));
                }
                backtrace(i+l);
            }
        }

    }

public:
    // TLE
    vector<string> wordBreak_recursive(string s, vector<string>& wordDict) {

        // this->target = "#" + s;
        set<int> lenSet;
        vector<string> res;
        set<string> wd;
        
        for(auto w : wordDict) {
            lenSet.emplace(w.size());
            wd.emplace(w);
        }

        int len = s.size();
        string output = "";
        s = "#" + s;
        dp(s, len, wd, lenSet, res, output);

        return res;
    }


    // TODO
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        this->target = "#" + s;

        this->lenset.clear();
        this->memo.clear();
        this->wordset.clear();

        for(auto w : wordDict) {
            this->lenset.emplace(w.size());
            this->wordset.emplace(w);
        }

        int size = s.size();
        for(int i = 0; i <= size; ++i) {
            set<string> s;
            this->memo.emplace(i, s);
        }

        backtrace(0);

        auto r = this->memo[size];
        vector<string> res(r.begin(), r.end());
        return res;
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
    string s2;
    Solution s;
    while(cin >> str >> s2) {
        
        auto vs = stringToStringVector(s2);
        
        vector<string> res = s.wordBreak(str, vs);
        for (auto a : res) {
            cout << a << endl;
        }
        cout << "=====" << endl;
    }
    return 0;
}

/*
// TLE case 
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}
*/
