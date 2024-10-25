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
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            auto x = s[i];
            int kk = min(x - 'a', 'z' - x + 1);
            if (kk <= k) {
                k -= kk;
                s[i] = 'a';
            } else {
                s[i] = x - k;
                break;
            }
        }
        return s;
    }
};

class PTest3106 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3106, Test1) {
    Solution s;
    auto actual = s.getSmallestString("zbbz", 3);
    decltype(actual) expect = "aaaz";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3106, Test2) {
    Solution s;
    auto actual = s.getSmallestString("xaxcd", 4);
    decltype(actual) expect = "aawcd";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3106, Test3) {
    Solution s;
    auto actual = s.getSmallestString("lol", 0);
    decltype(actual) expect = "lol";
    EXPECT_EQ(expect, actual);
}
}


