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
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = 0;
        for (int j = 0; j < grid[0].size(); ++j) {
            int exp = INT_MIN;
            for (int i = 0; i < grid.size(); ++i) {
                exp = max(exp, grid[i][j]);
                ans += exp - grid[i][j];
                ++exp;
            }
        }
        return ans;
    }
};

class PTest3402 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3402, Test1) {
    Solution s;
    vector<vector<int>> grid = {{3,2},{1,3},{3,4},{0,1}};
    auto actual = s.minimumOperations(grid);
    decltype(actual) expect = 15;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3402, Test2) {
    Solution s;
    vector<vector<int>> grid = {{3,2,1},{2,1,0},{1,2,3}};
    auto actual = s.minimumOperations(grid);
    decltype(actual) expect = 12;
    EXPECT_EQ(expect, actual);
}
}


