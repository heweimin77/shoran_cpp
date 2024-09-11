#include <gtest/gtest.h>
#include "support.h"

using namespace std;

namespace {

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        for (int i = 0; i < n; ++i) {
            if (lcp[i][i] != n - i) {
                return "";
            }
            for (int j = i; j < n; ++j) {
                if (lcp[i][j] != lcp[j][i]) {
                    return "";
                }
            }
        }

        char ch = 'b';
        string result(n, 'a');
        for (int i = 1; i < n; ++i) {
            int x = -1;
            for (int j = 0; j < i; ++j) {
                if (lcp[i][j] > 0) {
                    if (x >= 0 && result[x] != result[j]) {
                        return "";
                    }
                    x = j;
                }
            }
            if (x == -1) result[i] = ch++;
            else result[i] = result[x];
            if (result[i] > 'z') {
                return "";
            }
        }

        // check
        for (int d = 1; d < n; ++d) {
            int count = -1;
            for (int i = 0, j = d; j < n; ++i, ++j) {
                if (count < 0) {
                    count = 0;
                    for (int k = j; k < n && result[k] == result[k - d]; ++k) ++count;
                }
                if (lcp[i][j] != count) {
                    return "";
                }
                --count;
            }
        }


        return result;
    }
};

class P2573Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2573Test, Test1)
{
    vector<vector<int>> lcp = { {4,0,2,0}, {0,3,0,1}, {2,0,2,0}, {0,1,0,1} };
    Solution s;
    auto actual = s.findTheString(lcp);
    decltype(actual) expect = "abab";
    EXPECT_EQ(expect, actual);
}
TEST_F(P2573Test, Test2)
{
    vector<vector<int>> lcp = { {4,3,2,1}, {3,3,2,1}, {2,2,2,1}, {1,1,1,1} };
    Solution s;
    auto actual = s.findTheString(lcp);
    decltype(actual) expect = "aaaa";
    EXPECT_EQ(expect, actual);
}

}
