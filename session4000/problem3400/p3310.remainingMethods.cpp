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
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> nexts(n), prevs(n);
        for (auto &invo: invocations) {
            nexts[invo[0]].push_back(invo[1]);
            prevs[invo[1]].push_back(invo[0]);
        }
        unordered_set<int> suspends;
        suspends.insert(k);
        vector<int> q = {k};
        while (!q.empty()) {
            int now = q.back();
            q.pop_back();
            for (auto next : nexts[now]) {
                if (suspends.contains(next)) continue;
                suspends.insert(next);
                q.push_back(next);
            }
        }
        for (auto now : suspends) {
            for (auto p : prevs[now]) {
                if (!suspends.contains(p)) {
                    vector<int> ans;
                    for (int i = 0; i < n; ++i) {
                        ans.push_back(i);
                    }
                    return ans;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!suspends.contains(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class PTest3310 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3310, Test1) {
    Solution s;
    int n = 4, k = 1;
    vector<vector<int>> invocations = {{1,2},{0,1},{3,2}};
    auto actual = s.remainingMethods(n, k, invocations);
    decltype(actual) expect = {0,1,2,3};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3310, Test2) {
    Solution s;
    int n = 5, k = 0;
    vector<vector<int>> invocations = {{1,2},{0,2},{0,1},{3,4}};
    auto actual = s.remainingMethods(n, k, invocations);
    decltype(actual) expect = {3,4};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3310, Test3) {
    Solution s;
    int n = 3, k = 2;
    vector<vector<int>> invocations = {{1,2},{0,1},{2,0}};
    auto actual = s.remainingMethods(n, k, invocations);
    decltype(actual) expect = {};
    EXPECT_EQ(expect, actual);
}
}


