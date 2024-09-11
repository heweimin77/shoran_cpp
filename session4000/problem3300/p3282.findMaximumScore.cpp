#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0, r = 0;
        for (long long x : nums) {
            r = max(r, x);
            ans += r;
        }
        return ans - r;
    }
};

class P3282Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3282Test, Test1)
{
    Solution s;
    vector<int> nums = {1,3,1,5};
    auto actual = s.findMaximumScore(nums);
    decltype(actual) expect = 7;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3282Test, Test2)
{
    Solution s;
    vector<int> nums = {4,3,1,3,2};
    auto actual = s.findMaximumScore(nums);
    decltype(actual) expect = 16;
    EXPECT_EQ(expect, actual);
}

}


