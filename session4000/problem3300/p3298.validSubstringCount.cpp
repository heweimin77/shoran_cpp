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
    long long validSubstringCount(string word1, string word2) {
        int cnts[26] = {0};
        for (auto x : word2) ++cnts[x - 'a'];
        int cnt = 26 - count(cnts, cnts + 26, 0);
        long long j = 0, ans = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (--cnts[word1[i]-'a'] == 0) --cnt;
            while (cnt == 0) {
                if (++cnts[word1[j++]-'a'] == 1) ++cnt;
            }
            ans += j;
        }
        return ans;
    }
};

class PTest3298 : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3298, Test1) {
    Solution s;
    auto actual = s.validSubstringCount("bcca", "abc");
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3298, Test2) {
    Solution s;
    auto actual = s.validSubstringCount("abcabc", "abc");
    decltype(actual) expect = 10;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3298, Test3) {
    Solution s;
    auto actual = s.validSubstringCount("abcabc", "aaabc");
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


