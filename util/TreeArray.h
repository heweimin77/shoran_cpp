//
// Created by heweimin on 2024/9/27.
//

#ifndef SHORAN_CPP_TREEARRAY_H
#define SHORAN_CPP_TREEARRAY_H
#include <cstring>

class TreeArray {
public:
    TreeArray(int n) {
        this->n = n;
        data = new int[n+1];
        memset(data, 0, (n + 1) * sizeof(int));
    }
    ~TreeArray() {
        delete[] data;
    }
    int lb(int x) const { return x & (-x); }
    void add(int pos, int val) {
        for (; pos <= n; pos += lb(pos)) data[pos] += val;
    }
    int query (int pos) {
        int ret = 0;
        for (; pos; pos -= lb(pos)) ret += data[pos];
        return ret;
    };

private:
    int *data;
    int n;
};


#endif //SHORAN_CPP_TREEARRAY_H
