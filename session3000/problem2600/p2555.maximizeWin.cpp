#include <gtest/gtest.h>

using namespace std;

namespace {
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        vector<pair<int,int>> ranges;
        int i = 0, j = 0, n = prizePositions.size();
        while (i < n) {
            int now = prizePositions[i];
            while (i < n && prizePositions[i] == now) ++i;
            while (prizePositions[j] < now - k) ++j;
            ranges.emplace_back(now, i - j);
        }
        int ans = 0, r = 0;
        for (i = 0, j = 0; i < ranges.size(); ++i) {
            while (ranges[j].first < ranges[i].first - k) {
                r = max(ranges[j].second, r);
                ++j;
            }
            ans = max(ranges[i].second + r, ans);
        }
        return ans;
    }
};

class Solution2 {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        vector<pair<int,int>> ranges;
        int i = 0, j = 0, n = prizePositions.size();
        while (i < n) {
            int now = prizePositions[i];
            while (i < n && prizePositions[i] == now) ++i;
            while (prizePositions[j] < now - k) ++j;
            ranges.emplace_back(now, i - j);
        }
        vector<pair<int,int>> right = ranges;
        for (int i = right.size() - 2; i >= 0; --i) {
            right[i].second = max(right[i].second, right[i+1].second);
        }

        int ans = right[0].second, r = 0;
        j = 0;
        for (int i = 0; i < ranges.size(); ++i) {
            r = max(r, ranges[i].second);
            while (j < right.size() && ranges[j].first <= right[i].first + k)
                ++j;
            if (j == right.size()) break;
            ans = max(ans, r + right[j].second);
        }
        return ans;
    }
};

class P2555Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2555Test, Test1)
{
    Solution s;
    vector<int> prizePositions = {1,1,2,2,3,3,5};
    int k = 2;
    auto actual = s.maximizeWin(prizePositions, k);
    decltype(actual) expect = 7;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2555Test, Test2)
{
    Solution s;
    vector<int> prizePositions = {1, 2, 3, 4};
    int k = 0;
    auto actual = s.maximizeWin(prizePositions, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2555Test, Test3)
{
    Solution s;
    vector<int> prizePositions = {2616,2618,2620,2621,2626,2635,2657,2662,2662,2669,2671,2693,2702,2713,2714,2718,2730,2731,2750,2756,2772,2773,2775,2785,2795,2805,2811,2813,2816,2823,2824,2824,2826,2830,2833,2857,2885,2898,2910,2919,2928,2941,2942,2944,2965,2967,2970,2973,2974,2975,2977,3002,3007,3012,3042,3049,3078,3084,3089,3090,3094,3097,3114,3124,3125,3125,3144,3147,3148,3174,3197,3255,3262,3288,3291,3316,3320,3322,3331,3342,3378,3412,3412,3416,3420,3427,3428,3446,3452,3472,3479,3483,3488,3500,3516,3522,3531,3532,3540,3540,3544,3557,3570,3580,3592,3597,3597,3601,3615,3631,3640,3645,3673,3677,3681,3683,3685,3718,3738,3746,3758,3769,3797,3802,3815,3832,3839,3851,3864,3888,3889,3901,3902,3910,3913,3933,3940,3961,3974,3988,4003,4013,4019,4023,4026,4047,4060,4065,4072,4073,4082,4084,4109,4132,4139,4143,4145,4146,4155};
    int k = 6641;
    auto actual = s.maximizeWin(prizePositions, k);
    decltype(actual) expect = 159;
    EXPECT_EQ(expect, actual);
}
}


