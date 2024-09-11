#include <gtest/gtest.h>

using namespace std;


namespace {

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> deltas(n, vector<int>(n + 1));
        for (auto &q : queries) {
            for (int i = q[0]; i <= q[2]; ++i) {
                ++deltas[i][q[1]];
                --deltas[i][q[3] + 1];
            }
        }
        vector<vector<int>> results(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                s += deltas[i][j];
                results[i][j] = s;
            }
        }
        return results;
        
    }
};

class P2536Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2536Test, Test1)
{
    vector<vector<int>> queries = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    Solution s;
    auto actual = s.rangeAddQueries(3, queries);
    decltype(actual) expect = {{1, 1, 0}, {1, 2, 1}, {0, 1, 1}};
    EXPECT_EQ(expect, actual);
}

}

