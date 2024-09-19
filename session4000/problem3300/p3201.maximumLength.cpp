#include <gtest/gtest.h>
#include <algorithm>

using namespace std;

namespace {
class AutoRun {
public:
    AutoRun() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

} autorun;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ee = 0, eo = 0, oe = 0, oo = 0;
        for (int x : nums) {
            if (x & 1) {
                eo = max(eo, oe + 1);
                ++oo;
            } else {
                ++ee;
                oe = max(oe, eo + 1);
            }
        }
        vector<int> rs = {ee, eo, oe, oo};
        return *max_element(rs.begin(), rs.end());
    }
};

class P3201Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3201Test, Test1)
{
    Solution s;
    vector<int> nums = {1,2,3,4};
    auto actual = s.maximumLength(nums);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3201Test, Test2)
{
    Solution s;
    vector<int> nums = {1,2,1,1,2,1,2};
    auto actual = s.maximumLength(nums);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3201Test, Test3)
{
    Solution s;
    vector<int> nums = {1,3};
    auto actual = s.maximumLength(nums);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
}


