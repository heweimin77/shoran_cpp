﻿#include <gtest/gtest.h>
#include <numeric>

using namespace std;

namespace {

class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int mindex = 0, gindex = 0, pindex = 0;
        int result = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            string s = garbage[i];
            result += s.size();
            if (s.find('M') != string::npos) {
                mindex = i;
            }
            if (s.find('G') != string::npos) {
                gindex = i;
            }
            if (s.find('P') != string::npos) {
                pindex = i;
            }
        }
        result = accumulate(travel.begin(), travel.begin() + mindex, result);
        result = accumulate(travel.begin(), travel.begin() + gindex, result);
        result = accumulate(travel.begin(), travel.begin() + pindex, result);
        return result;
    }
};

class P2391Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2391Test, Test1)
{
    vector<string> garbage = { "G","P","GP","GG" };
    vector<int> travel = { 2, 4, 3 };
    Solution s;
    auto actual = s.garbageCollection(garbage, travel);
    decltype(actual) expect = 21;
    EXPECT_EQ(expect, actual);
}

}
