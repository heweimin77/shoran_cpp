#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    int longestDecomposition(string text)
    {
        const char *p = text.c_str();
        return longestDecomposition(p, p + text.size() - 1);
    }
    int longestDecomposition(const char *s, const char *e)
    {
        const char *ss = s + 1, *ee = e - 1;
        int result = 1;
        for (; ss <= ee; ++ss, --ee) {
            if (equal(s, ss, ee + 1, e + 1)) {
                int r = 2 + longestDecomposition(ss, ee);
                result = max(result, r);
            }
        }
        return result;
    }
};

class P1147Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P1147Test, Test1)
{
    Solution s;
    auto actual = s.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi");
    decltype(actual) expect = 7;
    EXPECT_EQ(expect, actual);
}

TEST_F(P1147Test, Test2)
{
    Solution s;
    auto actual = s.longestDecomposition("merchant");
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(P1147Test, Test3) {
    Solution s;
    auto actual = s.longestDecomposition("antaprezatepzapreanta");
    decltype(actual) expect = 11;
    EXPECT_EQ(expect, actual);
}

}
