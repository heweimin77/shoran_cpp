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
    string largestPalindrome(int n, int k) {
        auto merge3 = [&](const string &x, char c) {
            return x + string(n - x.size() * 2, c) + x;
        };
        auto merge5 = [&](const string &p1, const string& p2, char c) {
            int m = (n - p1.size()*2 - p2.size()) / 2;
            return p1 + string(m, c) + p2 + string(m, c) + p1;
        };
        auto merge = [&](char x) {
            if (n <= 2) return string(n, x);
            return merge3(string(1, x), '9');
        };
        auto largest7 = [&]() {
            if (n <= 2) return string(n, '7');
            if (n & 1) {
                int m = n / 2, mp = 1, p = 1;
                int xx = 0;
                for (int i = 0; i < n; ++i) {
                    if (i != m)
                        xx += p * 9;
                    else {
                        mp = p;
                    }
                    p = (p * 10) % 7;
                }
                for (int d = 9; d >= 0; --d) {
                    if ((d * mp + xx) % 7 == 0)
                        return merge3(string(m, '9'), '0' + d);
                }
            } else {
                int m = n / 2, mp = 1, p = 1;
                int xx = 0;
                for (int i = 0; i < n; ++i) {
                    if (i == m - 1)
                        mp = p * 11;
                    else if (i != m)
                        xx += p * 9;
                    p = (p * 10) % 7;
                }
                for (int d = 9; d >= 0; --d) {
                    if ((d * mp + xx) % 7 == 0)
                        return merge3(string(m - 1, '9'), '0' + d);
                }
            }
            return string();
        };

        switch (k) {
            case 2:
                return merge('8');
            case 4:
                if (n <= 4) return string(n, '8');
                else return merge3("88", '9');
            case 5:
                return merge('5');
            case 6:
                if (n <= 2) return string(n, '6');
                else if (n & 1) return merge5("8", "8", '9');
                else return merge5("8", "77", '9');
            case 7:
                return largest7();
            case 8:
                if (n <= 6) return string(n, '8');
                else return merge3("888", '9');
            default:
                return string(n, '9');
        }
    }
};

class PTest3260 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3260, Test1) {
    Solution s;
    auto actual = s.largestPalindrome(3, 5);
    decltype(actual) expect = "595";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3260, Test2) {
    Solution s;
    auto actual = s.largestPalindrome(1, 4);
    decltype(actual) expect = "8";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3260, Test3) {
    Solution s;
    auto actual = s.largestPalindrome(5, 6);
    decltype(actual) expect = "89898";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3260, Test4) {
    Solution s;
    auto actual = s.largestPalindrome(3, 7);
    decltype(actual) expect = "959";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3260, Test5) {
    Solution s;
    auto actual = s.largestPalindrome(4, 7);
    decltype(actual) expect = "9779";
    EXPECT_EQ(expect, actual);
}
}


