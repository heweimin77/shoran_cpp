#include <gtest/gtest.h>

using namespace std;

namespace {
static auto autorun = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();
class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned d1 = dividend < 0 ? -(long long)dividend : dividend;
        unsigned d2 = divisor < 0 ? -(long long)divisor : divisor;
        d1 /= d2;
        if ((dividend < 0) == (divisor < 0)) {
            if (d1 > INT32_MAX) d1 = INT32_MAX;
            return d1;
        } else {
            if (d1 > (1 << 31)) d1 = 1 << 31;
            return -d1;
        }
    }
};

class P029Test : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P029Test, Test1) {
    Solution s;
    auto actual = s.divide(10, 3);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(P029Test, Test2) {
    Solution s;
    auto actual = s.divide(7, -3);
    decltype(actual) expect = -2;
    EXPECT_EQ(expect, actual);
}
}


