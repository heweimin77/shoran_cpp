#include <gtest/gtest.h>

using namespace std;

namespace {
class AutoRun {
public:
    AutoRun() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
} autorun;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (!dp[i][j]) continue;
                if (j + 1 < n && p[j + 1] == '*') {
                    dp[i][j+2] = true;
                    for (int k = i; k < m; ++k) {
                        if (p[j] == '.' || p[j] == s[k]) {
                            dp[k+1][j+2] = true;
                        } else {
                            break;
                        }
                    }

                } else if (p[j] == '.' || p[j] == s[i]) {
                    if (i+1 <= m && j + 1 <= n) {
                        dp[i+1][j+1] = true;
                    }
                }
            }
        }

        return dp[m][n];
    }
};

class P010Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P010Test, Test1)
{
    Solution s;
    auto actual = s.isMatch("aa", "a");
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
TEST_F(P010Test, Test2)
{
    Solution s;
    auto actual = s.isMatch("aa", "a*");
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(P010Test, Test3)
{
    Solution s;
    auto actual = s.isMatch("ab", ".*");
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(P010Test, Test4)
{
    Solution s;
    auto actual = s.isMatch("mississippi", "mis*is*p*.");
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
}


