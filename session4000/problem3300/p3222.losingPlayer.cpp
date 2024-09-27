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
    string losingPlayer(int x, int y) {
        int ans = min(x, y / 4);
        return (ans & 1) ? "Alice" : "Bob";
    }
};

class PTest3222 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3222, Test1) {
    Solution s;
    auto actual = s.losingPlayer(2, 7);
    decltype(actual) expect = "Alice";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3222, Test2) {
    Solution s;
    auto actual = s.losingPlayer(4, 11);
    decltype(actual) expect = "Bob";
    EXPECT_EQ(expect, actual);
}
}


