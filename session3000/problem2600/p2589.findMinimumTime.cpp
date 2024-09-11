#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] < rhs[1];
            });

        set<int> select;
        for (auto& t : tasks) {
            int cnt = t[2];
            for (auto it = select.lower_bound(t[0]); cnt > 0 && it != select.end(); ++it) --cnt;
            for (int i = t[1]; cnt > 0; --i) {
                if (select.count(i) == 0) {
                    select.insert(i);
                    --cnt;
                }
            }
        }
        return select.size();
    }
};

class P2589Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2589Test, TestMain)
{
    vector<vector<int>> task = { {2,3,1}, {4,5,1}, {1,5,2} };
    Solution s;
    auto actual = s.findMinimumTime(task);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}

}
