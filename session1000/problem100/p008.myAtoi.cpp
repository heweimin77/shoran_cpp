#include "gtest/gtest.h"
#include <string>
#include <algorithm>

using namespace std;

namespace {

class Solution {
public:
    int myAtoi(string s) {
        auto limit = s.end();
        auto it = s.begin();
        while (it != limit && *it == ' ') ++it;
        if (it == limit) return 0;

        int flag = 1;
        if (*it == '-') {
            flag = -1;
            ++it;
        }
        else if (*it == '+') {
            ++it;
        }
        long long r = 0;
        while (it != limit && '0' <= *it && *it <= '9') {
            r *= 10;
            r += (*it++ - '0');
            if (r > INT32_MAX) {
                break;
            }
        }
        r *= flag;
        r = max(r, (long long)INT32_MIN);
        r = min(r, (long long)INT32_MAX);
        return (int)r;
    }
};

class P008Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};


TEST_F(P008Test, Test1)
{
    //vector<int> para = {1,3 };
    Solution s;
    auto actual = s.myAtoi("42");
    decltype(actual) expect = 42;
    EXPECT_EQ(expect, actual);
}
TEST_F(P008Test, Test2)
{
    Solution s;
    auto actual = s.myAtoi("   -42");
    decltype(actual) expect = -42;
    EXPECT_EQ(expect, actual);
}
TEST_F(P008Test, Test3)
{
    Solution s;
    auto actual = s.myAtoi("4193 with words");
    decltype(actual) expect = 4193;
    EXPECT_EQ(expect, actual);
}
TEST_F(P008Test, Test4)
{
    Solution s;
    auto actual = s.myAtoi("words and 987");
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(P008Test, Test5)
{
    Solution s;
    auto actual = s.myAtoi("-91283472332");
    decltype(actual) expect = -2147483648;
    EXPECT_EQ(expect, actual);
}

}


