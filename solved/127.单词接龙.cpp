/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 * 
 * 当单词表过大时，一一对比去计算两个单词之间是否可以转换的话则需要大量的时间。
 * 因此按照官方题解中的办法，可以按照一定的套路优化构造方法，而将时间复杂度从O(n*n)
 * 变成O(n*k)，其中k为单词平均长度。
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
private:
    int diff(string a, string b) {
        if(a.size() != b.size()) return -1;

        int dis = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a.at(i) != b.at(i)) dis += 1;
            if(dis > 1) return -1;
        }
        return 1;
    }

    // TLE
    int dijkstra(vector<vector<int>> adj, int s, int t) { 
        int n = adj.size();
        map<int, int> dist;
        bool *visited = new bool[n];
        int *dd = new int[n];  // record the shortest distance
        
        for(int i = 0; i < n; ++i) {
            dist[i] = INT_MAX;
            dd[i] = 0;
            visited[i] = false;
        }

        dist[s] = 0;
        while(visited[t] == false) {
            auto it = std::min_element(dist.begin(), dist.end(), [](const pair<int, int> a, const pair<int, int> b){
                return (a.second < b.second);
            });

            int node = it->first;
            int d = dist[node];

            if (d == INT_MAX) break; // unreachable nodes left

            dd[node] = d;
            dist.erase(node);
            visited[node] = true;

            for(auto nei : adj[node]) {
                if(nei == 1 && visited[nei] == false) {
                    int a = d + 1;
                    dist[nei] = (dist[nei] > a) ? a : dist[nei];
                }
            }
            // dbg(dist);
        }
        return dd[t];
    }
    
    int bfs_v1(vector<vector<int>> adj, int s, int t) {
        int n = adj.size();
        queue<int> nodes;
        
        bool *visited = new bool[n];
        int *dist = new int[n];
        for(int i = 0; i < n; ++i){
            visited[i] = false;
            dist[i] = 0;
        }

        dist[s] = 1;
        nodes.push(s);

        while(nodes.size() > 0) {
            int cur = nodes.front();
            nodes.pop();
            visited[cur] = true;

            for(int i = 0; i < n; ++i) {
                if(adj[cur][i] == 1 && visited[i] == false) {
                    dist[i] = dist[cur] + 1;
                    nodes.push(i);
                    if(i == t) return dist[t];
                }
            }
        }

        return dist[t];
    }

    // AC
    int bfs(vector<vector<int>> adj, int s, int t) {
        queue<int> nodes;
        int n = adj.size();


        int *dist = new int[n];
        bool *visited = new bool[n];

        for(int i = 0; i < n; i++) {
            dist[i] = 0;
            visited[i] = false;
        }
        
        nodes.push(s);

        while(nodes.empty() == false){
            int cur = nodes.front();
            nodes.pop();
            visited[cur] = true;

            for(auto nei : adj[cur]) {
                if(!visited[nei]) {
                    dist[nei] = dist[cur] + 1;
                    nodes.push(nei);
                    if(nei == t) {
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            cerr << dist[i] << ", ";
        }
        cerr << endl;

        return dist[t];
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) 
            return 0;

        if(std::find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) 
            wordList.insert(wordList.begin(), beginWord);

        unordered_map<string, int> wordId;
        // unordered_map<int, string> id2word;
        vector<vector<int>> adj;
        int id = 0;
        for(string s : wordList) {
            if(wordId.count(s) == 0) {
                // id2word[id] = s;
                wordId[s] = id++;
                adj.emplace_back();
            }

            string ss(s);
            for(int i = 0; i < s.size(); ++i) {
                char c = s.at(i);
                s.replace(i, 1, "*", 1);
                if(wordId.count(s) == 0) {
                    // id2word[id] = s;
                    wordId[s] = id++;
                    adj.emplace_back();
                }
                adj[wordId[ss]].push_back(wordId[s]);
                adj[wordId[s]].push_back(wordId[ss]);
                s = ss;
            }
        }

        // for(int i = 0; i < adj.size(); ++i) {
        //     cout << id2word[i] << " : ";
        //     for(auto neiId : adj[i]) {
        //         cout << id2word[neiId] << ", ";
        //     }
        //     cout << endl;
        // }


        int s = wordId[beginWord];
        int t = wordId[endWord];

        // vector<vector<int>> adj(n, vector<int>(n, 0));

        // int s = 0;
        // int t = 0;
        // for(int i = 0; i < n; i++) {
        //     adj[i][i] = -1;
        //     if(wordList[i] == beginWord) s = i;
        //     if(wordList[i] == endWord) t = i;

        //     for(int j = i+1; j < n; j++) {
        //         adj[i][j] = diff(wordList[i], wordList[j]);
        //         adj[j][i] = adj[i][j];
        //     }
        // }
        cerr << endWord << endl;

        int res = bfs(adj, s, t);
        res = (res == 0) ? 0 : res/2 + 1;
        return res;
    }
};
// @lc code=end


int main() {

    #ifdef LOCAL
        fr("./0_in.tc");
        fw("./0_out.tc");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif
    string b, e, l;
    Solution s;
    while(cin >> b >> e >> l) {
        auto sl = stringToStringVector(l);
        auto res = s.ladderLength(b, e, sl);
        cout << res << endl;
    }

    return 0;
}
/*


*/