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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> answers;
        int n = nums.size();
        for (int a = 0; a < n; ++a) {
            if (a > 0 && nums[a] == nums[a-1]) continue;
            for (int b = a + 1; b < n; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                int d = n - 1;
                for (int c = b + 1 ; c < n; ++c) {
                    if (c > b + 1 && nums[c] == nums[c-1]) continue;
                    long long s = nums[a] + nums[b] + nums[c];
                    while (d > c && s + nums[d] > target) --d;
                    if (d == c) break;
                    if (s + nums[d] == target) {
                        answers.push_back({nums[a], nums[b], nums[c], nums[d]});
                    }
                }
            }
        }
        return answers;
    }
};

class P018Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P018Test, Test1)
{
    Solution s;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    auto actual = s.fourSum(nums, target);
    decltype(actual) expect = {{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}};
    EXPECT_EQ(expect, actual);
}
TEST_F(P018Test, Test2)
{
    Solution s;
    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    auto actual = s.fourSum(nums, target);
    decltype(actual) expect = {{2,2,2,2}};
    EXPECT_EQ(expect, actual);
}
}


