// TODO
#pragma GCC optimize("Ofast")
#define DBG_MACRO_NO_WARNING
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
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

vector<vector<int> > stringToIntegerVectorVector(string input) {
    vector<vector<int> > output;
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

vector<vector<string> > stringToStringVectorVector(string input) {
    vector<vector<string> > output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ']';
    getline(ss, item, delim);
    if(!item.empty()) {
        output.push_back(stringToStringVector(item + "]"));
    }
    while(getline(ss, item, delim)) {
        item = item.substr(1, item.length() - 1);
        output.push_back(stringToStringVector(item + "]"));
    }
    return output;
}

class Solution {
public:
    bool exist(vector<vector<string> >& board, string word) {
        
        int m = board.size();
        if(m == 0) return false;
        int n = board[0].size();
        if(n == 0) return false;

        int len = word.length();

        // find the start points
        vector<pair<int, int> > starts;
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(board[i][j].at(0) == word.at(0)) {
                    starts.emplace_back(i, j);
                }
            }
        }

        if (starts.size() == 0) return false;
        if (len == 1) return true;

        int r[] = {1, -1, 0, 0};
        int c[] = {0, 0, -1, 1};
        
        
        for(auto a : starts) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            stack<pair<int, int>> q;
            q.push(a);
            // cout << word[0] << " pushed into Stack." << endl;
            int cnt = 1;

            while(!q.empty()) {
                auto p = q.top();
                int i = p.first;
                int j = p.second;

                visited[i][j] = true;
                bool has = false;
                for(int ii = 0; ii < 4; ++ii) {
                    int x = i + r[ii];
                    int y = j + c[ii];

                    if(check(x, y, m, n) && visited[x][y] == false && board[x][y].at(0) == word[cnt]) {
                        
                        q.emplace(x, y);
                        cnt++;
                        // cout << board[x][y] << " pushed into Stack." << endl;
                        if (cnt == len - 1) return true;
                        has = true;
                        break;
                    }
                }
                if (!has) {
                    q.pop();
                    cnt--;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool check(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
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
    string str, word;
    Solution s;
    while( cin >> str >> word) {
        word = word.substr(1, word.length()-1);

        auto board = stringToStringVectorVector(str);

        auto res = s.exist(board, word);
        cout << "res = " << res << endl;
    }
    return 0;
}

/*

[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCE"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCFB"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
""
[["A"]]
"A"
[["A","B","C","E"]]
"AB"

*/
