#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int low = 0, high = start.back() - start[0] + d + 1;
        auto ok = [&](int x) {
            long long limit = start[0];
            for (long long v : start) {
                if (v + d < limit) return false;
                limit = max(limit, v) + x;
            }
            return true;
        };
        while (low < high) {
            auto mid = (low + high) / 2;
            if (ok(mid)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low - 1;
    }
};

class P3181Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3181Test, Test1)
{
    Solution s;
    vector<int> start = {6, 0, 3};
    int d = 2;
    auto actual = s.maxPossibleScore(start, d);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3181Test, Test2)
{
    Solution s;
    vector<int> start = {2,6,13,13};
    int d = 5;
    auto actual = s.maxPossibleScore(start, d);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}

}


