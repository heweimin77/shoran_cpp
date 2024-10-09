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
    int maxGoodNumber(vector<int>& nums) {
        auto getbyindexes = [&](const vector<int> &index)->int {
            vector<int> xs;
            for (auto x : {nums[index[2]], nums[index[1]]}) {
                while (x > 0) {
                    xs.push_back(x & 1);
                    x >>= 1;
                }
            }
            reverse(xs.begin(), xs.end());
            int ans = nums[index[0]];
            for (auto x : xs) {
                ans <<= 1;
                ans += x;
            }
            return ans;
        };
        vector<vector<int>> indexes = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
        int ans = 0;
        for (auto &index : indexes) {
            ans = max(ans, getbyindexes(index));
        }
        return ans;
    }
};

class PTest3309 : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3309, Test1) {
    Solution s;
    vector<int> nums = {1,2,3};
    auto actual = s.maxGoodNumber(nums);
    decltype(actual) expect = 30;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3309, Test2) {
    Solution s;
    vector<int> nums = {2,8,16};
    auto actual = s.maxGoodNumber(nums);
    decltype(actual) expect = 1296;
    EXPECT_EQ(expect, actual);
}
}


