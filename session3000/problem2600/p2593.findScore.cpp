#include <gtest/gtest.h>

using namespace std;


namespace {
class Solution {
public:
    long long findScore(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> indexes(n);
        for (int i = 0; i < n; ++i) indexes[i] = i;
        stable_sort(indexes.begin(), indexes.end(), [&](int lhs, int rhs) {
            return nums[lhs] < nums[rhs];
        });
        long long result = 0;
        for (auto i : indexes) {
            if (nums[i] == 0) continue;
            result += nums[i];
            nums[i] = 0;
            if (i > 0) nums[i - 1] = 0;
            if (i < n - 1) nums[i + 1] = 0;
        }
        return result;
    }
};

class P2593Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2593Test, Test1)
{
    vector<int> nums = { 2,1,3,4,5,2 };
    Solution s;
    auto actual = s.findScore(nums);
    decltype(actual) expect = 7;
    EXPECT_EQ(expect, actual);
}

}

