#include <gtest/gtest.h>
#include <unordered_set>

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
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        unordered_set<int> xs;
        for (auto &p : points) xs.insert(p[0]);
        vector<int> xxs(xs.begin(), xs.end());
        std::sort(xxs.begin(), xxs.end());
        int ans = 0, limit = INT_MIN;
        for (auto x : xxs) {
            if (x > limit) {
                ++ans;
                limit = x + w;
            }
        }
        return ans;
    }
};

class PTest3111 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3111, Test1) {
    Solution s;
    vector<vector<int>> points = {{2,1},{1,0},{1,4},{1,8},{3,5},{4,6}};
    int w = 1;
    auto actual = s.minRectanglesToCoverPoints(points, w);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3111, Test2) {
    Solution s;
    vector<vector<int>> points = {{0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6}};
    int w = 2;
    auto actual = s.minRectanglesToCoverPoints(points, w);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3111, Test3) {
    Solution s;
    vector<vector<int>> points = {{2,3},{1,2}};
    int w = 0;
    auto actual = s.minRectanglesToCoverPoints(points, w);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
}


