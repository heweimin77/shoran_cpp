#include <gtest/gtest.h>
#include <unordered_set>

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
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> dict;
        for (auto &w : bannedWords) dict.insert(w);
        int count = 0;
        for (auto &m : message) {
            if (dict.contains(m)) {
                if (++count == 2) return true;
            }
        }
        return false;
    }
};

class PTest3295 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3295, Test1) {
    Solution s;
    vector<string> message = {"hello","world","leetcode"};
    vector<string> bannedWords = {"world","hello"};
    auto actual = s.reportSpam(message, bannedWords);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3295, Test2) {
    Solution s;
    vector<string> message = {"hello","programming","fun"};
    vector<string> bannedWords = {"world","programming","leetcode"};
    auto actual = s.reportSpam(message, bannedWords);
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
}


