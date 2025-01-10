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
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        string ans = "";
        int len = word.size() - numFriends + 1;
        for (int i = 0; i < word.size(); ++i) {
            string r = word.substr(i, min((int)word.size()-i, len));
            ans = max(ans, r);
        }
        return ans;
    }
};

class PTest3403 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3403, Test1) {
    Solution s;
    string word = "dbca";
    int numFriends = 2;
    auto actual = s.answerString(word, numFriends);
    decltype(actual) expect = "dbc";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3403, Test2) {
    Solution s;
    string word = "gggg";
    int numFriends = 4;
    auto actual = s.answerString(word, numFriends);
    decltype(actual) expect = "g";
    EXPECT_EQ(expect, actual);
}
}


