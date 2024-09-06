#include <gtest/gtest.h>
#include <queue>

using namespace std;

namespace {

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<vector<int>> adjs(n);
        for (auto &e : edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }
        vector<int> visited(n);
        for (auto r : restricted) {
            visited[r] = true;
        }
        queue<int> q;
        q.push(0);
        int result = 0;
        while (!q.empty()) {
            ++result;
            int x = q.front();
            visited[x] = true;
            q.pop();
            for (auto next : adjs[x]) {
                if (visited[next]) continue;
                q.push(next);
            }
        }
        return result;
    }
};

class P2368Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2368Test, Test1)
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6}};
    vector<int> restricted = { 4,5 };
    Solution s;
    auto actual = s.reachableNodes(7, edges, restricted);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}

}

