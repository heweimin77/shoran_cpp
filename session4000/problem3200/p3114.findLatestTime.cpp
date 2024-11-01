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
    string findLatestTime(string s) {
        if (s[0] == '?') {
            s[0] = (s[1] == '?' || s[1] < '2') ? '1' : '0';
        }
        if (s[1] == '?') {
            s[1] = s[0] < '1' ? '9' : '1';
        }
        if (s[3] == '?') s[3] = '5';
        if (s[4] == '?') s[4] = '9';
        return s;
    }
};

class PTest3114 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3114, Test1) {
    Solution s;
    auto actual = s.findLatestTime("1?:?4");
    decltype(actual) expect = "11:54";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3114, Test2) {
    Solution s;
    auto actual = s.findLatestTime("0?:5?");
    decltype(actual) expect = "09:59";
    EXPECT_EQ(expect, actual);
}
}


