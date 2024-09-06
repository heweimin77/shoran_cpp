#include <gtest/gtest.h>

using namespace std;


namespace {

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> counts;
        for (auto& line : grid) {
            ++counts[line];
        }
        int result = 0;
        vector<int> col(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                col[j] = grid[j][i];
            }
            result += counts[col];
        }
        return result;
    }
};

class Solution2OK {
public:
    int equalPairs(vector<vector<int>> &grid)
    {   
        int n = grid.size();
        vector<int> data(n);
        auto xgrid = grid;
        sort(xgrid.begin(), xgrid.end());
        int result = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                data[i] = grid[i][j];
            }
            result += upper_bound(xgrid.begin(), xgrid.end(), data) - lower_bound(xgrid.begin(), xgrid.end(), data);
        }
        return result;
    }
};

class P2352Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2352Test, TestMain)
{
    vector<vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    Solution s;
    auto actual = s.equalPairs(grid);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}

}

