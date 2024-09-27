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
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adjs(n);
        for (auto &e : edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }
        int answer = 0;
        function<int(int, int)> traverse = [&](int now, int parent) {
            int cnt = 0;
            int rcnt = 0;
            for (int child : adjs[now]) {
                if (child == parent) continue;
                int ccnt = traverse(child, now);
                rcnt = (rcnt == 0 || rcnt == ccnt) ? ccnt : INT_MAX;
                cnt += ccnt;
            }
            if (rcnt != INT_MAX) ++answer;
            return cnt + 1;
        };
        traverse(0, -1);
        return answer;
    }
};

class PTest3249 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3249, Test1) {
    Solution s;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    auto actual = s.countGoodNodes(edges);
    decltype(actual) expect = 7;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3249, Test2) {
    Solution s;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{0,5},{1,6},{2,7},{3,8}};
    auto actual = s.countGoodNodes(edges);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3249, Test3) {
    Solution s;
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{1,4},{0,5},{5,6},{6,7},{7,8},{0,9},{9,10},{9,12},{10,11}};
    auto actual = s.countGoodNodes(edges);
    decltype(actual) expect = 12;
    EXPECT_EQ(expect, actual);
}
}


