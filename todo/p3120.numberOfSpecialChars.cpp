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
        bool visited[256] = {false};
        for (auto x : word) visited[x] = true;
        int ans = 0;
        for (char x = 'a'; x <= 'z'; ++x) {
            if (visited[x] && visited[x - 'a' + 'A']) ++ans;
        }
        return ans;
    }
};

class PTest3120 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3120, Test1) {
    Solution s;
    auto actual = s.numberOfSpecialChars("aaAbcBC");
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3120, Test2) {
    Solution s;
    auto actual = s.numberOfSpecialChars("abc");
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3120, Test3) {
    Solution s;
    auto actual = s.numberOfSpecialChars("abBCab");
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}


