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
        int m = grid.size(), n = grid[0].size();
        int r1[10], r2[10];
        fill(r1, r1 + 10, 0);
        int *nows = r1, *nexts = r2;
        for (int j = 0; j < n; ++j) {
            int counts[10] = {0};
            for (int i = 0; i < m; ++i) {
                ++counts[grid[i][j]];
            }
            int m1 = INT_MAX, m2 = INT_MAX;
            for (int i = 0; i < 10; ++i) {
                if (nows[i] < m1) {
                    m2 = m1;
                    m1 = nows[i];
                } else if (nows[i] < m2) {
                    m2 = nows[i];
                }
            }
            for (int i = 0; i < 10; ++i) {
                nexts[i] = (nows[i] == m1 ? m2 : m1) + (m - counts[i]);
            }
            swap(nows, nexts);
        }
        return *min_element(nows, nows + 10);
    }
};

class PTest3122 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3122, Test1) {
    Solution s;
    vector<vector<int>> grid = {{1,0,2},{1,0,2}};
    auto actual = s.minimumOperations(grid);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3122, Test2) {
    Solution s;
    vector<vector<int>> grid = {{1,1,1},{0,0,0}};
    auto actual = s.minimumOperations(grid);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3122, Test3) {
    Solution s;
    vector<vector<int>> grid = {{1},{2},{3}};
    auto actual = s.minimumOperations(grid);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3122, Test4) {
    Solution s;
    vector<vector<int>> grid = {{0}};
    auto actual = s.minimumOperations(grid);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


