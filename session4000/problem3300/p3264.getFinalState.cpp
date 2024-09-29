#include <gtest/gtest.h>
#include <queue>

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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for (int i = 0; i < nums.size(); ++i) q.push({nums[i], i});
        for (int j = 0; j < k; ++j) {
            auto [v, i] = q.top();
            q.pop();
            nums[i] = v * multiplier;
            q.push({nums[i], i});
        }
        return nums;
    }
};

class PTest3264 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3264, Test1) {
    Solution s;
    vector<int> nums = {2,1,3,5,6};
    int k = 5, multiplier = 2;
    auto actual = s.getFinalState(nums, k, multiplier);
    decltype(actual) expect = {8,4,6,5,6};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3264, Test2) {
    Solution s;
    vector<int> nums = {1,2};
    int k = 3, multiplier = 4;
    auto actual = s.getFinalState(nums, k, multiplier);
    decltype(actual) expect = {16,8};
    EXPECT_EQ(expect, actual);
}
}


