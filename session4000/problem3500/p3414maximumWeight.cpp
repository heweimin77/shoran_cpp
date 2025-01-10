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
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); ++i) intervals[i].push_back(i);
        std::sort(intervals.begin(), intervals.end());
        map<int, array<vector<long long>, 4>> answers;
        answers[INT_MAX] = {{{0}, {0}, {0}, {0}}};
        for (int j = intervals.size()-1; j >= 0; --j) {
            int l = intervals[j][0], r = intervals[j][1], w = intervals[j][2], index = intervals[j][3];
            if (answers.begin()->first != l) {
                answers[l] = answers.begin()->second;
            }
            auto &last = answers.upper_bound(r)->second;
            auto &ans = answers[l];
            ans[0] = min(ans[0], {-w, index});
            for (int i = 1; i < 4; ++i) {
                vector<long long> r = last[i-1];
                r[0] -= w;
                r.push_back(index);
                sort(r.begin()+1, r.end());
                ans[i] = min(ans[i], r);
            }
        }
        auto &ans = answers.begin()->second;
        return vector<int>(ans[3].begin()+1, ans[3].end());
    }
};

class PTest3414 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3414, Test1) {
    Solution s;
    vector<vector<int>> intervals = {{1,3,2},{4,5,2},{1,5,5},{6,9,3},{6,7,1},{8,9,1}};
    auto actual = s.maximumWeight(intervals);
    decltype(actual) expect = {2,3};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3414, Test2) {
    Solution s;
    vector<vector<int>> intervals = {{5,8,1},{6,7,7},{4,7,3},{9,10,6},{7,8,2},{11,14,3},{3,5,5}};
    auto actual = s.maximumWeight(intervals);
    decltype(actual) expect = {1,3,5,6};
    EXPECT_EQ(expect, actual);
}
}


