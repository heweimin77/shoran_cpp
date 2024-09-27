#include <gtest/gtest.h>

using namespace std;

namespace {
static auto autorun = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();
class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) : gd(grid), ps(grid.size() * grid[0].size()) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                ps[grid[i][j]] = {i, j};
            }
        }
    }
    int get (int x, int y) {
        if (x < 0 || x >= gd.size()) return 0;
        if (y < 0 || y >= gd[0].size()) return 0;
        return gd[x][y];
    }
    int adjacentSum(int value) {
        auto [x, y] = ps[value];
        return get(x-1,y) + get(x, y-1) + get(x, y+1) + get(x+1, y);
    }

    int diagonalSum(int value) {
        auto [x, y] = ps[value];
        return get(x-1,y-1) + get(x-1, y+1) + get(x+1, y-1) + get(x+1, y+1);
    }
private:
    vector<vector<int>> gd;
    vector<pair<int,int>> ps;
};

class PTest3242 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3242, Test1) {
    vector<vector<int>> grid = {{0, 1, 2},{3, 4, 5},{6, 7, 8}};
    NeighborSum ns(grid);
    EXPECT_EQ(6, ns.adjacentSum(1));
    EXPECT_EQ(16, ns.adjacentSum(4));
    EXPECT_EQ(16, ns.diagonalSum(4));
    EXPECT_EQ(4, ns.diagonalSum(8));
}
}


