#include <gtest/gtest.h>
#include "Math.h"

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
    int maxLength(vector<int>& nums) {
        int ans = 2;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int gcd = Math::gcd(nums[i], nums[i + 1]);
            int lcm = Math::lcm(nums[i], nums[i + 1]);
            for (int j = i + 2; j < nums.size(); ++j) {
                if (nums[j] % gcd != 0) break;
                if (lcm * nums[j] != Math::lcm(lcm, nums[j])) break;
                lcm *= nums[j];
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

class PTest3411 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3411, Test1) {
    Solution s;
    vector<int> nums = {1,2,1,2,1,1,1};
    auto actual = s.maxLength(nums);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3411, Test2) {
    Solution s;
    vector<int> nums = {2,3,4,5,6};
    auto actual = s.maxLength(nums);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3411, Test3) {
    Solution s;
    vector<int> nums = {1,2,3,1,4,5,1};
    auto actual = s.maxLength(nums);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
}


