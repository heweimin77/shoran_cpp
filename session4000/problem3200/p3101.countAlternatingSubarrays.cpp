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
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0, r = 0, last = 2;
        for (auto n : nums) {
            if (n == last) {
                r = 1;
            } else {
                ++r;
            }
            ans += r;
            last = n;
        }
        return ans;
    }
};

class PTest3101 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3101, Test1) {
    Solution s;
    vector<int> nums = {0,1,1,1};
    auto actual = s.countAlternatingSubarrays(nums);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3101, Test2) {
    Solution s;
    vector<int> nums = {1,0,1,0};
    auto actual = s.countAlternatingSubarrays(nums);
    decltype(actual) expect = 10;
    EXPECT_EQ(expect, actual);
}
}


