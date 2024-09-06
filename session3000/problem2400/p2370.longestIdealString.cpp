#include <gtest/gtest.h>

using namespace std;


namespace {

class Solution {
public:
    int longestIdealString(string s, int k)
    {
        int results[26] = { 0 };
        for (auto c : s) {
            int i = c - 'a';
            auto left = max(0, i - k);
            auto right = min(26, i + k + 1);
            results[i] = *max_element(results + left, results + right) + 1;
        }
        return *max_element(results, results + 26);
    }
};

class P2370Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2370Test, Test1)
{
    Solution s;
    auto actual = s.longestIdealString("acfgbd", 2);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}

}

