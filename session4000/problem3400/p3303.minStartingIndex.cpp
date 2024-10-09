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
    int minStartingIndex(string s, string pattern) {
        auto getz = [](const string &s) {
            int n = s.size();
            vector<int> z(n);
            int l = 0, r = 0;
            for (int i = 1; i < n; ++i) {
                if (i <= r) {
                    z[i] = min(z[i-l], r - i + 1);
                }
                while (i + z[i] < n && s[z[i]] == s[i+z[i]]) {
                    l = i;
                    r = i + z[i];
                    ++z[i];
                }
            }
            return z;
        };
        int n = s.size(), m = pattern.size();
        auto prez = getz(pattern + s);
        reverse(pattern.begin(), pattern.end());
        reverse(s.begin(), s.end());
        auto sufz = getz(pattern + s);
        reverse(sufz.begin(), sufz.end());
        for (int i = 0; i < n - m + 1; ++i) {
            if (prez[i+m] + sufz[i+m-1] >= m - 1) return i;
        }
        return -1;
    }
};

class PTest3303 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3303, Test1) {
    Solution s;
    auto actual = s.minStartingIndex("abcdefg", "bcdffg");
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3303, Test2) {
    Solution s;
    auto actual = s.minStartingIndex("ababbababa", "bacaba");
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3303, Test3) {
    Solution s;
    auto actual = s.minStartingIndex("abcd", "dba");
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3303, Test4) {
    Solution s;
    auto actual = s.minStartingIndex("dde", "d");
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


