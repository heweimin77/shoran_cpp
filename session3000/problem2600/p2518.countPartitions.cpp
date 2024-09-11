#include <gtest/gtest.h>
#include <numeric>

using namespace std;

namespace {

class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    int countPartitions(vector<int> &nums, int k)
    {
        if (accumulate(nums.begin(), nums.end(), 0LL) < k + k) return 0;
        vector<long long> results(k);
        results[0] = 1;
        for (auto n : nums) {
            if (n >= k) continue;
            for (int i = k - 1; i >= n; --i) {
                results[i] += results[i - n];
                if (results[i] >= MOD) results[i] -= MOD;
            }
        }
        long long r = accumulate(results.begin(), results.end(), 0LL);
        r <<= 1;
        r %= MOD;
        return (fast_power(2, nums.size(), MOD) + MOD - r) % MOD;
    }
    long long fast_power(long long base, long long n, long long module)
    {
        long long result = 1;
        int mask = 1;
        for (int mask = 1; mask <= n; mask <<= 1) {
            if (mask & n) {
                result *= base;
                result %= module;
            }
            base *= base;
            base %= module;
        }
        return result;
    }
};

class P2518Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2518Test, TestMain)
{
    vector<int> nums = { 1,2,3,4 };
    Solution s;
    auto actual = s.countPartitions(nums, 4);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
}

