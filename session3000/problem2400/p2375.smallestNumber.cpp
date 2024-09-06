#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    string smallestNumber(string pattern)
    {
        int icnt = 1, dcnt = 0;
        int i = 0;
        char x = '1';
        string result;
        while (i < pattern.size()) {
            while (i < pattern.size() && pattern[i] == 'I') ++icnt,++i;
            while (i < pattern.size() && pattern[i] == 'D') ++dcnt,++i;
            for (int j = 1; j < icnt; ++j) result += x++;
            x += dcnt;
            for (int j = 0; j <= dcnt; ++j) result += x--;
            x += dcnt + 2;
            icnt = dcnt = 0;
        }
        return result;
    }
};

class P2375Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2375Test, Test1)
{
    Solution s;
    auto actual = s.smallestNumber("IIIDIDDD");
    decltype(actual) expect = "123549876";
    EXPECT_EQ(expect, actual);
}

}

