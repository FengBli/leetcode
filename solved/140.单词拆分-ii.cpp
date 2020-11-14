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
/**
class Solution {
private:
    map<int, vector<string>> memo;
    unordered_map<int, set<string>> memo2;
    unordered_set<string> wordset;
    set<int> lenset;
    string target;
    int ii;
    vector<bool> visited;

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

    // TLE, bottom-up
    void backtrace() { 
        this->memo[0] = {""};
        for(int i = 1; i < this->target.size(); ++i) {
            for(auto len : this->lenset) {
                if(len > i) break;
                string ss = target.substr(i-len+1, len);
                vector<string> prefs = this->memo[i-len];
                if(wordset.count(ss) > 0 && prefs.size() > 0) {
                    for(string prefix : prefs) {
                        string r = (prefix == "") ? ss : (prefix + " " + ss);
                        this->memo[i].push_back(r);
                    }
                }
            }
        }

        // for(auto i : this->memo) {
        //     cerr << i.first << ": [";
        //     for(string s : i.second) {
        //         cerr << "\"" << s << "\", ";
        //     }
        //     cerr << "]" << endl;
        // }
    }

    // top-down
    void backtrace(int i) {
        // cerr << "[STR] backtrace(" << i << ")" << endl;
        if(ii++ > 100) return;

        if(i == 0) {
            this->memo[i] = {""};
            this->visited[0] = true;
            return;
        }

        for(auto len : this->lenset) {
            if(len > i) break;

            string subs = this->target.substr(i-len+1, len);
            if(this->wordset.count(subs) > 0) {
                if(this->visited[i-len] == false) {
                    backtrace(i-len);
                    this->visited[i-len] = true;
                }

                for(string prefix : this->memo[i-len]) {
                    string r = (prefix == "") ? subs : (prefix + " " + subs);
                    this->memo[i].push_back(r);
                }
            } else {
                this->visited[i-len] = true;
            }
        }
        // cerr << "[END] backtrace(" << i << "), len(memo) = " << this->memo.size() << endl;
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
        this->memo2.clear();
        this->wordset.clear();

        this->wordset = unordered_set<string>(wordDict.begin(), wordDict.end());
        

        for(auto w : wordset) {
            this->lenset.emplace(w.size());
        }
        ii = 0;
        int size = s.size();
        this->visited = vector<bool>(size, false);
        backtrace(size);

        // auto r = this->memo2[size];
        // return vector<string>(r.begin(), r.end());
        return this->memo[size];
    }

};
**/

// AC, COPIED. 本地跑TLE的testcase一样会TLE，为何可以提交AC？怀疑此题有问题！！！
class Solution {
private:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];
    }

    void backtrack(const string& s, int index) {
        if (!ans.count(index)) {
            if (index == s.size()) {
                ans[index] = {""};
                return;
            }
            ans[index] = {};
            for (int i = index + 1; i <= s.size(); ++i) {
                string word = s.substr(index, i - index);
                if (wordSet.count(word)) {
                    backtrack(s, i);
                    for (const string& succ: ans[i]) {
                        ans[index].push_back(succ.empty() ? word : word + " " + succ);
                    }
                }
            }
        }
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/word-break-ii/solution/dan-ci-chai-fen-ii-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end

int main() {

    #ifdef LOCAL
        fr("./0_in.tc");
        fw("./0_out.tc");
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
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
*/
