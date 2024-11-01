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
    long long findKthSmallest(vector<int>& coins, int k) {
        auto gcd = [](long long a, long long b) {
            if (a > b) swap(a, b);
            while (a > 0) {
                int tmp = a;
                a = b % a;
                b = tmp;
            }
            return b;
        };
        auto lcm = [&](long long a, long long b) {
            return a * b / gcd(a, b);
        };
        int n = coins.size();
        int x = 1 << n;
        vector<bool> flag(x, true);
        vector<long long> eves, odds;
        vector<long long> lcms(x, 1);
        unordered_map<int,int> xcoins;
        for (int i = 0; i < coins.size(); ++i) {
            xcoins[1 << i] = coins[i];
        }
        for (int i = 1; i < x; ++i) {
            int pi = i & (i - 1);
            int c = xcoins[i - pi];
            flag[i] = not flag[pi];
            lcms[i] = lcm(lcms[pi], c);
            if (flag[i]) eves.push_back(lcms[i]);
            else odds.push_back(lcms[i]);
        }

        auto check = [&](long long mid) {
            long long cnt = 0;
            for (auto d : odds) {
                cnt += mid / d;
            }
            for (auto d : eves) {
                cnt -= mid / d;
            }
            return cnt >= k;
        };
        long long low = 0, high = coins[0] * (long long)k;
        while (low < high) {
            long long mid = (low + high) / 2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

class PTest3116 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3116, Test1) {
    Solution s;
    vector<int> coins = {3,6,9};
    int k = 3;
    auto actual = s.findKthSmallest(coins, k);
    decltype(actual) expect = 9;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3116, Test2) {
    Solution s;
    vector<int> coins = {5,2};
    int k = 7;
    auto actual = s.findKthSmallest(coins, k);
    decltype(actual) expect = 12;
    EXPECT_EQ(expect, actual);
}
}


