#include <gtest/gtest.h>
#include <unordered_set>
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
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjs(n);
        for (auto &e: edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }
        int start = 0;
        for (int i = 0; i < n; ++i) {
            if (adjs[i].size() < adjs[start].size()) start = i;
        }
        if (adjs[start].size() == 1) {
            vector<vector<int>> answers(1);
            auto &ans = answers[0];
            ans.push_back(start);
            int pre = adjs[start][0];
            ans.push_back(pre);
            for (int i = 2; i < n; ++i) {
                pre = adjs[pre][0] + adjs[pre][1] - ans[i-2];
                ans.push_back(pre);
            }
            return answers;
        }
        auto select1 = [&](int nb1, int nb2, int ex) {
            for (auto x : adjs[nb1]) {
                if (x == ex) continue;
                for (auto x2 : adjs[nb2]) {
                    if (x2 != x) continue;
                    return x2;
                }
            }
            return -1;
        };
        auto select2 = [&](int nb, int ex1, int ex2) {
            for (auto x : adjs[nb]) {
                if (x == ex1 || x == ex2) continue;
                return x;
            }
            return -1;
        };
        vector<vector<int>> ans = {{start, adjs[start][0] },{ adjs[start][1], select1(adjs[start][0], adjs[start][1], start)}};
        int i = 0, j = 0;
        while (true) {
            j = ans[0].size() - 1;
            int r1 = select2(ans[0][j], ans[0][j-1], ans[1][j]);
            if (r1 < 0) break;
            int r2 = select1(r1, ans[1][j], ans[0][j]);
            ans[0].push_back(r1);
            ans[1].push_back(r2);
        }
        while (true) {
            i = ans.size()-1;
            int r = select2(ans[i][0], ans[i][1], ans[i-1][0]);
            if (r < 0) break;
            ans.push_back({r});
            for (j = 1; j < ans[0].size(); ++j) {
                r = select1(ans[i+1][j-1], ans[i][j], ans[i][j-1]);
                ans[i+1].push_back(r);
            }
        }

        return ans;
    }
};

class PTest3311 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3311, Test1) {
    Solution s;
    int n = 4;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{2,3}};
    auto actual = s.constructGridLayout(n, edges);
    decltype(actual) expect = {{0,1}, {2,3}};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3311, Test2) {
    Solution s;
    int n = 9;
    vector<vector<int>> edges = {{0,1},{0,4},{0,5},{1,7},{2,3},{2,4},{2,5},{3,6},{4,6},{4,7},{6,8},{7,8}};
    auto actual = s.constructGridLayout(n, edges);
    decltype(actual) expect = { { 1, 0, 5 }, { 7, 4, 2 }, { 8, 6, 3 } };
    EXPECT_EQ(expect, actual);
}
}


