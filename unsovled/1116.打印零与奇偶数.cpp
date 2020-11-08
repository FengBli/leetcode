/*
 * @lc app=leetcode.cn id=1116 lang=cpp
 *
 * [1116] 打印零与奇偶数
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

// @lc code=start
class Semaphore {
public:
    Semaphore (int c = 0) : count(c) {}
    
    inline void notify( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        // cout << "thread " << tid <<  " notify" << endl;
        //notify the waiting thread
        cv.notify_one();
    }
    inline void wait( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        while(count == 0) {
            // cout << "thread " << tid << " wait" << endl;
            //wait on the mutex until notify is called
            cv.wait(lock);
            // cout << "thread " << tid << " run" << endl;
        }
        count--;
    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};
// TODO
class ZeroEvenOdd {
private:
    int n;
    std::mutex m1, m2, m3;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        m1.unlock();
        m2.lock();
        m3.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        m1.lock();
        printNumber(0);
        m2.unlock();
        m3.unlock();
    }

    void even(function<void(int)> printNumber) {
        static int i = 2;
        m2.lock();
        printNumber(i);
        i += 2;

        m1.unlock();
        m3.unlock();
    }

    void odd(function<void(int)> printNumber) {
        static int i = 1;
        m3.lock();
        printNumber(i);
        i += 2;

        m1.unlock();
        m2.unlock();
    }
};
// @lc code=end

