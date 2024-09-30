﻿#include <gtest/gtest.h>
#include <unordered_set>

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
    int countPairs(vector<int>& nums) {
        int base[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
        int limit = 1;
        for (int n : nums) while (base[limit] <= n) ++limit;
        unordered_map<int, unordered_set<int>> pairs;
        auto getv = [&](int n, int i) {
            return n / base[i] % 10;
        };
        auto getpair = [&](int n) ->unordered_set<int>& {
            auto it = pairs.find(n);
            if (it == pairs.end()) {
                it = pairs.insert(make_pair(n, unordered_set<int>())).first;
                unordered_set<int> &ps = it->second;
                ps.insert(n);
                for (int i = 0; i < limit; ++i) {
                    int iv = getv(n, i);
                    for (int j = 0; j < i; ++j) {
                        int jv = getv(n, j);
                        ps.insert(n + (iv - jv) * (base[j] - base[i]));
                    }
                }
            }
            return it->second;
        };

        unordered_map<int,int> counts;
        int ans = 0;
        for (int n : nums) {
            unordered_set<int> &ps = getpair(n);
            for (auto pn: ps) {
                ans += counts[pn];
            }
            ++counts[n];
        }
        return ans;
    }
};

class PTest3265 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3265, Test1) {
    Solution s;
    vector<int> nums = {3,12,30,17,21};
    auto actual = s.countPairs(nums);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3265, Test2) {
    Solution s;
    vector<int> nums = {1,1,1,1,1};
    auto actual = s.countPairs(nums);
    decltype(actual) expect = 10;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3265, Test3) {
    Solution s;
    vector<int> nums = {123,231};
    auto actual = s.countPairs(nums);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3265, Test4) {
    Solution s;
    vector<int> nums = {10,3,1,10,10,1,10};
    auto actual = s.countPairs(nums);
    decltype(actual) expect = 15;
    EXPECT_EQ(expect, actual);
}
}

