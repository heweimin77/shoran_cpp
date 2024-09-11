#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        map<int, long long> results;
        for (int i = 0; i < nums.size(); ++i) {
            int d = nums[i] - i;
            long long v = nums[i];
            auto it = results.upper_bound(d);
            if (it == results.begin()) {
                it = results.insert({ d, v}).first;
            } else {
                --it;
                v += max(0LL, it->second);
                if (it->first == d) {
                    it->second = v;
                } else {
                    it = results.insert({ d, v }).first;
                }
            }
            for (++it; it != results.end() && it->second <= v;) {
                it = results.erase(it);
            }

        }

        return results.rbegin()->second;
    }
};

class P2926Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};


TEST_F(P2926Test, Test1)
{
    vector<int> nums = { 3,3,5,6 };
    Solution s;
    auto actual = s.maxBalancedSubsequenceSum(nums);
    decltype(actual) expect = 14;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2926Test, TestMain)
{
    vector<int> nums = { 5,-1,-3,8 };
    Solution s;
    auto actual = s.maxBalancedSubsequenceSum(nums);
    decltype(actual) expect = 13;
    EXPECT_EQ(expect, actual);
}

}
