#include <gtest/gtest.h>
#include "DictTree.h"

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
    int minValidStrings(vector<string>& words, string target) {
        DictTree dt;
        for (auto &w : words) dt.add(w, 0);
        int n = target.size();
        vector<int> answers(n+1, INT_MAX);
        answers[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (answers[i] == INT_MAX) continue;
            int r = dt.match_len(target.begin()+i, target.end());
            for (int j = i + 1; j <= i + r; ++j) {
                answers[j] = min(answers[j], answers[i] + 1);
            }
        }
        return answers[n] == INT_MAX ? -1 : answers[n];
    }
};

class PTest3291 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3291, Test1) {
    Solution s;
    vector<string> words = {"abc","aaaaa","bcdef"};
    string target = "aabcdabc";
    auto actual = s.minValidStrings(words, target);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3291, Test2) {
    Solution s;
    vector<string> words = {"abababab","ab"};
    string target = "ababaababa";
    auto actual = s.minValidStrings(words, target);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3291, Test3) {
    Solution s;
    vector<string> words = {"abcdef"};
    string target = "xyz";
    auto actual = s.minValidStrings(words, target);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
}


