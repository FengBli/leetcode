/*
Sieve of Eratosthenes
https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

TODO: 
    1. a better timer wrapper
    2. segmented sieve
*/

#include<iostream>
#include<vector>
#include<cmath>
#include <chrono> // 计时

// T(n) = O(n log log(n)), S(n) = O(n)
// 时间复杂度的分析见上述链接，渐进分析
long long count_prime(long long n) {
    std::vector<bool> is_prime(n, true);
    is_prime[0] = false;
    is_prime[1] = false;

    long long root = (long long) std::ceil(std::sqrt(n));

    for(long long i = 2; i < n; ++i) {
        if(is_prime[i] && i <= root) { // root以上的数也无需访问，
            for(long long j = i * i; j < n; j += i) { // i的2，3，……，i-1等倍数已经在2，3，……的i倍时标记过
                is_prime[j] = false;
            }
        }
    }
    long long result = 0;
    for(long long i = 0; i < n; i++) {
        if(is_prime[i]) {
            result++;
        }
    }

    return result;
}

// 常数系数优化，
long long count_prime_v2(long long n) {
    std::vector<bool> is_prime(n, true);
    is_prime[0] = false;
    is_prime[1] = false;

    long long root = (long long) std::ceil(std::sqrt(n));

    for(long long i = 2; i < root; ++i) { // MODIFIED: 遍历上界变为sqrt(n)
        if(is_prime[i]) {
            for(long long j = i * i; j < n; j += i) { 
                is_prime[j] = false;
            }
        }
    }

    long long result = 0;
    for(long long i = 0; i < n; i++) {
        if(is_prime[i]) {
            result++;
        }
    }

    return result;
}

// 常数优化，只遍历奇数
long long count_prime_v3(long long n) {
    std::vector<bool> is_prime(n, true);
    is_prime[0] = false;
    is_prime[1] = false;
    is_prime[2] = true;

    long long root = (long long) std::ceil(std::sqrt(n));

    for(long long i = 3; i < root; i += 2) { // MODIFIED: 只遍历奇数
        if(is_prime[i]) {
            for(long long j = i * i; j < n; j += i) { 
                is_prime[j] = false;
            }
        }
    }

    long long result = 0;
    for(long long i = 0; i < n; i++) {
        if(is_prime[i]) {
            result++;
        }
    }

    return result;
}

int main() {

    long long n = 2000000; // 以下三个版本的耗时依次为：114810 74361 54177

    auto t1 = std::chrono::high_resolution_clock::now();
    count_prime(n);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration << std::endl;

    t1 = std::chrono::high_resolution_clock::now();
    count_prime_v2(n);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration << std::endl;

    t1 = std::chrono::high_resolution_clock::now();
    count_prime_v3(n);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration << std::endl;

    return 0;
}