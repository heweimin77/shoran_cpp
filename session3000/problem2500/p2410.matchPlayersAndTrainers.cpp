#include <gtest/gtest.h>
#include <climits>

using namespace std;

namespace {

class Solution {
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        trainers.push_back(INT_MAX);
        int result = 0;
        for (int i = 0, j = 0; i < players.size(); ++i,++j) {
            while (trainers[j] < players[i]) ++j;
            if (trainers[j] == INT_MAX) break;
            ++result;
        }
        return result;
    }
};

class P2410Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2410Test, Test1)
{
    vector<int> players = { 4,7,9 };
    vector<int> trainers = { 8,2,5,8 };
    Solution s;
    auto actual = s.matchPlayersAndTrainers(players, trainers);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}

}
