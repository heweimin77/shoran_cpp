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
    int strStr(string haystack, string needle) {
        string::size_type ans = haystack.find(needle);
        return ans == string::npos ? -1 : ans;
    }
};

class P028Test : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P028Test, Test1) {
    Solution s;
    auto actual = s.strStr("sadbutsad", "sad");
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(P028Test, Test2) {
    Solution s;
    auto actual = s.strStr("leetcode", "leeto");
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}

}


