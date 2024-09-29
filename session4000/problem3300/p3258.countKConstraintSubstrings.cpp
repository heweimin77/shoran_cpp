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
    int countKConstraintSubstrings(const string &s, int k) {
        int counts[2] = {0};
        int j = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++counts[s[i]-'0'];
            while (counts[0] > k && counts[1] > k) {
                --counts[s[j++]-'0'];
            }
            ans += i - j + 1;
        }
        return ans;
    }
    int countKConstraintSubstrings2(string s, int k) {
        int counts[2] = {0};
        int j = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (j < s.size() && (counts[0] <= k || counts[1] <= k)) {
                ++counts[s[j++]-'0'];
            }
            if (counts[0] <= k || counts[1] <= k) {
                ans += j - i;
            } else {
                ans += j - i - 1;
            }
            --counts[s[i]-'0'];
        }
        return ans;
    }
};

class PTest3258 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3258, Test1) {
    Solution s;
    auto actual = s.countKConstraintSubstrings("10101", 1);
    decltype(actual) expect = 12;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3258, Test2) {
    Solution s;
    auto actual = s.countKConstraintSubstrings("1010101", 2);
    decltype(actual) expect = 25;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3258, Test3) {
    Solution s;
    auto actual = s.countKConstraintSubstrings("11111", 1);
    decltype(actual) expect = 15;
    EXPECT_EQ(expect, actual);
}
}


