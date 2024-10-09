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
    char kthCharacter(int k) {
        vector<int> ans(1, 0);
        constexpr char limit = 'a' + 26;
        while (ans.size() < k) {
            int x = ans.size();
            for (int i = 0; i < x; ++i) {
                ans.push_back(ans[i] + 1);
            }
        }
        return 'a' + ans[k-1] % 26;
    }
};

class PTest3304 : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3304, Test1) {
    Solution s;
    auto actual = s.kthCharacter(5);
    decltype(actual) expect = 'b';
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3304, Test2) {
    Solution s;
    auto actual = s.kthCharacter(10);
    decltype(actual) expect = 'c';
    EXPECT_EQ(expect, actual);
}
}


