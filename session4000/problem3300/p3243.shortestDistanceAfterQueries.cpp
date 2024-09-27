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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> distances(n);
        vector<vector<int>> adjs(n);
        for (int i = 0; i < n - 1; ++i) {
            distances[i+1] = i + 1;
            adjs[i].push_back(i+1);
        }
        vector<int> answers;
        for (auto &q : queries) {
            adjs[q[0]].push_back(q[1]);
            if (distances[q[1]] > distances[q[0]] + 1) {
                queue<int> qs;
                distances[q[1]] = distances[q[0]] + 1;
                qs.push(q[1]);
                while (!qs.empty()) {
                    int now = qs.front();
                    qs.pop();
                    for (int next : adjs[now]) {
                        if (distances[next] > distances[now] + 1) {
                            distances[next] = distances[now] + 1;
                            qs.push(next);
                        }
                    }
                }
            }
            answers.push_back(distances[n-1]);
        }
        return answers;
    }
};

class PTest3243 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3243, Test1) {
    Solution s;
    int n = 5;
    vector<vector<int>> queries = {{2, 4},{0, 2},{0, 4}};
    auto actual = s.shortestDistanceAfterQueries(n, queries);
    decltype(actual) expect = {3,2,1};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3243, Test2) {
    Solution s;
    int n = 4;
    vector<vector<int>> queries = {{0, 3},{0, 2}};
    auto actual = s.shortestDistanceAfterQueries(n, queries);
    decltype(actual) expect = {1,1};
    EXPECT_EQ(expect, actual);
}
}


