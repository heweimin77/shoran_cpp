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
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> answers;
        bool keep = true;
        for (int i = 0; i < grid.size(); ++i) {
            auto &line = grid[i];
            if (i & 1) {
                for (int j = line.size() - 1; j >= 0; --j) {
                    if (keep) answers.push_back(line[j]);
                    keep = ! keep;
                }
            } else {
                for (int j = 0; j < line.size(); ++j) {
                    if (keep) answers.push_back(line[j]);
                    keep = ! keep;

                }
            }
        }

        return answers;
    }
};

class PTest3417 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3417, Test1) {
    Solution s;
    vector<vector<int>> grid = {{1,2},{3,4}};
    auto actual = s.zigzagTraversal(grid);
    decltype(actual) expect = {1, 4};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3417, Test2) {
    Solution s;
    vector<vector<int>> grid = {{2,1},{2,1},{2,1}};
    auto actual = s.zigzagTraversal(grid);
    decltype(actual) expect = {2,1,2};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3417, Test3) {
    Solution s;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    auto actual = s.zigzagTraversal(grid);
    decltype(actual) expect = {1,3,5,7,9};
    EXPECT_EQ(expect, actual);
}
}


