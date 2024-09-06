#include <gtest/gtest.h>
#include <numeric>

using namespace std;

namespace {

class Solution {
    using Info = pair<int, int>;
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> indexes(n);
        iota(indexes.begin(), indexes.end(), 0);
        stable_sort(indexes.begin(), indexes.end(), [&](const int lhs, const int rhs) {
            return nums[lhs] > nums[rhs];
            });

        vector<int> results(n);
        set<Info> xxs;
        for (auto index : indexes) {
            Info now = { index, nums[index] };
            auto it = xxs.lower_bound(now);
            if (it != xxs.end()) {
                ++it;
            }
            results[index] = it == xxs.end() ? -1 : it->second;
            xxs.insert(now);
        }

        return results;
    }
};

class P2454Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2454Test, TestMain)
{
    vector<int> nums = { 2,4,0,9,6 };
    Solution s;
    auto actual = s.secondGreaterElement(nums);
    decltype(actual) expect = { 9,6,6,-1,-1 };
    EXPECT_EQ(expect, actual);
}
}

