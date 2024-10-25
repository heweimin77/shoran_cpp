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
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int index = nums.size() / 2;
        long long ans = abs(nums[index] - k);
        for (int i = index - 1; i >= 0; --i) {
            if (nums[i]<= k) break;
            ans += nums[i] - k;
        }
        for (int i = index + 1; i < nums.size(); ++i) {
            if (nums[i]>= k) break;
            ans += k - nums[i];
        }
        return ans;
    }
};

class PTest3107 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3107, Test1) {
    Solution s;
    vector<int> nums = {2,5,6,8,5};
    int k = 4;
    auto actual = s.minOperationsToMakeMedianK(nums, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3107, Test2) {
    Solution s;
    vector<int> nums = {2,5,6,8,5};
    int k = 7;
    auto actual = s.minOperationsToMakeMedianK(nums, k);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3107, Test3) {
    Solution s;
    vector<int> nums = {1,2,3,4,5,6};
    int k = 4;
    auto actual = s.minOperationsToMakeMedianK(nums, k);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


