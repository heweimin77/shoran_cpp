#include <gtest/gtest.h>
#include <bitset>

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
    long long maximumValueSum(vector<vector<int>>& board) {
        int INF = 1e9;
        int m = board.size(), n = board[0].size();
        vector<int> data1(n, -INF);
        vector<vector<int>> data2(n, vector<int>(n, -INF * 2));
        long long answer = -INF * 3LL;
        for (auto &row : board) {
            int m1 = -INF, m2 = -INF, m3 = -INF;
            for (int x : row) {
                if (x > m1) {
                    m3 = m2;
                    m2 = m1;
                    m1 = x;
                } else if (x > m2) {
                    m3 = m2;
                    m2 = x;
                } else if (x > m3) {
                    m3 = x;
                }
            }
            long long r = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    int xs1 = row[i], xs2 = row[j];
                    if (xs1 < xs2) swap(xs1, xs2);
                    if (m1 != xs1) r = m1;
                    else if (m2 != xs2) r = m2;
                    else r = m3;
                    answer = max(answer, data2[i][j] + r);
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) data2[i][j] = max(data2[i][j], data1[i] + row[j]);
                for (int j = i + 1; j < n; ++j) data2[j][i] = max(data2[j][i], data1[i] + row[j]);
            }
            for (int i = 0; i < n; ++i) data1[i] = max(data1[i], row[i]);
        }
        return answer;
    }
};

class PTest3257 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3257, Test1) {
    Solution s;
    vector<vector<int>> board = {{-3,1,1,1},{-3,1,-3,1},{-3,2,1,1}};
    auto actual = s.maximumValueSum(board);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3257, Test2) {
    Solution s;
    vector<vector<int>> board = {{1,2,3},{4,5,6},{7,8,9}};
    auto actual = s.maximumValueSum(board);
    decltype(actual) expect = 15;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3257, Test3) {
    Solution s;
    vector<vector<int>> board = {{1,1,1},{1,1,1},{1,1,1}};
    auto actual = s.maximumValueSum(board);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3257, Test4) {
    Solution s;
    vector<vector<int>> board = {{-1000000000,-1000000000,-1000000000},{-1000000000,-1000000000,-1000000000},{-1000000000,-1000000000,-1000000000}};
    auto actual = s.maximumValueSum(board);
    decltype(actual) expect = -3000000000;
    EXPECT_EQ(expect, actual);
}
}


