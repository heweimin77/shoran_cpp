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
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        colors.insert(colors.end(), colors.begin(), colors.begin() + k);
        int i = 0, ans = 0;
        while (i < n) {
            int j = i;
            while (j < colors.size() - 1 && colors[j] != colors[j+1]) ++j;
            if (j - i + 1 >= k) {
                if (j < n) {
                    ans += j - i - k + 2;
                } else {
                    ans += min(j - i - k + 2, n - i);
                }
            }
            i = j + 1;
        }

        return ans;
    }
};

class P3208Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3208Test, Test1)
{
    Solution s;
    vector<int> colors = {0,1,0,1,0};
    int k = 3;
    auto actual = s.numberOfAlternatingGroups(colors, k);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3208Test, Test2)
{
    Solution s;
    vector<int> colors = {0,1,0,0,1,0,1};
    int k = 6;
    auto actual = s.numberOfAlternatingGroups(colors, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}

}


