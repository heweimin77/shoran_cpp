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
    int maximumPrimeDifference(vector<int>& nums) {
        bool notprimes[101] = {false};
        notprimes[0] = notprimes[1] = true;
        for (int i = 2; i <= 100; ++i) {
            if (notprimes[i]) continue;
            for (int j = i + i; j <= 100; j += i) {
                notprimes[j] = true;
            }
        }
        int ans = 0, first = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (!notprimes[nums[i]]) {
                first = min(first, i);
                ans = i - first;
            }
        }
        return ans;
    }
};

class PTest3115 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3115, Test1) {
    Solution s;
    vector<int> nums = {4,2,9,5,3};
    auto actual = s.maximumPrimeDifference(nums);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3115, Test2) {
    Solution s;
    vector<int> nums = {4,8,2,8};
    auto actual = s.maximumPrimeDifference(nums);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


