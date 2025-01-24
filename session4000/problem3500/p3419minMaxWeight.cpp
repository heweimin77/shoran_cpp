#include <gtest/gtest.h>
#include <queue>
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
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> adjs(n);
        for (auto &e : edges) {
            adjs[e[1]].push_back({e[2], e[0]});
        }
        int answer = 0;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, 0});
        while (visited.size() < n && !q.empty()) {
            auto x = q.top();
            q.pop();
            if (visited.contains(x.second)) continue;
            answer = max(answer, x.first);
            visited.insert(x.second);
            for (auto &next : adjs[x.second]) {
                if (visited.contains(next.second)) continue;
                q.push(next);
            }
        }
        return visited.size() == n ? answer : -1;
    }
};

class PTest3419 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3419, Test1) {
    Solution s;
    int n = 5;
    vector<vector<int>> edges = {{1,0,1},{2,0,2},{3,0,1},{4,3,1},{2,1,1}};
    int threshold = 2;
    auto actual = s.minMaxWeight(n, edges, threshold);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3419, Test2) {
    Solution s;
    int n = 5;
    vector<vector<int>> edges = {{0,1,1},{0,2,2},{0,3,1},{0,4,1},{1,2,1},{1,4,1}};
    int threshold = 1;
    auto actual = s.minMaxWeight(n, edges, threshold);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3419, Test3) {
    Solution s;
    int n = 5;
    vector<vector<int>> edges = {{1,2,1},{1,3,3},{1,4,5},{2,3,2},{3,4,2},{4,0,1}};
    int threshold = 1;
    auto actual = s.minMaxWeight(n, edges, threshold);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3419, Test4) {
    Solution s;
    int n = 5;
    vector<vector<int>> edges = {{1,2,1},{1,3,3},{1,4,5},{2,3,2},{4,0,1}};
    int threshold = 1;
    auto actual = s.minMaxWeight(n, edges, threshold);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
}


