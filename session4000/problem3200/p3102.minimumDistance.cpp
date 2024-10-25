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
    int minimumDistance(vector<vector<int>>& points) {
        auto get_max = [&](int skip) {
            vector<pair<int,int>> x1, x2;
            for (int i = 0; i < points.size(); ++i) {
                if (i == skip) continue;
                auto &p = points[i];
                x1.push_back({p[0]+p[1], i});
                x2.push_back({p[0]-p[1], i});
            }
            std::sort(x1.begin(), x1.end());
            std::sort(x2.begin(), x2.end());
            int r1 = x1.back().first - x1[0].first;
            int r2 = x2.back().first - x2[0].first;
            return r1 >= r2 ? vector<int> {r1, x1.back().second, x1[0].second} : vector<int> {r2, x2.back().second, x2[0].second};
        };
        auto rs = get_max(-1);
        auto r1 = get_max(rs[1]);
        auto r2 = get_max(rs[2]);
        return min(r1[0], r2[0]);
    }
};

class PTest3102 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3102, Test1) {
    Solution s;
    vector<vector<int>> points = {{3,10},{5,15},{10,2},{4,4}};
    auto actual = s.minimumDistance(points);
    decltype(actual) expect = 12;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3102, Test2) {
    Solution s;
    vector<vector<int>> points = {{1,1},{1,1},{1,1}};
    auto actual = s.minimumDistance(points);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


