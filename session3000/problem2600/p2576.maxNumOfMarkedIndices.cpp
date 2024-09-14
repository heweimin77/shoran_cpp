#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j = n / 2, ans = 0;
        for (int i = 0; i < n / 2; ++i) {
            while (j < n && nums[j] < nums[i] + nums[i]) ++j;
            if (j == n) break;
            ++j;
            ++ans;
        }
        return ans << 1;
    }
};

class P2576Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2576Test, Test1)
{
    Solution s;
    vector<int> nums = {3,5,2,4};
    auto actual = s.maxNumOfMarkedIndices(nums);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2576Test, Test2)
{
    Solution s;
    vector<int> nums = {9,2,5,4};
    auto actual = s.maxNumOfMarkedIndices(nums);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2576Test, Test3)
{
    Solution s;
    vector<int> nums = {7,6,8};
    auto actual = s.maxNumOfMarkedIndices(nums);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


