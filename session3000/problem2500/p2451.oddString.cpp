﻿#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    string oddString(vector<string> &words)
    {
        if (isSame(words[0], words[1])) {
            for (int i = 2; i < words.size(); ++i) {
                if (!isSame(words[0], words[i])) {
                    return words[i];
                }
            }
        } else {
            if (isSame(words[0], words[2])) {
                return words[1];
            } else {
                return words[0];
            }
        }
        return "";
    }
    bool isSame(const string &w1, const string &w2)
    {
        for (int i = 1; i < w1.size(); ++i) {
            if (w1[i] - w1[i - 1] != w2[i] - w2[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

class P2451Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2451Test, Test1)
{
    vector<string> words = { "adc","wzy","abc" };
    Solution s;
    auto actual = s.oddString(words);
    decltype(actual) expect = "abc";
    EXPECT_EQ(expect, actual);
}

}
