﻿#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

namespace {

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<long long> counts3(n);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int count2 = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    ans += counts3[j];
                    ++count2;
                } else {
                    counts3[j] += count2;
                }
            }
        }

        return ans;
    }
};


class Solution2Timeout {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        vector<int> counts3(n);
        vector<unordered_map<int, int>> counts2(n);
        vector<int> counts1(n);
        for (auto x : nums) {
            --x;
            for (int i = 0; i < x; ++i) {
                result += counts3[i];
            }
            for (auto& r : counts2[x]) {
                counts3[r.first] += r.second;
            }
            int cnt = 0;
            for (int i = 0; i < x; ++i) {
                counts2[i][x] += cnt;
                cnt += counts1[i];
            }
            ++counts1[x];
        }
        return result;
    }
};

class P2552Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2552Test, Test1)
{
    vector<int> nums = { 1,3,2,4,5 };
    Solution s;
    auto actual = s.countQuadruplets(nums);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2552Test, TestMain)
{
    vector<int> nums = { 1,3,5,2,4 };
    Solution s;
    auto actual = s.countQuadruplets(nums);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}
