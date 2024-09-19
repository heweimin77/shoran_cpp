#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    int longestContinuousSubstring(const string &s) {
        int ans = 1;
        int r = 0;
        char expext = 'A';
        for (char x : s) {
            if (expext == x) {
                ++r;
            } else {
                ans = max(ans, r);
                r = 1;
            }
            expext = x + 1;
        }
        return max(ans, r);
    }
};

class PTest : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(PTest, Test1)
{
    Solution s;
    auto actual = s.longestContinuousSubstring("abacaba");
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest, Test2)
{
    Solution s;
    auto actual = s.longestContinuousSubstring("abcde");
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
}


