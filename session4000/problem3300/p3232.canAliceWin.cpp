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
    bool canAliceWin(vector<int>& nums) {
        int ans = 0;
        for (auto x : nums) {
            if (x < 10) {
                ans += x;
            } else {
                ans -= x;
            }
        }
        return ans != 0;
    }
};

class PTest3232 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3232, Test1) {
    Solution s;
    vector<int> nums = {1,2,3,4,10};
    auto actual = s.canAliceWin(nums);
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3232, Test2) {
    Solution s;
    vector<int> nums = {1,2,3,4,5,14};
    auto actual = s.canAliceWin(nums);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3232, Test3) {
    Solution s;
    vector<int> nums = {5,5,5,25};
    auto actual = s.canAliceWin(nums);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
}


