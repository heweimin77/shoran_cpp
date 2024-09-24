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
    vector<string> generateParenthesis(int n) {
        vector<string> answers;
        string r;
        function<void(int,int)> traverse = [&](int left, int right) {
            if (right == 0) {
                answers.push_back(r);
                return;
            }
            if (left > 0) {
                r.push_back('(');
                traverse(left-1, right);
                r.pop_back();
            }
            if (right > left) {
                r.push_back(')');
                traverse(left, right-1);
                r.pop_back();
            }
        };
        traverse(n, n);
        return answers;
    }
};

class P022Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P022Test, Test1) {
    Solution s;
    auto actual = s.generateParenthesis(3);
    decltype(actual) expect = {"((()))","(()())","(())()","()(())","()()()"};
    EXPECT_EQ(expect, actual);
}
TEST_F(P022Test, Test2) {
    Solution s;
    auto actual = s.generateParenthesis(1);
    decltype(actual) expect = {"()"};
    EXPECT_EQ(expect, actual);
}

}


