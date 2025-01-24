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
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        for (auto x2: nums2) {
            x2 *= k;
            for (auto x1: nums1) {
                if (x1 % x2 == 0) ++ans;
            }
        }
        return ans;
    }
};

class PTest3162 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3162, Test1) {
    Solution s;
    vector<int> nums1 = {1,3,4};
    vector<int> nums2 = {1,3,4};
    int k = 1;
    auto actual = s.numberOfPairs(nums1, nums2, k);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3162, Test2) {
    Solution s;
    vector<int> nums1 = {1,2,4,12};
    vector<int> nums2 = {2,4};
    int k = 3;
    auto actual = s.numberOfPairs(nums1, nums2, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
}


