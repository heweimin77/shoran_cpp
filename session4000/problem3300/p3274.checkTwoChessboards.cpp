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
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return ((coordinate1[0] ^ coordinate1[1] ^ coordinate2[0] ^ coordinate2[1]) & 1) == 0;
    }
};

class PTest3274 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3274, Test1) {
    Solution s;
    auto actual = s.checkTwoChessboards("a1", "c3");
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3274, Test2) {
    Solution s;
    auto actual = s.checkTwoChessboards("a1", "h3");
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
}


