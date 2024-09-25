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
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> counts(n);
        int ans = 0;
        for (auto &line : grid) {
            int xcnt = 0, ycnt = 0;
            for (int i = 0; i < n; ++i) {
                auto x = line[i];
                if (x == 'X') ++xcnt;
                else if (x == 'Y') ++ycnt;
                counts[i].first += xcnt;
                counts[i].second += ycnt;
                if (counts[i].first == counts[i].second && counts[i].first > 0) ++ans;
            }
        }
        return ans;
    }
};

class PTest3212 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3212, Test1) {
    Solution s;
    vector<vector<char>> grid = {{'X','Y','.'},{'Y','.','.'}};
    auto actual = s.numberOfSubmatrices(grid);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3212, Test2) {
    Solution s;
    vector<vector<char>> grid = {{'X','X'},{'X','Y'}};
    auto actual = s.numberOfSubmatrices(grid);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3212, Test3) {
    Solution s;
    vector<vector<char>> grid = {{'.','.'},{'.','.'}};
    auto actual = s.numberOfSubmatrices(grid);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


