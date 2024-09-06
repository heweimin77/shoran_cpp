#include <gtest/gtest.h>
#include <climits>

using namespace std;

namespace {

class Solution {
public:
    int maxSum(vector<vector<int>> &grid)
    {
        int result = INT_MIN;
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int r = grid[i][j] + grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] + grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
                result = max(result, r);
            }
        }
        return result;
    }
};

class P2428Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2428Test, Test1)
{
    vector<vector<int>> grid = {{6, 2, 1, 3}, {4, 2, 1, 5}, {9, 2, 8, 7}, {4, 1, 2, 9}};
    Solution s;
    auto actual = s.maxSum(grid);
    decltype(actual) expect = 30;
    EXPECT_EQ(expect, actual);
}

}
