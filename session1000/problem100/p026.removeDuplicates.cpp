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
    int removeDuplicates(vector<int>& nums) {
        int r = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[r]) {
                nums[++r] = nums[i];
            }
        }
        return r + 1;
    }
};

class P026Test : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P026Test, Test1) {
    Solution s;
    vector<int> nums = {1,1,2};
    auto actual = s.removeDuplicates(nums);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(P026Test, Test2) {
    Solution s;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    auto actual = s.removeDuplicates(nums);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}

}


