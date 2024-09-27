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
    int minChanges(vector<int>& nums, int k) {
        vector<int> counts2(k + 2), counts0(k + 2);
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i], b = nums[n - 1 - i];
            if (a > b) swap(a, b);
            ++counts0[b - a];
            ++counts2[max(b, k - a) + 1];
        }
        int ans = n, r = 0;
        for (int i = 0; i <= k; ++i) {
            r += counts2[i];
            ans = min(ans, r - counts0[i]);
        }
        return n / 2 + ans;
    }
};

class PTest3224 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3224, Test1) {
    Solution s;
    vector<int> nums = {1,0,1,2,4,3};
    int k = 4;
    auto actual = s.minChanges(nums, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3224, Test2) {
    Solution s;
    vector<int> nums = {0,1,2,3,3,6,5,4};
    int k = 6;
    auto actual = s.minChanges(nums, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3224, Test3) {
    Solution s;
    vector<int> nums = {0,11,9,6,1,15,6,0,12,14};
    int k = 15;
    auto actual = s.minChanges(nums, k);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
}


