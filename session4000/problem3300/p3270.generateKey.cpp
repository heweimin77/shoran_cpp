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
    int generateKey(int num1, int num2, int num3) {
        int base = 1, ans = 0;
        while (num1 > 0 && num2 > 0 && num3 > 0) {
            int r = min({num1%10, num2%10, num3%10});
            ans += r * base;
            base *= 10;
            num1 /= 10, num2 /= 10, num3 /= 10;
        }
        return ans;
    }
};

class PTest3270 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3270, Test1) {
    Solution s;
    auto actual = s.generateKey(1, 10, 1000);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3270, Test2) {
    Solution s;
    auto actual = s.generateKey(987, 879, 798);
    decltype(actual) expect = 777;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3270, Test3) {
    Solution s;
    auto actual = s.generateKey(1, 2, 3);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}


