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
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size()-2;
        for (int i = 0; i < n; ++i) {
            nums[i] ^= 1;
            if (nums[i]) {
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                ++ans;
            }
        }
        return nums[n] == 1 && nums[n+1] == 1 ? ans : -1;
    }
    int minOperations2(vector<int>& nums) {
        int n1 = 0, n2 = 0, ans = 0;
        for (auto n : nums) {
            n = 1 - n;
            ans += n1;
            n2 ^= n1;
            n ^= n1;
            n1 = n2;
            n2 = n;
        }
        return n1 == 0 && n2 == 0 ? ans : -1;
    }
};

class PTest3191 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3191, Test1) {
    Solution s;
    vector<int> nums = {0,1,1,1,0,0};
    auto actual = s.minOperations(nums);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3191, Test2) {
    Solution s;
    vector<int> nums = {0,1,1,1};
    auto actual = s.minOperations(nums);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
}


