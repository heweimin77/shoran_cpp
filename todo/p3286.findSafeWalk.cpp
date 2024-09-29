#include <gtest/gtest.h>
#include <queue>

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
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int OFFSET = 2;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> nows;
        grid[0][0] += OFFSET;
        nows.push_back({0, 0});
        while (!nows.empty()) {
            vector<pair<int,int>> nexts;
            while (!nows.empty()) {
                auto [x, y] = nows.back();
                nows.pop_back();
                for (auto [nx, ny] : vector<pair<int,int>>({{x-1,y},{x+1,y},{x,y-1}, {x, y+1}})) {
                    if (nx < 0 || nx >= m) continue;
                    if (ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] >= OFFSET) continue;
                    grid[nx][ny] += grid[x][y];
                    //cout << x << ", " << y << ": "  << nx << ", " << ny << ", " << grid[nx][ny] << endl;
                    if (grid[nx][ny] == grid[x][y]) {
                        nows.push_back({nx, ny});
                    } else {
                        nexts.push_back({nx,ny});
                    }
                }
            }
            nows = std::move(nexts);
        }

        return grid[m-1][n-1] < health + OFFSET;
    }
};

class PTest3286 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3286, Test1) {
    Solution s;
    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    int health = 1;
    auto actual = s.findSafeWalk(grid, health);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3286, Test2) {
    Solution s;
    vector<vector<int>> grid = {{0,1,1,0,0,0},{1,0,1,0,0,0},{0,1,1,1,0,1},{0,0,1,0,1,0}};
    int health = 3;
    auto actual = s.findSafeWalk(grid, health);
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3286, Test3) {
    Solution s;
    vector<vector<int>> grid = {{1,1,1},{1,0,1},{1,1,1}};
    int health = 5;
    auto actual = s.findSafeWalk(grid, health);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}

}


