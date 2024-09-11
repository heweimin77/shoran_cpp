#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> fns(n);
        for (int i = 0; i < n; ++i) {
            fns[i].resize(i+1);
            fns[i][i] = nums[i];
        }
        vector<vector<int>> mxors = fns;
        for (int d = 1; d < n; ++d) {
            for (int i = d; i < n; ++i) {
                int j = i - d;
                int r = fns[i][j] = fns[i-1][j] ^ fns[i][j+1];
                r = max(r, mxors[i-1][j]);
                r = max(r, mxors[i][j+1]);
                mxors[i][j] = r;
            }
        }
        vector<int> ans;
        for (auto &q : queries) {
            ans.push_back(mxors[q[1]][q[0]]);
        }
        return ans;
    }
};

class P3277Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3277Test, Test1)
{
    Solution s;
    vector<int> nums = {2,8,4,32,16,1};
    vector<vector<int>> queries = {{0,2},{1,4},{0,5}};
    auto actual = s.maximumSubarrayXor(nums, queries);
    decltype(actual) expect = {12,60,60};
    EXPECT_EQ(expect, actual);
}
TEST_F(P3277Test, Test2)
{
    Solution s;
    vector<int> nums = {0,7,3,2,8,5,1};
    vector<vector<int>> queries = {{0,3},{1,5},{2,4},{2,6},{5,6}};
    auto actual = s.maximumSubarrayXor(nums, queries);
    decltype(actual) expect = {7,14,11,14,5};
    EXPECT_EQ(expect, actual);
}

}


