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
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> answers(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        answers[0][0] = {coins[0][0], max(coins[0][0], 0), max(coins[0][0], 0)};
        auto update = [](vector<int> &r, vector<int> &r1, int c) {
            r[0] = max(r[0], r1[0] + c);
            r[1] = max(r[1], r1[1] + c);
            r[2] = max(r[2], r1[2] + c);
            r[1] = max(r[1], r1[0]);
            r[2] = max(r[2], r1[1]);
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                auto &r = answers[i][j];
                auto c = coins[i][j];
                if (i > 0) {
                    update(r, answers[i-1][j], c);
                }
                if (j > 0) {
                    update(r, answers[i][j - 1], c);
                }
            }
        }
        return answers[m - 1][n - 1][2];
    }
};

class PTest3418 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3418, Test1) {
    Solution s;
    vector<vector<int>> coins  = {{0,1,-1},{1,-2,3},{2,-3,4}};
    auto actual = s.maximumAmount(coins);
    decltype(actual) expect = 8;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3418, Test2) {
    Solution s;
    vector<vector<int>> coins  = {{10,10,10},{10,10,10}};
    auto actual = s.maximumAmount(coins);
    decltype(actual) expect = 40;
    EXPECT_EQ(expect, actual);
}
}


