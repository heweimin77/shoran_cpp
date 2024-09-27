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
        int ans = 0, d1 = 0, d01 = 0;
        for (int i = 0, ni = m-1; i <= ni; ++i, --ni) {
            for (int j = 0, nj = n-1; j <= nj; ++j, --nj) {
                if (i == ni && j == nj) {
                    ans += grid[i][j];
                } else if (i == ni) {
                    int x = grid[i][j] + grid[i][nj];
                    if (x == 1) ++d01;
                    else if (x == 2) ++d1;
                } else if (j == nj) {
                    int x = grid[i][j] + grid[ni][j];
                    if (x == 1) ++d01;
                    else if (x == 2) ++d1;
                } else {
                    int x = grid[i][j] + grid[i][nj] + grid[ni][j] + grid[ni][nj];
                    ans += x <= 2 ? x : 4 - x;
                }
            }
        }
        return ans + (d01 == 0 ? (d1 & 1) * 2 : d01);
    }
};

class PTest3240 : public testing::Test
        {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3240, Test1) {
    Solution s;
    vector<vector<int>> grid = {{1,0,0},{0,1,0},{0,0,1}};
    auto actual = s.minFlips(grid);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3240, Test2) {
    Solution s;
    vector<vector<int>> grid = {{0,1},{0,1},{0,0}};
    auto actual = s.minFlips(grid);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3240, Test3) {
    Solution s;
    vector<vector<int>> grid = {{1},{1}};
    auto actual = s.minFlips(grid);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3240, Test4) {
    Solution s;
    vector<vector<int>> grid = {{0,0,1},{1,1,0},{1,1,1},{0,1,1}};
    auto actual = s.minFlips(grid);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
}


