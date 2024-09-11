#include <gtest/gtest.h>
#include <queue>

using namespace std;

namespace {
class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> results(n);
        vector<vector<int>> prevs(n), nexts(n);
        for (auto& e: edges) {
            nexts[e[0]].push_back(e[1]);
            prevs[e[1]].push_back(e[0]);
        }

        function<int(int,int)> dfs = [&](int now, int parent) {
            int r = 0;
            for (int n : prevs[now]) {
                if (n == parent) continue;
                ++r;
                r += dfs(n, now);
            }
            for (int n : nexts[now]) {
                if (n == parent) continue;
                r += dfs(n, now);
            }
            return r;
        };

        results[0] = dfs(0, -1);

        function<void(int now, int parent, int value)> changeroot = [&](int now, int parent, int value) {
            results[now] = value;
            for (int n : prevs[now]) {
                if (n == parent) continue;
                changeroot(n, now, value - 1);
            }
            for (int n : nexts[now]) {
                if (n == parent) continue;
                changeroot(n, now, value + 1);
            }
        };

        changeroot(0, -1, results[0]);
        return results;
    }

};

class Solution2 {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> results(n);
        vector<vector<int>> prevs(n), nexts(n);
        for (auto& e: edges) {
            nexts[e[0]].push_back(e[1]);
            prevs[e[1]].push_back(e[0]);
        }
        results[0] = dfs(prevs, nexts, 0, -1);
        changeroot(prevs, nexts, 0, -1, results, results[0]);
        return results;
    }

    int dfs(vector<vector<int>> &prevs, vector<vector<int>> &nexts, int now, int parent) {
        int r = 0;
        for (int n : prevs[now]) {
            if (n == parent) continue;
            ++r;
            r += dfs(prevs, nexts, n, now);
        }
        for (int n : nexts[now]) {
            if (n == parent) continue;
            r += dfs(prevs, nexts, n, now);
        }
        return r;
    }
    void changeroot(vector<vector<int>> &prevs, vector<vector<int>> &nexts, int now, int parent, vector<int> &results , int value) {
        results[now] = value;
        for (int n : prevs[now]) {
            if (n == parent) continue;
            changeroot(prevs, nexts, n, now, results, value - 1);
        }
        for (int n : nexts[now]) {
            if (n == parent) continue;
            changeroot(prevs, nexts, n, now, results, value + 1);
        }
    }
};

class P2858Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2858Test, Test1)
{
    vector<vector<int>> edges = {{2,0}, {2,1}, {1,3}};
    Solution s;
    auto actual = s.minEdgeReversals(4, edges);
    decltype(actual) expect = { 1,1,0,2 };
    EXPECT_EQ(expect, actual);
}

TEST_F(P2858Test, Test2)
{
    vector<vector<int>> edges = { {0,3}, {1,2}, {2,3} };
    Solution s;
    auto actual = s.minEdgeReversals(4, edges);
    decltype(actual) expect = { 2,1,2,3 };
    EXPECT_EQ(expect, actual);
}

TEST_F(P2858Test, Test3)
{
    vector<vector<int>> edges = { {0,3}, {1,2}, {2,3} };
    Solution s;
    auto actual = s.minEdgeReversals(4, edges);
    decltype(actual) expect = { 2,1,2,3 };
    EXPECT_EQ(expect, actual);
}

TEST_F(P2858Test, Test4)
{
    vector<vector<int>> edges = { {0,1}, {2,0}, {0,4}, {3,4} };
    Solution s;
    auto actual = s.minEdgeReversals(5, edges);
    decltype(actual) expect = { 2,3,1,2,3 };
    EXPECT_EQ(expect, actual);
}
}
