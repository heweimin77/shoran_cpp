#include <gtest/gtest.h>

using namespace std;

namespace {
class AutoRun {
public:
    AutoRun() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

} autorun;
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        //vector<vector<int>> answers(k, vector<int>(k));
        int answers[k][k];
        memset(answers, 0, sizeof(answers));
        for (int x : nums) {
            x %= k;
            for (int i = 0; i < k; ++i) {
                answers[i][x] = answers[x][i] + 1;
            }
        }
        int ans = 0;
        for (auto &as : answers) {
            for (auto &r : as) {
                ans = max(ans, r);
            }
        }
        return ans;
    }
};
class P3201Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3201Test, Test1)
{
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    int k = 2;
    auto actual = s.maximumLength(nums, k);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3201Test, Test2)
{
    Solution s;
    vector<int> nums = {1,4,2,3,1,4};
    int k = 3;
    auto actual = s.maximumLength(nums, k);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}

}


