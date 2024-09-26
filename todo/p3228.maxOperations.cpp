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
    int maxOperations(string s) {
        int ans = 0, cnt = 0;
        char lx = '0';
        for (auto x : s) {
            if (x == '1') ++cnt;
            else if (lx == '1'){
                ans += cnt;
            }
            lx = x;
        }
        return ans;
    }
};

class PTest3228 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3228, Test1) {
    Solution s;
    auto actual = s.maxOperations("1001101");
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3228, Test2) {
    Solution s;
    auto actual = s.maxOperations("00111");
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


