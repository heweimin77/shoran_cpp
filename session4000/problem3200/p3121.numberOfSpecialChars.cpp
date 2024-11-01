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
    int numberOfSpecialChars(string word) {
        int counts[26] = {0};
        int lowers[4] = {1, 1, 3, 3};
        int caps[4] = {3, 2, 2, 3};
        for (auto x : word) {
            if ('a' <= x && x <= 'z') {
                counts[x - 'a'] = lowers[counts[x - 'a']];
            } else {
                counts[x - 'A'] = caps[counts[x - 'A']];
            }
        }
        return count(counts, counts + 26, 2);
    }
};

class PTest3121 : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3121, Test1) {
    Solution s;
    auto actual = s.numberOfSpecialChars("aaAbcBC");
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3121, Test2) {
    Solution s;
    auto actual = s.numberOfSpecialChars("abc");
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3121, Test3) {
    Solution s;
    auto actual = s.numberOfSpecialChars("AbBCab");
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


