/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]", debug_out(__VA_ARGS__)
#else
#define dbg(...) {}
#endif


// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // T(n) = O(n), S(n) = O(1)
    bool isPalindrome(ListNode* head) {
        bool res = true;
        ListNode *p1, *p2;
        p1 = head;
        p2 = head;

        int size = 1;

        if(nullptr == p1 || nullptr == p1->next) {
            res = true;
        } else {
            // find the length and middle point
            while(p1->next){
                p1 = p1->next;
                if(0 == size%2)
                    p2 = p2->next;
                size++;
            }

            if(0 == size%2) p2 = p2->next;

            // reverse the first half
            ListNode *prev = nullptr;
            for(ListNode *cur = head; cur != p2; ) {
                ListNode *post = cur->next;
                if(cur == head) {
                    cur->next = nullptr;
                    prev = cur;
                    cur = post;
                    post = post->next;
                } else {
                    cur->next = prev;
                    prev = cur;
                    cur = post;
                    post = post->next;
                }
            }

            if(1 == size%2) p2 = p2->next;

            for(int i = 0; i < size/2; ++i) {
                if( prev->val != p2->val) {
                    res = false;
                    break;
                }
                prev = prev->next;
                p2 = p2->next;
            }
        }
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

    string str;
    Solution s;
    while(cin >> str) {
        ListNode *head = stringToListNode(str);
        auto res = s.isPalindrome(head);
        cout << res << "：" << str << endl;
    }

}