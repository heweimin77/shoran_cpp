#include <gtest/gtest.h>

using namespace std;

namespace {
static auto autorun = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        pair<long, long> ans = {0, 0};
        for (int i = 0; i < energyDrinkA.size(); ++i) {
            ans = make_pair(max(ans.first + energyDrinkA[i], ans.second), max(ans.second + energyDrinkB[i], ans.first));
        }
        return max(ans.first, ans.second);
    }
};

class PTest3259 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3259, Test1) {
    Solution s;
    vector<int> energyDrinkA = {1,3,1};
    vector<int> energyDrinkB = {3,1,1};
    auto actual = s.maxEnergyBoost(energyDrinkA, energyDrinkB);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3259, Test2) {
    Solution s;
    vector<int> energyDrinkA = {4,1,1};
    vector<int> energyDrinkB = {1,1,3};
    auto actual = s.maxEnergyBoost(energyDrinkA, energyDrinkB);
    decltype(actual) expect = 7;
    EXPECT_EQ(expect, actual);
}
}


