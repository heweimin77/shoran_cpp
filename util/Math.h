//
// Created by heweimin on 2024/9/26.
//

#ifndef SHORAN_CPP_MATH_H
#define SHORAN_CPP_MATH_H

#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

class Math {
public:
    static vector<int> get_primes(int n) {
        vector<int> primes, minfactor(n + 1);
        for (int i = 2; i <= n; ++i) {
            if (minfactor[i] == 0) {
                minfactor[i] = i;
                primes.push_back(i);
            }
            for (auto p : primes) {
                if (i * p > n) break;
                minfactor[i * p] = p;
                if (p == minfactor[i]) break;
            }
        }
        return primes;
    }
    static long long fast_power(long long base, int n, long long module) {
        long long ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans *= base;
                ans %= module;
            }
            base *= base;
            base %= module;
            n >>= 1;
        }
        return ans;
    }
    static long long invert(int x, int module) {
        return fast_power(x, module - 2, module);
    }

    template<class INT>
    static INT gcd(INT a, INT b) {
        if (a > b) swap(a, b);
        while (a) {
            int c = b % a;
            b = a;
            a = c;
        }
        return b;
    }
    template<class INT>
    static INT lcm(INT a, INT b) {
        return a * b / gcd(a, b);
    }
};

class Comb {
public:
    Comb(int n, long long module) : f(n + 1), invf(n + 1) {
        this->module = module;
        f[0] = 1;
        for (int i = 1; i <= n; ++i) f[i] = f[i-1] * i % module;
        invf[n] = Math::invert(f[n], module);
        for (int i = n; i > 0; --i) invf[i-1] = invf[i] * i % module;
    }
    long long comb(int n, int k) {
        auto ans = f[n] * invf[k] % module;
        return ans * invf[n - k] % module;
    }
private:
    long long module;
    vector<long long> f;
    vector<long long> invf;
};


#endif //SHORAN_CPP_MATH_H
