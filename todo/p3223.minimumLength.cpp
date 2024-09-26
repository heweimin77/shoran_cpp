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
    int minimumLength(string s) {
        int counts[26] = {0};
        for (auto x : s) {
            ++counts[x - 'a'];
        }
        int ans = 0;
        for (auto c : counts) {
            if (c == 0) continue;
            ans += 2 - (c & 1);
        }
        return ans;
    }
};

class PTest3223 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3223, Test1) {
    Solution s;
    auto actual = s.minimumLength("abaacbcbb");
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3223, Test2) {
    Solution s;
    auto actual = s.minimumLength("aa");
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}

}


