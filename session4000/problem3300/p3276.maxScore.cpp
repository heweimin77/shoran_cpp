#include <gtest/gtest.h>
#include <algorithm>
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
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int limit = 1 << m;
        vector<unordered_set<int>> data;
        unordered_set<int> xs;
        for (auto &row : grid) {
            data.push_back(unordered_set<int>());
            for (auto x : row) {
                data.back().insert(x);
                xs.insert(x);
            }
        }

        vector<int> answers(limit);
        for (auto x : xs) {
            vector<int> nexts(limit);
            for (int i = 1; i < limit; ++i) {
                int r = answers[i];
                for (int j = 0; j < m; ++j) {
                    if (((1 << j) & i) == 0)  continue;
                    if (!data[j].contains(x)) continue;
                    r = max(r, x + answers[i & ~(1 << j)]);
                }
                nexts[i] = r;
            }
            answers = std::move(nexts);
        }
        return *max_element(answers.begin(), answers.end());
    }
};

class PTest3276 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3276, Test1) {
    Solution s;
    vector<vector<int>> grid = {{1,2,3},{4,3,2},{1,1,1}};
    auto actual = s.maxScore(grid);
    decltype(actual) expect = 8;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3276, Test2) {
    Solution s;
    vector<vector<int>> grid = {{8,7,6},{8,3,2}};
    auto actual = s.maxScore(grid);
    decltype(actual) expect = 15;
    EXPECT_EQ(expect, actual);
}
}


