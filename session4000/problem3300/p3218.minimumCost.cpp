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
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), std::greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), std::greater<int>());
        vector<vector<int>> answers(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i== 0 && j== 0) continue;
                int r = INT_MAX;
                if (i > 0) {
                    r = min(r, answers[i-1][j] + (j + 1) * horizontalCut[i-1]);
                }
                if (j > 0) {
                    r = min(r, answers[i][j-1] + (i + 1) * verticalCut[j - 1]);
                }
                answers[i][j] = r;
            }
        }
        return answers.back().back();
    }
};

class PTest3218 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3218, Test1) {
    Solution s;
    int m = 3, n = 2;
    vector<int> horizontalCut = {1,3};
    vector<int> verticalCut = {5};
    auto actual = s.minimumCost(m, n, horizontalCut, verticalCut);
    decltype(actual) expect = 13;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3218, Test2) {
    Solution s;
    int m = 2, n = 2;
    vector<int> horizontalCut = {7};
    vector<int> verticalCut = {4};
    auto actual = s.minimumCost(m, n, horizontalCut, verticalCut);
    decltype(actual) expect = 15;
    EXPECT_EQ(expect, actual);
}
}


