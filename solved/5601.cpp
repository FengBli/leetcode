
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

class OrderedStream {
private:
    int len;
    int ptr;
    map<int, string> ss;
public:
    OrderedStream(int n) {
        this->len = n;
        this->ptr = 1;
        this->ss = map<int, string>();
    }
    
    vector<string> insert(int id, string value) {
        vector<string> ans;
        if(0 >= id || this->len < id) {
            return vector<string>();
        }
        this->ss.emplace(id, value);
        if(ptr <= len) {
            auto it = this->ss.find(ptr);
            if(it != this->ss.end()) {
                for(int i = ptr; this->ss.count(i) > 0; ++i) {
                    ptr = i + 1;
                    ans.push_back(this->ss[i]);
                }
            }
        }
        dbg(ans);
        return ans;
    }
};

int main() {
    int n = 10;
    OrderedStream *os= new OrderedStream(5);
    os->insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
    os->insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
    os->insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
    os->insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
    os->insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
}