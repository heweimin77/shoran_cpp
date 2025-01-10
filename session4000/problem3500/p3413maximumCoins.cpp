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
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        std::sort(coins.begin(), coins.end());
        auto get_count = [](vector<vector<int>>& coins, int k) {
            int limit = INT_MIN, j = 0;
            long long ans = 0, r = 0;
            for (auto &coin: coins) {
                int nlimit = coin[0] + k;
                while (j < coins.size() && limit < nlimit) {
                    if (coins[j][0] >= nlimit) break;
                    r += (min(coins[j][1] + 1, nlimit) - max(coins[j][0], limit)) * (long long)coins[j][2];
                    limit = min(coins[j][1] + 1, nlimit);
                    if (limit > coins[j][1]) ++j;
                }
                ans = max(ans, r);
                if (limit > coin[1]) {
                    r -= (coin[1] - coin[0] + 1) * (long long)coin[2];
                } else {
                    r = 0;
                    limit = coin[1] + 1;
                }
            }
            return ans;
        };
        long long r = get_count(coins, k);
        for (auto &coin : coins) {
            coin = {-coin[1], -coin[0], coin[2]};
        }
        reverse(coins.begin(), coins.end());
        return max(r, get_count(coins, k));
    }
};

class PTest3413 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3413, Test1) {
    Solution s;
    vector<vector<int>> coins = {{8,10,1},{1,3,2},{5,6,4}};
    auto actual = s.maximumCoins(coins, 4);
    decltype(actual) expect = 10;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3413, Test2) {
    Solution s;
    vector<vector<int>> coins = {{1,10,3}};
    auto actual = s.maximumCoins(coins, 2);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3413, Test3) {
    Solution s;
    vector<vector<int>> coins = {{31,39,20},{27,29,6},{1,3,4}};
    auto actual = s.maximumCoins(coins, 3);
    decltype(actual) expect = 60;
    EXPECT_EQ(expect, actual);
}
}


