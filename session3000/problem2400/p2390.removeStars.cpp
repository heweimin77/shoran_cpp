#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for (auto x : s) {
            if (x == '*') {
                --j;
            } else {
                s[j++] = x;
            }
        }
        s.resize(j);
        return s;
    }
};

class P2090TestRemoveStars : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2090TestRemoveStars, Test1)
{
    Solution s;
    auto actual = s.removeStars("leet**cod*e");
    decltype(actual) expect = "lecoe";
    EXPECT_EQ(expect, actual);
}
TEST_F(P2090TestRemoveStars, Test2)
{
    Solution s;
    auto actual = s.removeStars("erase*****");
    decltype(actual) expect = "";
    EXPECT_EQ(expect, actual);
}
}


