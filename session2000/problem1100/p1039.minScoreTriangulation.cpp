#include <gtest/gtest.h>
#include <climits>

using namespace std;


namespace {

class Solution {
public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> results(n, vector<int>(n));
        for (int d = 2; d < n; ++d) {
            for (int i = 0, j = d; j < n; ++i, ++j) {
                int result = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    int r = values[i] * values[j] * values[k] + results[i][k] + results[k][j];
                    result = min(result, r);
                }
                results[i][j] = result;
            }
        }
        return results[0].back();
    }
};

class P1039Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P1039Test, Test1)
{
    vector<int> nums = { 1,3,1,4,1,5 };
    Solution s;
    auto actual = s.minScoreTriangulation(nums);
    decltype(actual) expect = 13;
    EXPECT_EQ(expect, actual);
}

}

