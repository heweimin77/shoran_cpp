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
    int findWinningPlayer(vector<int>& skills, int k) {
        int ans = 0, cnt = 0;
        for (int i = 1; i < skills.size(); ++i) {
            if (skills[ans] > skills[i]) ++cnt;
            else {
                ans = i;
                cnt = 1;
            }
            if (cnt == k) break;
        }
        return ans;
    }
};

class PTest3175 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3175, Test1) {
    Solution s;
    vector<int> skills  = {4,2,6,3,9};
    int k = 2;
    auto actual = s.findWinningPlayer(skills, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3175, Test2) {
    Solution s;
    vector<int> skills  = {2,5,4};
    int k = 3;
    auto actual = s.findWinningPlayer(skills, k);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}


