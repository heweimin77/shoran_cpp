#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;


namespace {
class Solution {
public:
    long long countGood(vector<int> &nums, int k)
    {
        unordered_map<int, int> counts;
        int n = nums.size();
        int j = 0;
        int kk = 0;
        long long result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (; j < n && kk < k; ++j) {
                int x = ++counts[nums[j]];
                kk += x - 1;
            }
            if (kk < k) break;
            result += n - j + 1;
            int x = --counts[nums[i]];
            kk -= x;
        }
        return result;
    }
};

class P2537Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2537Test, Test1)
{
    vector<int> nums = { 1,1,1,1,1 };
    Solution s;
    auto actual = s.countGood(nums, 10);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}

}

