//
// Created by heweimin on 2024/9/26.
//

#ifndef SHORAN_CPP_MATH_H
#define SHORAN_CPP_MATH_H
#include <vector>

using std::vector;

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
};


#endif //SHORAN_CPP_MATH_H
