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
    int numberOfStableArrays(int zero, int one, int limit) {
        int MOD = 1e9 + 7;
        vector<vector<pair<long long,long long>>> answers(zero+1, vector<pair<long long,long long>>(one+1));
        answers[0][0] = {1,1};
        answers[1][0].first = answers[0][1].second = 1;
        for (int i = 0; i <= zero; ++i) {
            for (int j = 0; j <= one; ++j) {
                if (i + j <= 1) continue;
                if (i >= 1) {
                    answers[i][j].first = answers[i-1][j].first + answers[i-1][j].second - (i - limit - 1 >= 0 ? answers[i-limit-1][j].second: 0) + MOD;
                    answers[i][j].first %= MOD;
                }
                if (j >= 1) {
                    answers[i][j].second = answers[i][j-1].first + answers[i][j-1].second - (j - limit - 1 >= 0 ? answers[i][j-limit-1].first: 0) + MOD;
                    answers[i][j].second %= MOD;
                }
            }
        }
        return (answers[zero][one].first + answers[zero][one].second) % MOD;
    }
};
#undef MAKE_KEY
#undef GET_CNT0
#undef GET_CNT1
#undef GET_LAST
#undef GET_CNT
class Solution665of670 {
#define MAKE_KEY(cnt0, cnt1, last, cnt) (((cnt0)<<24) | ((cnt1) <<16) | ((last) <<8) | (cnt))
#define GET_CNT0(key) ((key) >> 24)
#define GET_CNT1(key) (((key) >> 16) & 0xFF)
#define GET_LAST(key) (((key) >> 8) & 0xFF)
#define GET_CNT(key) ((key) & 0xFF)
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int MOD = 1e9 + 7;
        unordered_map<unsigned int,long long> nows;
        nows[0] = 1;
        for (int i = 0; i < zero + one; ++i) {
            unordered_map<unsigned int, long long> nexts;
            for (auto [key, value]: nows) {
                value %= MOD;
                unsigned int cnt0 = GET_CNT0(key), cnt1 = GET_CNT1(key), last = GET_LAST(key), cnt = GET_CNT(key);
                unsigned int ncnt0 = cnt0 + 1, ncnt1 = cnt1, nlast = 0, ncnt = last == 0 ? cnt + 1 : 1;
                if (ncnt0 <= zero && ncnt <= limit) {
                    nexts[MAKE_KEY(ncnt0, ncnt1, nlast, ncnt)] += value;
                }
                ncnt0 = cnt0, ncnt1 = cnt1 + 1, nlast = 1, ncnt = last == 1 ? cnt + 1 : 1;
                if (ncnt1 <= one && ncnt <= limit) {
                    nexts[MAKE_KEY(ncnt0, ncnt1, nlast, ncnt)] += value;
                }
            }
            nows = std::move(nexts);
        }
        long long ans = 0;
        for (auto [key, value]: nows) {
            ans += value;
        }
        return ans % MOD;
    }
};

class PTest3129 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3129, Test1) {
    Solution s;
    auto actual = s.numberOfStableArrays(1, 1, 2);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3129, Test2) {
    Solution s;
    auto actual = s.numberOfStableArrays(1, 2, 1);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3129, Test3) {
    Solution s;
    auto actual = s.numberOfStableArrays(3, 3, 2);
    decltype(actual) expect = 14;
    EXPECT_EQ(expect, actual);
}
}


