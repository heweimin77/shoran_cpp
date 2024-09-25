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
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), std::greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), std::greater<int>());
        long long i = 0, j = 0, answer = 0;
        while (i < m - 1 && j < n - 1) {
            if (horizontalCut[i] < verticalCut[j]) {
                answer += verticalCut[j++] * (i + 1);
            } else {
                answer += horizontalCut[i++] * (j + 1);
            }
        }
        if (i == m - 1) {
            for (; j < n - 1; ++j) {
                answer += verticalCut[j] * m;
            }
        }
        if (j == n - 1) {
            for (; i < m - 1; ++i) {
                answer += horizontalCut[i] * n;
            }
        }
        return answer;
    }
};

class PTest3219 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3219, Test1) {
    Solution s;
    int m = 3, n = 2;
    vector<int> horizontalCut = {1,3};
    vector<int> verticalCut = {5};
    auto actual = s.minimumCost(m, n, horizontalCut, verticalCut);
    decltype(actual) expect = 13;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3219, Test2) {
    Solution s;
    int m = 2, n = 2;
    vector<int> horizontalCut = {7};
    vector<int> verticalCut = {4};
    auto actual = s.minimumCost(m, n, horizontalCut, verticalCut);
    decltype(actual) expect = 15;
    EXPECT_EQ(expect, actual);
}
}


