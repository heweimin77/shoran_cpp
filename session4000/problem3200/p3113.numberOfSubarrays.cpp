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
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = 0;
        vector<pair<int,int>> ss;
        for (auto x : nums) {
            while (!ss.empty() && ss.back().first < x) ss.pop_back();
            if (!ss.empty() && ss.back().first == x) {
                ss.back().second++;
            } else {
                ss.push_back({x, 1});
            }
            ans += ss.back().second;
        }
        return ans;
    }
};

class PTest3113 : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3113, Test1) {
    Solution s;
    vector<int> nums = {1,4,3,3,2};
    auto actual = s.numberOfSubarrays(nums);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3113, Test2) {
    Solution s;
    vector<int> nums = {3,3,3};
    auto actual = s.numberOfSubarrays(nums);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3113, Test3) {
    Solution s;
    vector<int> nums = {1};
    auto actual = s.numberOfSubarrays(nums);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}


