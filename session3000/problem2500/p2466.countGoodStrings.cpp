#include <gtest/gtest.h>
#include <numeric>

using namespace std;

namespace {

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        constexpr int MOD = 1e9 + 7;
        vector<int> results(high + 1);
        results[0] = 1;
        for (int i = min(one, zero); i <= high; ++i) {
            int r = 0;
            if (i >= one) {
                r += results[i - one];
            }
            if (i >= zero) {
                r += results[i - zero];
            }
            if (r >= MOD) r -= MOD;
            results[i] = r;
        }
        return accumulate(results.begin() + low, results.end(), 0LL) % MOD;
    }
};

class P2466Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2466Test, Test1)
{
    Solution s;
    auto actual = s.countGoodStrings(3, 3, 1, 1);
    decltype(actual) expect = 8;
    EXPECT_EQ(expect, actual);
    
}

}
