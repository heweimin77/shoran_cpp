#include <gtest/gtest.h>
#include <cmath>

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
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto getHeight = [&](long long y) {
            long long height = 0;
            for (long long w : workerTimes)
                height += (long long)(sqrt(y * 2 / w + 0.25) - 0.5);
            return height;
        };

        long long low = 0, high =  (long long)workerTimes[0] * mountainHeight * (1 + mountainHeight) / 2;
        while (low < high) {
            auto mid = (low + high) / 2;
            if (getHeight(mid) < mountainHeight) low = mid + 1;
            else high = mid;
        }
        return high;
    }
};

class PTest3296 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3296, Test1) {
    Solution s;
    int mountainHeight = 4;
    vector<int> workerTimes = {2,1,1};
    auto actual = s.minNumberOfSeconds(mountainHeight, workerTimes);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3296, Test2) {
    Solution s;
    int mountainHeight = 10;
    vector<int> workerTimes = {3,2,2,4};
    auto actual = s.minNumberOfSeconds(mountainHeight, workerTimes);
    decltype(actual) expect = 12;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3296, Test3) {
    Solution s;
    int mountainHeight = 5;
    vector<int> workerTimes = {1};
    auto actual = s.minNumberOfSeconds(mountainHeight, workerTimes);
    decltype(actual) expect = 15;
    EXPECT_EQ(expect, actual);
}
}


