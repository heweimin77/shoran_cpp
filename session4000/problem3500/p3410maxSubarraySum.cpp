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
    long long maxSubarraySum(vector<int>& nums) {
        int nmax = *max_element(nums.begin(), nums.end());
        if (nmax <= 0) return nmax;
        int n = nums.size();
        vector<long long> sums(n);
        sums[0] = nums[0];
        for (int i = 1; i < n; ++i) sums[i] = sums[i-1] + nums[i];
        long long ans = 0, base = 0, r = 0;
        unordered_map<int, long long> results;
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            r += x;
            if (x > 0) {
                ans = max(ans, r);
            } else {
                long long ans2 = base;
                auto it = results.find(x);
                if (it != results.end()) {
                    ans2 = max(ans2, it->second + sums[i - 1] - sums[indexes[x]]);
                }
                r = max(r, ans2);
                results[x] = ans2;
                indexes[x] = i;
            }
            base = max(base + x, 0LL);
        }
        return ans;
    }
};

class PTest3410 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3410, Test1) {
    Solution s;
    vector<int> nums = {-3,2,-2,-1,3,-2,3};
    auto actual = s.maxSubarraySum(nums);
    decltype(actual) expect = 7;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3410, Test2) {
    Solution s;
    vector<int> nums = {1,2,3,4};
    auto actual = s.maxSubarraySum(nums);
    decltype(actual) expect = 10;
    EXPECT_EQ(expect, actual);
}
}


