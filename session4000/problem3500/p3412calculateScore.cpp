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
    long long calculateScore(string s) {
        long long ans = 0;
        vector<int> indexes[26];
        for (int i = 0; i < s.size(); ++i) {
            auto x = s[i];
            if (indexes['z' - x].empty()) {
                indexes[x - 'a'].push_back(i);
            } else {
                ans += i - indexes['z' - x].back();
                indexes['z' - x].pop_back();
            }
        }
        return ans;
    }
};

class PTest3412 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3412, Test1) {
    Solution s;
    auto actual = s.calculateScore("aczzx");
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3412, Test2) {
    Solution s;
    auto actual = s.calculateScore("abcdef");
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


