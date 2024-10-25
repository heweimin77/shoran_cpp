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
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, inc = 1, dec = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                ++inc;
                ans = max(ans, inc);
            } else {
                inc = 1;
            }
            if (nums[i] < nums[i-1]) {
                ++dec;
                ans = max(ans, dec);
            } else {
                dec = 1;
            }

        }
        return ans;
    }
};

class PTest3105 : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3105, Test1) {
    Solution s;
    vector<int> nums = {1,4,3,3,2};
    auto actual = s.longestMonotonicSubarray(nums);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3105, Test2) {
    Solution s;
    vector<int> nums = {3,3,3,3};
    auto actual = s.longestMonotonicSubarray(nums);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3105, Test3) {
    Solution s;
    vector<int> nums = {3,2,1};
    auto actual = s.longestMonotonicSubarray(nums);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
}


