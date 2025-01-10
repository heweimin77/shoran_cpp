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
    int longestSubsequence(vector<int>& nums) {
        int nmax = *max_element(nums.begin(), nums.end());
        vector<vector<pair<int,int>>> answers(nmax + 1);
        auto get_value = [&](int i, int d) {
            if (i < 0 || i > nmax) return 0;
            auto &ans = answers[i];
            if (ans.empty()) return 0;
            auto it = upper_bound(ans.begin(), ans.end(), pair<int,int>{d, 0});
            if (it == ans.end()) return 0;
            return it->second;
        };
        for (int x : nums) {
            vector<pair<int,int>> ans;
            if (!answers[x].empty()) {
                ans.push_back({0, answers[x][0].second + 1});
            }
            for (int d = 1; d < max(x, nmax - x + 1); ++d) {
                auto lr = get_value(x - d, d);
                auto rr = get_value(x + d, d);
                auto r = max(lr, rr) + 1;
                if (r <= 1) continue;
                while (!ans.empty() and ans.back().second <= r) {
                    ans.pop_back();
                }
                ans.push_back({d, r});
            }
            ans.push_back({nmax, 1});
            answers[x] = ans;
        }
        int as = 0;
        for (auto &ans : answers) {
            if (ans.empty()) continue;
            as = max(as, ans[0].second);
        }
        return as;
    }
};

class PTest3409 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3409, Test1) {
    Solution s;
    vector<int> nums = {16,6,3};
    auto actual = s.longestSubsequence(nums);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3409, Test2) {
    Solution s;
    vector<int> nums = {6,5,3,4,2,1};
    auto actual = s.longestSubsequence(nums);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3409, Test3) {
    Solution s;
    vector<int> nums = {10,20,10,19,10,20};
    auto actual = s.longestSubsequence(nums);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
}


