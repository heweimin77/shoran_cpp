#include <gtest/gtest.h>
#include <cmath>

using namespace std;

namespace {
static auto autorun = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class UnionSet3 {
public:
    class UNode {
    public:
        UNode(int v) {
            value = key = v;
            parent = this;
            rank = 0;
        }
        int value = 0;
        int key = 0;
        UNode *parent;
        int rank = 0;
    };

    vector<UNode *> data;
    UnionSet3(int n) : data(n){
        for (int i = 0; i < n; ++i) {
            data[i] = new UNode(i);
        }
    }

    void merge(int x, int y) {
        auto xx = find_set(x);
        auto yy = find_set(y);
        if (xx == yy) return;
        int key = min(xx->key, yy->key);
        xx->key = yy->key = key;
        if (xx->rank > yy->rank)
            yy->parent = xx;
        else {
            xx->parent = yy;
            if (xx->rank == yy->rank)
                yy->rank += 1;
        }
    }

    UNode *find_set(int x) {
        auto node = data[x];
        auto find_node = [](UNode *node) {
            while (node != node->parent) {
                node = node->parent;
            }
            return node;
        };
        return find_node(node);
    }
    bool is_same_group(int x, int y) {
        auto xx = find_set(x);
        auto yy = find_set(y);
        return xx == yy;
    }
};

class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        UnionSet3 uset(n + 2);

        auto isConnect = [](long long x1, long long y1, long long x2, long long y2, long long xm, long long ym, long long x, long long y, long long r) {
            long long s1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) - r * r;
            long long s2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) - r * r;
            long long sm = (xm - x) * (xm - x) + (ym - y) * (ym - y) - r * r;
            if (s1 <= 0 || s2 <= 0) return true;
            if (x1 <= xm && xm <= x2 && y1 <= ym && ym <= y2) {
                if (sm <= 0) return true;
            }
            return false;
        };

        auto left_top = [&](int x, int y, int r) {
            return isConnect(0, 0, 0, Y, 0, y, x, y, r) || isConnect(0, Y, X, Y, x, Y, x, y, r);
        };

        auto right_bottom = [&](int x, int y, int r) {
            return isConnect(0, 0, X, 0, x, 0, x, y, r) || isConnect(X, 0, X, Y, X, y, x, y, r);
        };

        auto circle2 = [&](vector<int> &c1, vector<int> &c2) {
            long long x1 = c1[0], y1 = c1[1], r1 = c1[2];
            long long  x2 = c2[0], y2 = c2[1], r2 = c2[2];
            long long  ld = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            if (ld == 0) return false;
            double dd = sqrt(ld);
            if (!(abs(r1 - r2) <= dd && dd <= r1 + r2)) return false;
            double dr1 = r1 * dd / (r1 + r2);
            double xr = x1 + (x2 - x1) * dr1 / dd;
            double yr = y1 + (y2 - y1) * dr1 / dd;
            return 0 <= xr & xr <= X && 0 <= yr && yr <= Y;
        };

        for (int i = 0; i < circles.size(); ++i) {
            int x = circles[i][0], y = circles[i][1], r = circles[i][2];
            if (left_top(x, y, r)) {
                uset.merge(i, n);
            }
            if (right_bottom(x, y, r)) {
                uset.merge(i, n + 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (circle2(circles[i], circles[j]))
                    uset.merge(i, j);
            }
        }
        return !uset.is_same_group(n, n + 1);
    }
};

class PTest3235 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3235, Test1) {
    Solution s;
    int xCorner = 3, yCorner = 4;
    vector<vector<int>> circles = {{2,1,1}};
    auto actual = s.canReachCorner(xCorner, yCorner, circles);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3235, Test2) {
    Solution s;
    int xCorner = 3, yCorner = 3;
    vector<vector<int>> circles = {{1,1,2}};
    auto actual = s.canReachCorner(xCorner, yCorner, circles);
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3235, Test3) {
    Solution s;
    int xCorner = 3, yCorner = 3;
    vector<vector<int>> circles = {{2,1,1},{1,2,1}};
    auto actual = s.canReachCorner(xCorner, yCorner, circles);
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3235, Test4) {
    Solution s;
    int xCorner = 4, yCorner = 4;
    vector<vector<int>> circles = {{5,5,1}};
    auto actual = s.canReachCorner(xCorner, yCorner, circles);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
}


