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
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int nmax = *max_element(nums.begin(), nums.end());
        vector<int> xcnts(nmax + 1);
        for (auto x : nums) ++xcnts[x];
        vector<long long> gcdcnts(nmax + 1);
        for (int i = nmax; i > 0; --i) {
            long long c = 0, r = 0;
            for (int j = i; j <= nmax; j += i) {
                c += xcnts[j];
                r += gcdcnts[j];
            }
            gcdcnts[i] = c * (c - 1) / 2 - r;
        }

        partial_sum(gcdcnts.begin(), gcdcnts.end(), gcdcnts.begin());
        vector<int> ans;
        for (auto q : queries) {
            ans.push_back(upper_bound(gcdcnts.begin(), gcdcnts.end(), q) - gcdcnts.begin());
        }
        return ans;
    }
};

class PTest3312 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3312, Test1) {
    Solution s;
    vector<int> nums = {2,3,4};
    vector<long long> queries = {0,2,2};
    auto actual = s.gcdValues(nums, queries);
    decltype(actual) expect = {1,2,2};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3312, Test2) {
    Solution s;
    vector<int> nums = {4,4,2,1};
    vector<long long> queries = {5,3,1,0};
    auto actual = s.gcdValues(nums, queries);
    decltype(actual) expect = {4,2,1,1};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3312, Test3) {
    Solution s;
    vector<int> nums = {2,2};
    vector<long long> queries = {0,0};
    auto actual = s.gcdValues(nums, queries);
    decltype(actual) expect = {2,2};
    EXPECT_EQ(expect, actual);
}
}


