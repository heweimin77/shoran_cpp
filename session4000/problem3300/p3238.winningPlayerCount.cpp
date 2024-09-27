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
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int counts[11][11] = {0};
        for (auto &p : pick) {
            ++counts[p[0]][p[1]];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 11; ++j) {
                if (counts[i][j] > i) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};

class PTest3238 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3238, Test1) {
    Solution s;
    int n = 4;
    vector<vector<int>> pick = {{0,0},{1,0},{1,0},{2,1},{2,1},{2,0}};
    auto actual = s.winningPlayerCount(n, pick);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3238, Test2) {
    Solution s;
    int n = 5;
    vector<vector<int>> pick = {{1,1},{1,2},{1,3},{1,4}};
    auto actual = s.winningPlayerCount(n, pick);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3238, Test3) {
    Solution s;
    int n = 5;
    vector<vector<int>> pick = {{1,1},{2,4},{2,4},{2,4}};
    auto actual = s.winningPlayerCount(n, pick);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}


