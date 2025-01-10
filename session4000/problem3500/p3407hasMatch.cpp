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
    bool hasMatch(string s, string p) {
        auto pp = p.find('*');
        auto p1 = s.find(p.substr(0, pp));
        if (p1 == string::npos) return false;
        auto p2 = s.find(p.substr(pp + 1), p1 + pp);
        return p2 != string::npos;
    }
};

class PTest3407 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3407, Test1) {
    Solution ss;
    string s = "leetcode", p = "ee*e";
    auto actual = ss.hasMatch(s, p);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3407, Test2) {
    Solution ss;
    string s = "car", p = "c*v";
    auto actual = ss.hasMatch(s, p);
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3407, Test3) {
    Solution ss;
    string s = "luck", p = "u*";
    auto actual = ss.hasMatch(s, p);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
}


