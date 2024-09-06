#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> results(n, vector<int>(d, -1));
        results[0][0] = jobDifficulty[0];
        for (int i = 1; i < n; ++i) {
            int job = jobDifficulty[i];
            auto &now = results[i];
            auto& last = results[i - 1];
            now[0] = max(job, last[0]);
            for (int j = 1; j < d; ++j) {
                if (last[j - 1] == -1) continue;
                int r = last[j - 1] + job;
                int njob = job;
                for (int k = i - 1; k > 0; --k) {
                    if (results[k - 1][j - 1] == -1) break;
                    njob = max(njob, jobDifficulty[k]);
                    r = min(r, results[k-1][j-1] + njob);
                }
                now[j] = r;
            }
        }
        return results.back().back();
    }
};

class P1335Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P1335Test, TestMain)
{
    vector<int> jobDifficulty = { 6,5,4,3,2,1 };
    Solution s;
    auto actual = s.minDifficulty(jobDifficulty, 2);
    decltype(actual) expect = 7;
    EXPECT_EQ(expect, actual);
}
}

