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
        vector<int> answers;
        map<int,int> ranges;
        int distance = 0;
        for (auto &q : queries) {
            auto it = ranges.upper_bound(q[0]);
            if (it == ranges.begin()) {
                it = ranges.insert(make_pair(q[0], q[1])).first;
                distance += q[1] - q[0] - 1;
            } else {
                --it;
                if (it->second <= q[0]) {
                    it = ranges.insert(make_pair(q[0], q[1])).first;
                    distance += q[1] - q[0] - 1;
                } else if (it->first == q[0] && q[1] > it->second){
                    distance += q[1] - it->second;
                    it->second = q[1];
                } else {
                    it = ranges.end();
                }
            }
            while (it != ranges.end()) {
                auto jt = it;
                ++jt;
                if (jt == ranges.end()) break;
                if (jt->first == it->first) {
                    if (it->second > jt->second) {
                        distance += jt->second - jt->first - 1;
                        ranges.erase(jt);
                    } else {
                        distance += it->second - it->first - 1;
                        ranges.erase(it);
                        break;
                    }
                } else {
                    if (jt->second <= it->second) {
                        distance -= jt->second - jt->first - 1;
                        ranges.erase(jt);
                    } else {
                        break;
                    }
                }
            }
            answers.push_back(n - 1 - distance);
        }

        return answers;
    }
};

class PTest3244 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3244, Test1) {
    Solution s;
    int n = 5;
    vector<vector<int>> queries = {{2, 4},{0, 2},{0, 4}};
    auto actual = s.shortestDistanceAfterQueries(n, queries);
    decltype(actual) expect = {3,2,1};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3244, Test2) {
    Solution s;
    int n = 4;
    vector<vector<int>> queries = {{0, 3},{0, 2}};
    auto actual = s.shortestDistanceAfterQueries(n, queries);
    decltype(actual) expect = {1,1};
    EXPECT_EQ(expect, actual);
}
}


