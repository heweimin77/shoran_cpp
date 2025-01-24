#include <gtest/gtest.h>
#include <stack>

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
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sums(n);
        sums[0] = nums[0];
        for (int i = 0; i < n -1; ++i) sums[i+1] = sums[i] + nums[i+1];
        vector<int> nexts(n);
        stack<pair<int,int>> s;
        s.push({INT_MAX, n});
        for (int i = n - 1; i >= 0; --i) {
            auto x = nums[i];
            while (s.top().first < x) s.pop();
            nexts[i] = s.top().second;
            s.push({x, i});
        }

        int j = 0, limit = nums[0];
        long long kk = 0;
        long long answer = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && kk <= k) {
                kk += max(0, limit - nums[j]);
                limit = max(limit, nums[j]);
                ++j;
            }
            if (j <= n && kk <= k) {
                answer += (long long) (n - i) * (n - i + 1) / 2;
                break;
            }
            if (kk <= k) {
                answer += j - i;
            } else {
                answer += j - i - 1;
            }
            if (i + 1 >= n || nums[i] <= nums[i+1]) continue;
            int next = nexts[i];
            int jj = min(next, j);
            kk -= (long long)(jj - i - 1) * nums[i] - sums[jj - 1] + sums[i];
            int x = i + 1;
            long long xlimit = 0;
            while (x < jj) {
                xlimit = nums[x];
                int xn = nexts[x];
                if (xn < jj)
                    kk += xlimit * (xn - x) - sums[xn - 1] + sums[x - 1];
                else
                    kk += xlimit * (jj - x) - sums[jj - 1] + sums[x - 1];
                x = xn;
            }
            if (next >= j)
                limit = xlimit;
        }
        return answer;
    }
};

class PTest3420 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3420, Test1) {
    Solution s;
    vector<int> nums = {6,3,1,2,4,4};
    int k = 7;
    auto actual = s.countNonDecreasingSubarrays(nums, k);
    decltype(actual) expect = 17;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3420, Test2) {
    Solution s;
    vector<int> nums = {6,3,1,3,6};
    int k = 4;
    auto actual = s.countNonDecreasingSubarrays(nums, k);
    decltype(actual) expect = 12;
    EXPECT_EQ(expect, actual);
}
}


