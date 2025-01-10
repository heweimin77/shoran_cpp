#include <gtest/gtest.h>
#include "Math.h"

using namespace std;

namespace {
static auto autorun = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();
int mod = 1e9 + 7;
Comb cb(100000, mod);
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        long long ans = cb.comb(n - 1, k) * m % mod;
        return  ans * Math::fast_power(m - 1, n - k - 1, mod) % mod;
    }
};

class PTest3405 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3405, Test1) {
    Solution s;
    int n = 3, m = 2, k = 1;
    auto actual = s.countGoodArrays(n, m, k);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3405, Test2) {
    Solution s;
    int n = 4, m = 2, k = 2;
    auto actual = s.countGoodArrays(n, m, k);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3405, Test3) {
    Solution s;
    int n = 5, m = 2, k = 0;
    auto actual = s.countGoodArrays(n, m, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
}


