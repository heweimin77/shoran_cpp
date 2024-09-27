#include <gtest/gtest.h>
#include <numeric>
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
    int countOfPairs(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int s = 50;
        vector<int> results = {1};
        for (int ss: nums) {
            vector<int> nexts(ss + 1);
            for (int i = 0; i <= ss; ++i) {
                long long r = 0;
                for (int j = 0; j <= min(i, (int)results.size()-1); ++j) {
                    if (s - j < ss - i) break;
                    r += results[j];
                }
                nexts[i] = r % MOD;
            }
            s = ss;
            results = std::move(nexts);
        }
        return std::accumulate(results.begin(), results.end(), 0LL) % MOD;
    }
};

class PTest3250 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3250, Test1) {
    Solution s;
    vector<int> nums = {2,3,2};
    auto actual = s.countOfPairs(nums);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3250, Test2) {
    Solution s;
    vector<int> nums = {5,5,5,5};
    auto actual = s.countOfPairs(nums);
    decltype(actual) expect = 126;
    EXPECT_EQ(expect, actual);
}
}


