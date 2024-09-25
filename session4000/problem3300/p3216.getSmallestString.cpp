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
    string getSmallestString(string s) {
        for (int i = 0; i < s.size()-1; ++i) {
            int diff = s[i] - s[i+1];
            if (diff > 0 && (diff & 1) == 0) {
                swap(s[i], s[i+1]);
                break;
            }
        }
        return s;
    }
};

class PTest3216 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3216, Test1) {
    Solution s;
    auto actual = s.getSmallestString("45320");
    decltype(actual) expect = "43520";
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3216, Test2) {
    Solution s;
    auto actual = s.getSmallestString("001");
    decltype(actual) expect = "001";
    EXPECT_EQ(expect, actual);
}
}


