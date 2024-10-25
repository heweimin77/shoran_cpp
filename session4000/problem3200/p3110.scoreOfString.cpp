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
    int scoreOfString(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            ans += abs(s[i]-s[i-1]);
        }
        return ans;
    }
};

class PTest3110 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3110, Test1) {
    Solution s;
    auto actual = s.scoreOfString("hello");
    decltype(actual) expect = 13;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3110, Test2) {
    Solution s;
    auto actual = s.scoreOfString("zaz");
    decltype(actual) expect = 50;
    EXPECT_EQ(expect, actual);
}
}


