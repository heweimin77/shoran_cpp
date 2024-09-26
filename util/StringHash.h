//
// Created by heweimin on 2024/9/26.
//

#ifndef SHORAN_CPP_STRINGHASH_H
#define SHORAN_CPP_STRINGHASH_H
#include <string>
#include <vector>


class StringHash {
public:
    using ValueType = long long;
    StringHash(int b, int m) : bbase({1}){
        base = b;
        mod = m;
    }
    int hash(const std::string &w, int start, int end) {
        ValueType ans = 0;
        for (int i = start; i < end; ++i) {
            ans = (ans * base + w[i] - 'a') % mod;
        }
        return ans;
    }
    int rehash(int hash, char add, char del, int n) {
        int a = add - 'a', d = del - 'a';
        prebase(n);
        return (int)((((ValueType)hash - d * bbase[n - 1]) * base + a) % mod + mod) % mod;
    }

    std::vector<int> get_prehash(const std::string &w) {
        std::vector<int> pre_hash(w.size() + 1);
        for (int i = 0; i < w.size(); i++) {
            pre_hash[i + 1] = ((ValueType) pre_hash[i] * base + w[i] - 'a') % mod; // 秦九韶算法计算多项式哈希
        }
        return pre_hash;
    }
    int get_hash(std::vector<int> &prehash, int left, int right) {
        prebase(right - left + 1);
        return ((prehash[right] - (ValueType) prehash[left] * bbase[right - left]) % mod + mod) % mod;
    }

    void prebase(int n) {
        int i = bbase.size();
        if (i >= n) return;
        bbase.resize(n);
        for (; i < n; ++i) {
            bbase[i] = (int)((bbase[i-1] * base) % mod);
        }
    }

private:
    ValueType base;
    ValueType mod;
    std::vector<int> bbase;
};


#endif //SHORAN_CPP_STRINGHASH_H
