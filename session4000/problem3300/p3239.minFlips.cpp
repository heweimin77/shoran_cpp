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
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rans = 0, cans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rans += grid[i][j] ^ grid[i][n-1-j];
                cans += grid[i][j] ^ grid[m-1-i][j];
            }
        }
        return min(rans, cans) / 2;
    }
};

class PTest3239 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3239, Test1) {
    Solution s;
    vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,1}};
    auto actual = s.minFlips(grid);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3239, Test2) {
    Solution s;
    vector<vector<int>> grid = {{0,1},{0,1},{0,0}};
    auto actual = s.minFlips(grid);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3239, Test3) {
    Solution s;
    vector<vector<int>> grid = {{1},{0}};
    auto actual = s.minFlips(grid);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


