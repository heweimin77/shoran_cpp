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
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> dmaps = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> answers;
        int n = digits.size();
        if (n == 0) {
            return {};
        }
        string r(n, 'a');
        function<void(int)> traverse = [&](int i) {
            if (i == n) {
                answers.push_back(r);
                return ;
            }
            for (auto x : dmaps[digits[i]]) {
                r[i] = x;
                traverse(i + 1);
            }
        };
        traverse(0);
        return answers;
    }
};

class P017Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P017Test, Test1)
{
    Solution s;
    auto actual = s.letterCombinations("23");
    decltype(actual) expect = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
    EXPECT_EQ(expect, actual);
}
TEST_F(P017Test, Test2)
{
    Solution s;
    auto actual = s.letterCombinations("");
    decltype(actual) expect = {};
    EXPECT_EQ(expect, actual);
}
TEST_F(P017Test, Test3)
{
    Solution s;
    auto actual = s.letterCombinations("2");
    decltype(actual) expect = {"a","b","c"};
    EXPECT_EQ(expect, actual);
}
}


