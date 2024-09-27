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
    long long maximumScore(vector<vector<int>>& gd) {
        int m = gd.size(), n = gd[0].size();
        vector<vector<long long>> grid(m, vector<long long>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = gd[i][j];
            }
        }
        for (int cur = 0; cur < n; ++cur) {
            for (int pre = 1; pre < m; ++pre) {
                grid[pre][cur] += grid[pre-1][cur];
            }
        }
        vector<pair<long long, long long>> results(m + 1);
        for (int j = 0; j < m - 1; ++j) {
            vector<pair<long long, long long>> nexts(m + 1);
            for (int pre = 0; pre <= m; ++pre) {
                long long r1 = 0, r2 = 0;
                for (int cur = 0; cur <= m; ++cur) {
                    auto&[rr1, rr2] = results[cur];
                    if (cur == pre) {
                        r1 = max(r1, rr1);
                        r2 = max(r2, rr1);
                    } else if (cur < pre) {
                        long long r = rr2 + grid[pre-1][j] - (cur > 0 ? grid[cur-1][j] : 0);
                        r1 = max(r1, r);
                        r2 = max(r2, r);
                    } else {
                        long long r = rr1 + grid[cur-1][j+1] - (pre > 0 ? grid[pre-1][j+1] : 0);
                        r1 = max(r1, r);
                        if (pre == 0) r2 = max(r2, rr1);
                    }
                }
                nexts[pre] = make_pair(r1, r2);
            }
            results = std::move(nexts);
        }
        long long ans = 0;
        for (int i = 0; i <= m; ++i) {
            ans = max(ans, results[i].first);
        }
        return ans;
    }
};

class PTest3225 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3225, Test1) {
    Solution s;
    vector<vector<int>> grid = {{0,0,0,0,0},{0,0,3,0,0},{0,1,0,0,0},{5,0,0,3,0},{0,0,0,0,2}};
    auto actual = s.maximumScore(grid);
    decltype(actual) expect = 11;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3225, Test2) {
    Solution s;
    vector<vector<int>> grid = {{10,9,0,0,15},{7,1,0,8,0},{5,20,0,11,0},{0,0,0,1,2},{8,12,1,10,3}};
    auto actual = s.maximumScore(grid);
    decltype(actual) expect = 94;
    EXPECT_EQ(expect, actual);
}
}


