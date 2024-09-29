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
    string stringHash(string s, int k) {
        string ans(s.size()/k, '0');
        for (int i = 0; i < s.size(); i += k) {
            int r = 0;
            for (int j = i; j < i + k; ++j) {
                r += s[j] - 'a';
            }
            ans[i/k] = 'a' + r % 26;
        }
        return ans;
    }
};

class PTest3271 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3271, Test1) {
    Solution s;
    auto actual = s.stringHash("abcd", 2);
    decltype(actual) expect = "bf";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3271, Test2) {
    Solution s;
    auto actual = s.stringHash("mxz", 3);
    decltype(actual) expect = "i";
    EXPECT_EQ(expect, actual);
}
}


