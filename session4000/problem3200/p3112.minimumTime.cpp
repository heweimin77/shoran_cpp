#include <gtest/gtest.h>
#include <queue>

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
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adjs(n);
        for (auto &e : edges) {
            adjs[e[0]].push_back({e[1], e[2]});
            adjs[e[1]].push_back({e[0], e[2]});
        }
        vector<int> answers(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qs;
        qs.push({0, 0});
        answers[0] = 0;
        while (!qs.empty()) {
            auto now = qs.top();
            qs.pop();
            if (answers[now.second] < now.first) continue;
            for (auto next : adjs[now.second]) {
                int np = next.first, nv = now.first + next.second;
                if (nv < disappear[np] && nv < answers[np]) {
                    answers[np] = nv;
                    qs.push({nv, np});
                }
            }
        }
        for (int i = 0; i < answers.size(); ++i) if (answers[i] == INT_MAX) answers[i] = -1;
        return answers;
    }
};

class PTest3112 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3112, Test1) {
    Solution s;
    int n = 3;
    vector<vector<int>> edges = {{0,1,2},{1,2,1},{0,2,4}};
    vector<int> disappear = {1,1,5};
    auto actual = s.minimumTime(n, edges, disappear);
    decltype(actual) expect = {0,-1,4};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3112, Test2) {
    Solution s;
    int n = 3;
    vector<vector<int>> edges = {{0,1,2},{1,2,1},{0,2,4}};
    vector<int> disappear = {1,3,5};
    auto actual = s.minimumTime(n, edges, disappear);
    decltype(actual) expect = {0,2,3};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3112, Test3) {
    Solution s;
    int n = 2;
    vector<vector<int>> edges = {{0,1,1}};
    vector<int> disappear = {1,1};
    auto actual = s.minimumTime(n, edges, disappear);
    decltype(actual) expect = {0,-1};
    EXPECT_EQ(expect, actual);
}
}


