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
    string getEncryptedString(const string &s, int k) {
        k %= s.size();
        return s.substr(k) + s.substr(0, k);
    }
};

class P3210Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3210Test, Test1)
{
    Solution s;
    auto actual = s.getEncryptedString("dart", 3);
    decltype(actual) expect = "tdar";
    EXPECT_EQ(expect, actual);
}
TEST_F(P3210Test, Test2)
{
    Solution s;
    auto actual = s.getEncryptedString("aaa", 1);
    decltype(actual) expect = "aaa";
    EXPECT_EQ(expect, actual);
}

}


