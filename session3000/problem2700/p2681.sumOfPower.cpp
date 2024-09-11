#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    int sumOfPower(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        long long lowsum = 0;
        long long result = 0;
        for (auto n : nums) {
            long long r = lowsum + n;
            r *= n;
            r %= MOD;
            r *= n;
            result += r;
            result %= MOD;
            lowsum <<= 1;
            lowsum += n;
            lowsum %= MOD;
        }
        return result;
    }
};

class P2681Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2681Test, TestMain)
{
    vector<int> nums = { 2, 1, 4 };
    Solution s;
    auto actual = s.sumOfPower(nums);
    decltype(actual) expect = 141;
    EXPECT_EQ(expect, actual);
}

}
