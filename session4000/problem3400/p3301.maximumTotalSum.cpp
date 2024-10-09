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
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), std::greater<int>());
        long long ans = 0, r = INT_MAX;
        for (long long h : maximumHeight) {
            r = min(r - 1, h);
            if (r <= 0) return -1;
            ans += r;
        }
        return ans;
    }
};

class PTest3301 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3301, Test1) {
    Solution s;
    vector<int> maximumHeight = {2,3,4,3};
    auto actual = s.maximumTotalSum(maximumHeight);
    decltype(actual) expect = 10;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3301, Test2) {
    Solution s;
    vector<int> maximumHeight = {15,10};
    auto actual = s.maximumTotalSum(maximumHeight);
    decltype(actual) expect = 25;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3301, Test3) {
    Solution s;
    vector<int> maximumHeight = {2,2,1};
    auto actual = s.maximumTotalSum(maximumHeight);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
}


