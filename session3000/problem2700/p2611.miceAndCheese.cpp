﻿#include <gtest/gtest.h>
#include <queue>

using namespace std;


namespace {

class Solution {
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        int n = reward1.size();
        if (k > (n >> 1)) {
            k = n - k;
            reward1.swap(reward2);
        }
        int result = 0;
        priority_queue<int> q;
        for (int i = 0; i < n; ++i) {
            result += reward2[i];
            q.push(reward1[i] - reward2[i]);
        }
        for (int i = 0; i < k; ++i) {
            result += q.top();
            q.pop();
        }
        return result;
    }
};

class P2611Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2611Test, Test1)
{
    vector<int> reward1 = { 1,1,3,4 };
    vector<int> reward2 = { 4,4,1,1 };
    Solution s;
    auto actual = s.miceAndCheese(reward1, reward2, 2);
    decltype(actual) expect = 15;
    EXPECT_EQ(expect, actual);
}

}

