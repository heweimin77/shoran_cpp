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
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adjs(n);
        for (auto &e : edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }

        vector<int> answers(n);
        function<void(int, int)> traverse = [&](int now, int parent) {
            int ans = 0;
            for (int child : adjs[now]) {
                if (child == parent) continue;
                traverse(child, now);
                ans = max(ans, answers[child] + ((child & 1) ? 1 : 2));
            }
            answers[now] = ans;
        };
        traverse(0, -1);
        vector<int> results(n);
        function<void(int,int)> traverse2 = [&](int now, int parent) {
            int mans1 = 0, mans2 = 0;
            for (int child : adjs[now]) {
                int ans =  answers[child] + ((child & 1) ? 1 : 2);
                if (ans > mans1) {
                    mans2 = mans1;
                    mans1 = ans;
                } else if (ans > mans2) {
                    mans2 = ans;
                }
            }
            results[now] = mans1;
            for (int child: adjs[now]) {
                if (child == parent) continue;
                if (mans1 == answers[child]  + ((child & 1) ? 1 : 2)) {
                    answers[now] = mans2;
                } else {
                    answers[now] = mans1;
                }
                traverse2(child, now);
            }
            if (parent < 0) {
                answers[now] = mans1;
            } else if (mans1 == answers[parent]  + ((parent & 1) ? 1 : 2)) {
                answers[now] = mans2;
            } else {
                answers[now] = mans1;
            }
        };
        traverse2(0, -1);
        return results;
    }
};

class PTest3241 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3241, Test1) {
    Solution s;
    vector<vector<int>> edges = {{0,1},{0,2}};
    auto actual = s.timeTaken(edges);
    decltype(actual) expect = {2,4,3};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3241, Test2) {
    Solution s;
    vector<vector<int>> edges = {{0,1}};
    auto actual = s.timeTaken(edges);
    decltype(actual) expect = {1,2};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3241, Test3) {
    Solution s;
    vector<vector<int>> edges = {{2,4},{0,1},{2,3},{0,2}};
    auto actual = s.timeTaken(edges);
    decltype(actual) expect = {4,6,3,5,5};
    EXPECT_EQ(expect, actual);
}
}


