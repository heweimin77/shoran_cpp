#include <gtest/gtest.h>
#include <set>
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
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        vector<pair<int,int>> left, right;
        int kx = coordinates[k][0], ky = coordinates[k][1];
        for (auto &co: coordinates) {
            int x = co[0], y = co[1];
            if (x > kx && y > ky) left.push_back({x - kx, y - ky});
            else if (x < kx && y < ky) right.push_back({kx - x, ky - y});
        }

        auto count = [&](vector<pair<int,int>> &ns)->int {
            std::sort(ns.begin(), ns.end(), [](pair<int,int> &lhs, pair<int,int> &rhs) {
                if (lhs.first != rhs.first) return lhs.first < rhs.first;
                return lhs.second > rhs.second;
            });

            set<pair<int,int>> answers;
            for (auto [x,y]: ns) {
                auto it = answers.lower_bound({y, x});
                if (it != answers.begin()) {
                    auto jt = it;
                    --jt;
                    if (jt->first == y || jt->second == x) continue;
                }
                if (it != answers.end()) {
                    answers.erase(it);
                }
                answers.insert({y, x});
            }
            return answers.size();
        };
        return 1 + count(left) + count(right);
    }
};

class PTest3288 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3288, Test1) {
    Solution s;
    vector<vector<int>> coordinates = {{3,1},{2,2},{4,1},{0,0},{5,3}};
    int k = 1;
    auto actual = s.maxPathLength(coordinates, k);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3288, Test2) {
    Solution s;
    vector<vector<int>> coordinates = {{2,1},{7,0},{5,6}};
    int k = 2;
    auto actual = s.maxPathLength(coordinates, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3288, Test3) {
    Solution s;
    vector<vector<int>> coordinates = {{0,3},{8,5},{6,8}};
    int k = 0;
    auto actual = s.maxPathLength(coordinates, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
}


