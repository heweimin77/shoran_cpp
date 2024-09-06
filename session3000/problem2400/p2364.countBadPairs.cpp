#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;


namespace {

class Solution {
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, int> counts;
        int n = nums.size();
        long long result = (n - 1LL) * n / 2;
        for (int i = 0; i < n; ++i) {
            auto x = nums[i] - i;
            result -= counts[x]++;
        }
        return result;
    }
};

class P2364Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2364Test, Test1)
{
    vector<int> nums = { 4,1,3,3 };
    Solution s;
    auto actual = s.countBadPairs(nums);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}

}

