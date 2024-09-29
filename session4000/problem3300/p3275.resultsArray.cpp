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
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> qs;
        vector<int> ans;
        for (auto &q : queries) {
            qs.push(abs(q[0]) + abs(q[1]));
            if (qs.size() > k) qs.pop();
            ans.push_back(qs.size() == k ? qs.top() : -1);
        }
        return ans;
    }
};

class PTest3275 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3275, Test1) {
    Solution s;
    vector<vector<int>> queries = {{1,2},{3,4},{2,3},{-3,0}};
    int k = 2;
    auto actual = s.resultsArray(queries, k);
    decltype(actual) expect = {-1,7,5,3};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3275, Test2) {
    Solution s;
    vector<vector<int>> queries = {{5,5},{4,4},{3,3}};
    int k = 1;
    auto actual = s.resultsArray(queries, k);
    decltype(actual) expect = {10,8,6};
    EXPECT_EQ(expect, actual);
}
}


