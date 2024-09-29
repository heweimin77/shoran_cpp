#include <gtest/gtest.h>
#include <queue>

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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto fast_power = [](long long base, int n, int module) {
            long long result = 1;
            for (int mask = 1; mask <= n; mask <<= 1) {
                if (mask & n) result = (result * base) % module;
                base = (base * base) % module;
            }
            return result;
        };
        if (multiplier == 1) return nums;
        int n = nums.size(), MOD = 1e9 + 7;
        int nmax = *max_element(nums.begin(), nums.end());

        auto get_count = [&](int v) {
            int cnt = 0;
            for (long long x : nums) {
                while (x * multiplier <= v) {
                    ++cnt;
                    x *= multiplier;
                }
            }
            return cnt;
        };

        auto mul = [&](int v) {
            for (int i = 0; i < nums.size(); ++i) {
                long long x = nums[i];
                while (x * multiplier <= v) {
                    x *= multiplier;
                    nums[i] = x;
                }
            }
        };
        auto mulk = [&](int k) {
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
            for (int i = 0; i < nums.size(); ++i)  q.push({nums[i], i});
            for (int j = 0; j < k; ++j) {
                auto [v, i] = q.top();
                q.pop();
                v *= multiplier;
                nums[i] = v % MOD;
                q.push({v, i});
            }
        };

        int xcnt = get_count(nmax);
        if (xcnt <= k) {
            k -= xcnt;
            mul(nmax);
            mulk(k % n);
            long long xx = fast_power(multiplier, k / n, MOD);
            for (int i = 0; i < n; ++i) nums[i] = (nums[i] * xx) % MOD;
            return nums;
        } else {
            int low = 0, high = nmax;
            while (low < high) {
                int mid = (low + high) / 2;
                if (get_count(mid) < k) low = mid + 1;
                else                       high = mid;
            }
            int xcnt = get_count(low - 1);
            mul(low - 1);
            k -= xcnt;
            mulk(k);
            for (int i = 0; i < n; ++i) nums[i] %= MOD;
            return nums;
        }
    }
};

class PTest3266 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3266, Test1) {
    Solution s;
    vector<int> nums = {2,1,3,5,6};
    int k = 5, multiplier = 2;
    auto actual = s.getFinalState(nums, k, multiplier);
    decltype(actual) expect = {8,4,6,5,6};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3266, Test2) {
    Solution s;
    vector<int> nums = {1,2};
    int k = 3, multiplier = 4;
    auto actual = s.getFinalState(nums, k, multiplier);
    decltype(actual) expect = {16,8};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3266, Test3) {
    Solution s;
    vector<int> nums = {100000,2000};
    int k = 2, multiplier = 1000000;
    auto actual = s.getFinalState(nums, k, multiplier);
    decltype(actual) expect = {999999307,999999993};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3266, Test4) {
    Solution s;
    vector<int> nums = {689009555,813837455,240010825,967305450};
    int k = 804709161, multiplier = 601392;
    auto actual = s.getFinalState(nums, k, multiplier);
    decltype(actual) expect = {158205367,862774837,475528263,828321106};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3266, Test5) {
    Solution s;
    vector<int> nums = {2,1,2};
    int k = 2, multiplier = 8;
    auto actual = s.getFinalState(nums, k, multiplier);
    decltype(actual) expect = {16,8,2};
    EXPECT_EQ(expect, actual);
}
}


