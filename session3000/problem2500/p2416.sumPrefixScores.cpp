﻿#include <gtest/gtest.h>
using namespace std;

namespace {

class Solution {
    struct Info {
        Info()
        {
            memset(nexts, 0, sizeof(nexts));
        }
        void add(const string &s)
        {
            Info *p = this;
            for (auto ch : s) {
                int i = ch - 'a';
                if (p->nexts[i] == nullptr) {
                    p->nexts[i] = new Info();
                }
                ++p->nexts[i]->count;
                p = p->nexts[i];
            }
        }
        int get(const string &s)
        {
            Info *p = this;
            int result = 0;
            for (auto ch : s) {
                p = p->nexts[ch - 'a'];
                result += p->count;
            }
            return result;
        }
        int count = 0;
        Info *nexts[26];
    };
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        Info root;
        for (auto &s : words) {
            root.add(s);
        }
        vector<int> results;
        for (auto &s : words) {
            results.push_back(root.get(s));
        }
        return results;
    }
};
class P2416Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2416Test, TestMain)
{
    vector<string> words = { "abc","ab","bc","b" };
    Solution s;
    auto actual = s.sumPrefixScores(words);
    decltype(actual) expect = { 5,4,3,2 };
    EXPECT_EQ(expect, actual);
}
}

