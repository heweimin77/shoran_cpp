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
    string longestCommonPrefix(vector<string>& strs) {
        int match = strs[0].size();
        string &s = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            for (int j = 0; j < match; ++j) {
                if (s[j] != strs[i][j]) {
                    match = j;
                    break;
                }
            }
        }
        return s.substr(0, match);
    }
    string longestCommonPrefix2(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

class P014Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P014Test, Test1)
{
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    auto actual = s.longestCommonPrefix(strs);
    decltype(actual) expect = "fl";
    EXPECT_EQ(expect, actual);
}
TEST_F(P014Test, Test2)
{
    Solution s;
    vector<string> strs = {"dog","racecar","car"};
    auto actual = s.longestCommonPrefix(strs);
    decltype(actual) expect = "";
    EXPECT_EQ(expect, actual);
}
}


