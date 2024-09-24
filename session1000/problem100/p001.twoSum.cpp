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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = indexes.find(target - nums[i]);
            if (it != indexes.end()) {
                return {it->second, i};
            }
            indexes[nums[i]] = i;
        }
        return {};
    }
};
class P001Test : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P001Test, Test1) {
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto actual = s.twoSum(nums, target);
    decltype(actual) expect = {0, 1};
    EXPECT_EQ(expect, actual);
}
TEST_F(P001Test, Test2) {
    Solution s;
    vector<int> nums = {3,2,4};
    int target = 6;
    auto actual = s.twoSum(nums, target);
    decltype(actual) expect = {1, 2};
    EXPECT_EQ(expect, actual);
}
TEST_F(P001Test, Test3) {
    Solution s;
    vector<int> nums = {3, 3};
    int target = 6;
    auto actual = s.twoSum(nums, target);
    decltype(actual) expect = {0, 1};
    EXPECT_EQ(expect, actual);
}
}


