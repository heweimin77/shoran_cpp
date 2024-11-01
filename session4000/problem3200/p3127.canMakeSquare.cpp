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
    bool canMakeSquare(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int r = 0;
                r += grid[i][j] == 'W' ? 1 : 0;
                r += grid[i-1][j] == 'W' ? 1 : 0;
                r += grid[i][j-1] == 'W' ? 1 : 0;
                r += grid[i-1][j-1] == 'W' ? 1 : 0;
                if (r != 2) return true;
            }
        }
        return false;
    }
};

class PTest3127 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3127, Test1) {
    Solution s;
    int target = 9;
    vector<vector<char>> grid = {{'B','W','B'},{'B','W','W'},{'B','W','B'}};
    auto actual = s.canMakeSquare(grid);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3127, Test2) {
    Solution s;
    vector<vector<char>> grid = {{'B','W','B'},{'W','B','W'},{'B','W','B'}};
    auto actual = s.canMakeSquare(grid);
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3127, Test3) {
    Solution s;
    vector<vector<char>> grid = {{'B','W','B'},{'B','W','W'},{'B','W','W'}};
    auto actual = s.canMakeSquare(grid);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
}


