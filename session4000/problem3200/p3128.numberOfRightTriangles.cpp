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
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rowcounts(m), colcounts(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++rowcounts[i];
                    ++colcounts[j];
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ans += (rowcounts[i] - 1) * (colcounts[j] - 1);
                }
            }
        }
        return ans;
    }
};

class PTest3128 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3128, Test1) {
    Solution s;
    vector<vector<int>> grid = {{0,1,0},{0,1,1},{0,1,0}};
    auto actual = s.numberOfRightTriangles(grid);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3128, Test2) {
    Solution s;
    vector<vector<int>> grid = {{1,0,0,0},{0,1,0,1},{1,0,0,0}};
    auto actual = s.numberOfRightTriangles(grid);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3128, Test3) {
    Solution s;
    vector<vector<int>> grid = {{1,0,1},{1,0,0},{1,0,0}};
    auto actual = s.numberOfRightTriangles(grid);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
}


