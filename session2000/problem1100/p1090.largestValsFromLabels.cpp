﻿#include <gtest/gtest.h>
#include <queue>
#include <unordered_map>

using namespace std;

namespace {

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < values.size(); ++i) {
            q.push({ values[i], labels[i] });
        }

        int result = 0;
        unordered_map<int, int> counts;
        while (!q.empty() && numWanted > 0) {
            auto now = q.top();
            q.pop();
            auto& cnt = counts[now.second];
            if (cnt >= useLimit) continue;
            result += now.first;
            ++cnt;
            --numWanted;
        }
        return result;
    }
};

class P1090Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P1090Test, TestMain)
{
    vector<int> values = { 5,4,3,2,1 };
    vector<int> labels = { 1,1,2,2,3 };
    Solution s;
    auto actual = s.largestValsFromLabels(values, labels, 3, 1);
    decltype(actual) expect = 9;
    EXPECT_EQ(expect, actual);
}

}
