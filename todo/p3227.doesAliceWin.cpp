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
    bool doesAliceWin(string s) {
        int flag[128] = {0};
        flag['a'] = flag['e'] = flag['i']  = flag['o'] = flag['u'] = 1;
        int ecount = 0;
        for (auto x : s) {
            ecount += flag[x];
        }
        return ecount > 0;
    }
};

class PTest3227 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3227, Test1) {
    Solution s;
    auto actual = s.doesAliceWin("leetcoder");
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3227, Test2) {
    Solution s;
    auto actual = s.doesAliceWin("bbcd");
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
}


