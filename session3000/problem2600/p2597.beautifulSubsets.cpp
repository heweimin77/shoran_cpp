#include <gtest/gtest.h>

using namespace std;


namespace {

class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int counts[1000] = { 0 };
        int result = 0;
        traverse(nums, k, 0, result, counts);
        return result;
    }
    void traverse(vector<int> &nums, int k, int i, int &result, int counts[])
    {
        if (i == nums.size()) return;
        traverse(nums, k, i + 1, result, counts);
        int n = nums[i] - 1;
        int nk = n - k;
        if (nk >= 0 && counts[nk] > 0) return;
        nk = n + k;
        if (nk < 1000 && counts[nk] > 0) return;
        ++result;
        ++counts[n];
        traverse(nums, k, i + 1, result, counts);
        --counts[n];
    }
};

class P2597Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2597Test, Test1)
{
    vector<int> nums = { 14,10,24,25,29,8,27,26,15,11,3,19,23,5,22,16,28,17 };
    Solution s;
    auto actual = s.beautifulSubsets(nums, 27);
    decltype(actual) expect = 262143;
    EXPECT_EQ(expect, actual);
}

}

