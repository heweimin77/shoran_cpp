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
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (auto n : nums) {
            auto r = 0;
            while (n > 0) {
                r += n % 10;
                n /= 10;
            }
            ans = min(ans, r);
        }
        return ans;
    }
};

class PTest3300 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3300, Test1) {
    Solution s;
    vector<int> nums = {10,12,13,14};
    auto actual = s.minElement(nums);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3300, Test2) {
    Solution s;
    vector<int> nums = {1,2,3,4};
    auto actual = s.minElement(nums);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3300, Test3) {
    Solution s;
    vector<int> nums = {999,19,199};
    auto actual = s.minElement(nums);
    decltype(actual) expect = 10;
    EXPECT_EQ(expect, actual);
}
}


