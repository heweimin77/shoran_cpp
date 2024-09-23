#include <gtest/gtest.h>
#include <stack>

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
    bool isValid(string s) {
        stack<char> ss;
        for (char x : s) {
            if (x == '(') {
                ss.push(')');
            } else if (x == '[') {
                ss.push(']');
            } else if (x == '{') {
                ss.push('}');
            } else {
                if (ss.empty()) return false;
                if (ss.top() != x) return false;
                ss.pop();
            }
        }
        return ss.empty();
    }
};

class P020Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P020Test, Test1)
{
    Solution s;
    auto actual = s.isValid("()");
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(P020Test, Test2)
{
    Solution s;
    auto actual = s.isValid("()[]{}");
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
TEST_F(P020Test, Test3)
{
    Solution s;
    auto actual = s.isValid("(]");
    decltype(actual) expect = false;
    EXPECT_EQ(expect, actual);
}
TEST_F(P020Test, Test4)
{
    Solution s;
    auto actual = s.isValid("([])");
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
}


