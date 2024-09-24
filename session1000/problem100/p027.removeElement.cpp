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
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        for (int v : nums) {
            if (v != val) {
                nums[ans++] = v;
            }
        }
        return ans;
    }
};

class P027Test : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P027Test, Test1) {
    Solution s;
    vector<int> nums = {3,2,2,3};
    int val = 3;
    auto actual = s.removeElement(nums, val);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}

TEST_F(P027Test, Test2) {
    Solution s;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    auto actual = s.removeElement(nums, val);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}

}


