#include <gtest/gtest.h>
#include <cmath>

using namespace std;

namespace {
class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long low = 0, high = (long long) ranks[0] * cars * cars;
        while (low + 1 < high) {
            long long mid = (low + high) / 2;
            long long crs = 0;
            for (auto r : ranks) {
                crs += sqrt((double)mid / r);
            }
            if (crs >= cars) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    }
};

class P2594Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2594Test, Test1)
{
    vector<int> ranks = { 4,2,3,1 };
    Solution s;
    auto actual = s.repairCars(ranks, 10);
    decltype(actual) expect = 16;
    EXPECT_EQ(expect, actual);
}

}

