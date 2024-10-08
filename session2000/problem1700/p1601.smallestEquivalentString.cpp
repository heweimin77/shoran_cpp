﻿#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int indexes[26] = { 0 };
        for (int i = 0; i < 26; ++i) indexes[i] = i;
        for (int i = 0; i < s1.size(); ++i) {
            int i1 = indexes[s1[i] - 'a'];
            int i2 = indexes[s2[i] - 'a'];
            if (i1 == i2) continue;
            if (i1 > i2) swap(i1, i2);
            for (int j = i2; j < 26; ++j) {
                if (indexes[j] == i2) {
                    indexes[j] = i1;
                }
            }
        }

        for (auto &ch : baseStr) {
            ch = 'a' + indexes[ch - 'a'];
        }

        return baseStr;
    }
};

class P1601Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P1601Test, Test1)
{
    Solution s;
    auto actual = s.smallestEquivalentString("parker", "morris", "parser");
    decltype(actual) expect = "makkek";
    EXPECT_EQ(expect, actual);
}

}
