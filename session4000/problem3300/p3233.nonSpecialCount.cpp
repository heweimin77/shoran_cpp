#include <gtest/gtest.h>
#include <cmath>
#include "Math.h"

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
    int nonSpecialCount(int l, int r) {
        auto primes = Math::get_primes(sqrt(r));
        auto nonCount = [&](int n)->int {
            int x = sqrt(n);
            int count = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
            return n - count;
        };
        return nonCount(r) - nonCount(l-1);
    }
};

class PTest3233 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3233, Test1) {
    Solution s;
    auto actual = s.nonSpecialCount(5, 7);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3233, Test2) {
    Solution s;
    auto actual = s.nonSpecialCount(4, 16);
    decltype(actual) expect = 11;
    EXPECT_EQ(expect, actual);
}
}


