/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */
#pragma GCC optimize("Ofast")
#define DBG_MACRO_NO_WARNING
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;

#ifdef LOCAL
    #include "dbg.h"
#endif

#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define REP(x, l, u) for(ll x = l; x < u; x++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

using namespace std;

// @lc code=start
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : myHashMap(mod) { }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int c = key % this->mod;
        auto &list = this->myHashMap[c];
        for(auto it = list.begin(); it != list.end(); ++it) {
            if(it->first == key) {
                it->second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int c = key % this->mod;
        auto &list = this->myHashMap[c];
        for(auto it = list.begin(); it != list.end(); ++it) {
            if(it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int c = key % this->mod;
        auto &list = this->myHashMap[c];
        auto it = list.begin();
        for(; it != list.end(); ++it) {
            if(it->first == key) {
                list.erase(it);
                return;
            }
        }
    }
private:
    int mod = 1009;
    vector<list<pair<int, int>>> myHashMap;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

