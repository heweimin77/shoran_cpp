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
    int maxTotalReward(vector<int>& rewardValues) {
        std::sort(rewardValues.begin(), rewardValues.end());
        int nmax = rewardValues.back() * 2;
        bool flag[nmax];
        memset(flag, 0, sizeof(flag));
        for (auto r : rewardValues) {
            flag[r] = true;
            for (int j = r - 1; j > 0; --j) {
                if (flag[j]) flag[j+r] = true;
            }
        }
        for (int j = nmax-1; j > 0; --j) {
            if (flag[j]) return j;
        }
    }
};
class Solution2 {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        set<int> data;
        std::sort(rewardValues.begin(), rewardValues.end());
        for (auto r : rewardValues) {
            data.insert(r);
            for (auto it = data.begin(); it != data.end(); ++it) {
                if (*it >= r) break;
                data.insert(*it + r);
            }
        }
        return *data.rbegin();
    }
};

class PTest3180 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3180, Test1) {
    Solution s;
    vector<int> rewardValues = {1,1,3,3};
    auto actual = s.maxTotalReward(rewardValues);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3180, Test2) {
    Solution s;
    vector<int> rewardValues = {1,6,4,3,2};
    auto actual = s.maxTotalReward(rewardValues);
    decltype(actual) expect = 11;
    EXPECT_EQ(expect, actual);
}
}


