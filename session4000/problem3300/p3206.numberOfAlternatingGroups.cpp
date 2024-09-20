#include <gtest/gtest.h>

using namespace std;

namespace {
class AutoRun {
public:
    AutoRun() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

} autorun;
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        for (int i = 1; i < colors.size()-1; ++i) {
            if (colors[i] != colors[i-1] && colors[i] != colors[i+1]) {
                ++ans;
            }
        }
        return ans;
    }
};
class Solution2 {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0, n = colors.size();
        if (colors[0] != colors[1] && colors[0] != colors.back()) ++ans;
        if (colors.back() != colors[0] && colors.back() != colors[n-2]) ++ans;
        for (int i = 1; i < n-1; ++i) {
            if (colors[i] != colors[i-1] && colors[i] != colors[i+1]) {
                ++ans;
            }
        }
        return ans;
    }
};

class P3206Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3206Test, Test1)
{
    Solution s;
    vector<int> colors = {1,1,1};
    auto actual = s.numberOfAlternatingGroups(colors);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3206Test, Test2)
{
    Solution s;
    vector<int> colors = {0,1,0,0,1};
    auto actual = s.numberOfAlternatingGroups(colors);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3206Test, Test3)
{
    Solution s;
    vector<int> colors = {0, 0, 1};
    auto actual = s.numberOfAlternatingGroups(colors);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}


