#include <gtest/gtest.h>

using namespace std;

namespace {

  class Solution {
  public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
      sort(nums.begin(), nums.end());
      int lwr = nums.size() - 1, upr = nums.size() - 1;
      long long result = 0;
      for (int i = 0; i < nums.size(); ++i) {
        int limit = lower - nums[i];
        for (; lwr > i && nums[lwr] >= limit; --lwr);
        lwr = max(lwr, i);
        limit = upper - nums[i];
        for (; upr > i && nums[upr] > limit; --upr);
        if (upr == i) {
          break;
        }
        result += upr - lwr;
      }
      return result;
    }
  };

  class P2563Test :public testing::Test
  {
  public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
  };


  TEST_F(P2563Test, Test1)
  {
    vector<int> nums  = { 0, 1, 7, 4, 4, 5 };
    Solution s;
    auto actual = s.countFairPairs(nums, 3, 6);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
  }
}

