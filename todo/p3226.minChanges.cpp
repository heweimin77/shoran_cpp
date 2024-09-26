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
    int minChanges(int n, int k) {
        if ((n | k) != n) return -1;
        n ^= k;
        int ans = 0;
        while (n > 0) {
            ++ans;
            n &= (n - 1);
        }
        return ans;
    }
};

class PTest3226 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3226, Test1) {
    Solution s;
    auto actual = s.minChanges(13, 4);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3226, Test2) {
    Solution s;
    auto actual = s.minChanges(21, 21);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3226, Test3) {
    Solution s;
    auto actual = s.minChanges(14, 13);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
}


