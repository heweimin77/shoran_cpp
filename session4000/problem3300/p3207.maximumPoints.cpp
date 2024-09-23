#include <gtest/gtest.h>
#include <numeric>

using namespace std;

namespace {
class AutoRun {
public:
    AutoRun() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

} autorun;
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int base = *min_element(enemyEnergies.begin(), enemyEnergies.end());
        if (base > currentEnergy) return 0;
        return accumulate(enemyEnergies.begin(), enemyEnergies.end(), (long long )currentEnergy - base) / base;
    }
};

class P3207Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3207Test, Test1)
{
    Solution s;
    vector<int> enemyEnergies = {3,2,2};
    int currentEnergy = 2;
    auto actual = s.maximumPoints(enemyEnergies, currentEnergy);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3207Test, Test2)
{
    Solution s;
    vector<int> enemyEnergies = {2};
    int currentEnergy = 10;
    auto actual = s.maximumPoints(enemyEnergies, currentEnergy);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}

}


