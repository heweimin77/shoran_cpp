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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int nmax = *max_element(nums1.begin(), nums1.end());
        vector<int> counts(nmax + 1);
        for (auto x : nums2) {
            x *= k;
            if (x > nmax) continue;
            ++counts[x];
        }
        for (int i = nmax; i > 0; --i) {
            if (counts[i] == 0) continue;
            for (int j = i + i; j <= nmax; j += i) {
                counts[j] += counts[i];
            }
        }
        long long ans = 0;
        for (auto x : nums1) {
            ans += counts[x];
        }
        return ans;
    }
};

class PTest3164 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3164, Test1) {
    Solution s;
    vector<int> nums1 = {1,3,4};
    vector<int> nums2 = {1,3,4};
    int k = 1;
    auto actual = s.numberOfPairs(nums1, nums2, k);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3164, Test2) {
    Solution s;
    vector<int> nums1 = {1,2,4,12};
    vector<int> nums2 = {2,4};
    int k = 3;
    auto actual = s.numberOfPairs(nums1, nums2, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
}


