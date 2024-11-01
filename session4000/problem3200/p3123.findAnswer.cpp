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
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adjs(n);
        for (auto &e: edges) {
            adjs[e[0]].emplace_back(e[1], e[2]);
            adjs[e[1]].emplace_back(e[0], e[2]);
        }
        auto get_distance = [&](int start) {
            vector<int> disances(n, INT_MAX/3);
            disances[start] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
            q.emplace(0, start);
            while (!q.empty()) {
                auto [v, p] = q.top();
                q.pop();
                if (v != disances[p]) continue;
                for (auto [np, nv]: adjs[p]) {
                    nv += v;
                    if (nv < disances[np]) {
                        disances[np] = nv;
                        q.emplace(nv, np);
                    }
                }
            }
            return disances;
        };

        auto distances0 = get_distance(0);
        auto distances1 = get_distance(n-1);
        int target = distances0[n-1];
        vector<bool> answers(edges.size());
        for (int i = 0; i < edges.size(); ++i) {
            int e0 = edges[i][0], e1 = edges[i][1], w = edges[i][2];
            if (distances0[e0] + distances1[e1] == target - w || distances0[e1] + distances1[e0] == target - w) {
                answers[i] = true;
            }
        }
        return answers;
    }
};

class PTest3123 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3123, Test1) {
    Solution s;
    int n = 6;
    vector<vector<int>> edges = {{0,1,4},{0,2,1},{1,3,2},{1,4,3},{1,5,1},{2,3,1},{3,5,3},{4,5,2}};
    auto actual = s.findAnswer(n, edges);
    decltype(actual) expect = {true,true,true,false,true,true,true,false};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3123, Test2) {
    Solution s;
    int n = 4;
    vector<vector<int>> edges = {{2,0,1},{0,1,1},{0,3,4},{3,2,2}};
    auto actual = s.findAnswer(n, edges);
    decltype(actual) expect = {true,false,false,true};
    EXPECT_EQ(expect, actual);
}
}


