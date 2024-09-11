#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> results;
        for (auto &q : queries) {
            string s1 = getBin(q[0]);
            string s2 = getBin(q[1]);
            results.push_back(getResult(s1, s2));
        }
        return results;
    }
    string getBin(int x)
    {
        string s;
        while (x > 0) {
            s.push_back('0' + (x & 1));
            x >>= 1;
        }
        return s;
    }
    int getResult(const string &s1, const string &s2)
    {
        int cnt = 0;
        for (auto i1 = s1.rbegin(), i2 = s2.rbegin(); i1 != s1.rend() && i2 != s2.rend(); ++i1, ++i2) {
            if (*i1 != *i2) break;
            ++cnt;
        }
        return s1.size() + s2.size() - cnt - cnt + 1;
    }
};

class P2509Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2509Test, TestMain)
{
    vector<vector<int>> queries = { {5,3}, {4,7}, {2,3} };
    Solution s;
    auto actual = s.cycleLengthQueries(3, queries);
    decltype(actual) expect = { 4,5,3 };
    EXPECT_EQ(expect, actual);
}
}

