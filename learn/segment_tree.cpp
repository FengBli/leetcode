#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>

#ifdef LOCAL
#include "dbg.h"
#endif

#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define vi vector<int>

using namespace std;

#define MAXN 32

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
    const char delim = ',';
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
    if(!item.empty())
        output.push_back(stringToIntegerVector(item + "]"));

    while(getline(ss, item, delim)) {
        item = item.substr(1, item.size()-1);
        output.push_back(stringToIntegerVector(item + "]"));
    }
    return output;
}

// T(n) = O(n)
void build(vector<int> &t, vector<int> a, int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(t, a, v*2, tl, tm);
        build(t, a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

// T(n) = O(log(n))
int sum(vector<int> t, int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tr && r == tr) return t[v];

    int tm = (tl + tr) / 2;
    return sum(t, v*2, tl, tm, l, min(r, tm)) + sum(t, v*2+1, tm, tr, max(l, tm+1), r);
}

// T(n) = O(log(n))
void update(vi &t, int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if(pos < tm) update(t, v*2, tl, tm, pos, new_val);
        else update(t, v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[2*v+1];
    }
}


int main() {

    #ifdef LOCAL
        fr("../0_in.tc");
        fw("../0_out.tc");
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    string str;
    while( cin >> str ) {
        vector<int> nums = stringToIntegerVector(str);
        vector<int> t(MAXN, 0);
        build(t, nums, 1, 0, nums.size() - 1);
        dbg(t);
    }
    return 0;
}