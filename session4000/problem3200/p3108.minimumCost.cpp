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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> indexes(n, -1);
        vector<pair<int, unordered_set<int>>> nodes;
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (indexes[u] == -1 && indexes[v] == -1) {
                indexes[u] = indexes[v] = nodes.size();
                nodes.emplace_back(w, unordered_set<int>({u, v}));
            } else if (indexes[u] != -1 && indexes[v] != -1) {
                nodes[indexes[u]].first &= w;
                if (indexes[u] == indexes[v]) continue;
                nodes[indexes[u]].first &= nodes[indexes[v]].first;
                for (auto x : nodes[indexes[v]].second) {
                    indexes[x] = indexes[u];
                    nodes[indexes[u]].second.insert(x);
                }
            } else if (indexes[u] != -1) {
                indexes[v] = indexes[u];
                nodes[indexes[u]].first &= w;
                nodes[indexes[u]].second.insert(v);
            } else {
                indexes[u] = indexes[v];
                nodes[indexes[v]].first &= w;
                nodes[indexes[v]].second.insert(u);
            }
        }
        vector<int> answers;
        for (auto &q : query) {
            if (indexes[q[0]] != indexes[q[1]] || indexes[q[0]] == -1) {
                answers.push_back(-1);
            } else {
                answers.push_back(nodes[indexes[q[0]]].first);
            }
        }
        return answers;
    }
};

class PTest3108 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3108, Test1) {
    Solution s;
    int n = 5;
    vector<vector<int>> edges = {{0,1,7},{1,3,7},{1,2,1}};
    vector<vector<int>> query = {{0,3},{3,4}};
    auto actual = s.minimumCost(n, edges, query);
    decltype(actual) expect = {1, -1};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3108, Test2) {
    Solution s;
    int n = 3;
    vector<vector<int>> edges = {{0,2,7},{0,1,15},{1,2,6},{1,2,1}};
    vector<vector<int>> query = {{1,2}};
    auto actual = s.minimumCost(n, edges, query);
    decltype(actual) expect = {0};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3108, Test3) {
    Solution s;
    int n = 7;
    vector<vector<int>> edges = {{6,0,0},{4,1,1},{5,4,0},{1,2,2},{3,0,2},{2,0,1},{0,4,2},{1,6,1},{1,3,1},{3,0,1}};
    vector<vector<int>> query = {{5,4},{0,5},{4,0},{1,5},{1,3},{1,5}};
    auto actual = s.minimumCost(n, edges, query);
    decltype(actual) expect = {0,0,0,0,0,0};
    EXPECT_EQ(expect, actual);
}
}


