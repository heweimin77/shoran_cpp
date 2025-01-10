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
    long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<double, long long> counts;
        long long ans = 0;
        for (int i = 4; i < nums.size() - 2; ++i) {
            double r = nums[i-2];
            for (int j = 0; j <= i - 4; ++j) {
                counts[nums[j]/r] += 1;
            }
            r = nums[i];
            for (int j = i + 2; j < nums.size(); ++j) {
                auto rr = nums[j] / r;
                auto it = counts.find(rr);
                ans += it == counts.end() ? 0 : it->second;
            }
        }
        return ans;
    }
};

class PTest3404 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3404, Test1) {
    Solution s;
    vector<int> nums = {1,2,3,4,3,6,1};
    auto actual = s.numberOfSubsequences(nums);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3404, Test2) {
    Solution s;
    vector<int> nums = {3,4,3,4,3,4,3,4};
    auto actual = s.numberOfSubsequences(nums);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
}


