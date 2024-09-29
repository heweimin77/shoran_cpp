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
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long r1 = LONG_LONG_MIN/4, r2 = LONG_LONG_MIN/4, r3 = LONG_LONG_MIN/4, r4 = LONG_LONG_MIN/4;
        for (long long x : b) {
            r4 = max(r4, r3 + x * a[3]);
            r3 = max(r3, r2 + x * a[2]);
            r2 = max(r2, r1 + x * a[1]);
            r1 = max(r1, x * a[0]);
        }
        return r4;
    }
};

class PTest3290 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3290, Test1) {
    Solution s;
    vector<int> a = {3,2,5,6};
    vector<int> b = {2,-6,4,-5,-3,2,-7};
    auto actual = s.maxScore(a, b);
    decltype(actual) expect = 26;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3290, Test2) {
    Solution s;
    vector<int> a = {-1,4,5,-2};
    vector<int> b = {-5,-1,-3,-2,-4};
    auto actual = s.maxScore(a, b);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
}


