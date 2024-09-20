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
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,long long> nows;
        long long ans = 0;
        for (int x : nums) {
            if ((x & k)!=k) {
                nows.clear();
                continue;
            }
            unordered_map<int,long long> nexts;
            nexts[x] = 1;
            for (auto &n : nows) {
                int nk = n.first & x;
                if ((nk & k) != k) continue;
                nexts[nk] += n.second;
            }
            ans += nexts[k];
            nows = std::move(nexts);
        }
        return ans;
    }
};

class P3209Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3209Test, Test1)
{
    Solution s;
    vector<int> nums = {1,1,1};
    int k = 1;
    auto actual = s.countSubarrays(nums, k);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3209Test, Test2)
{
    Solution s;
    vector<int> nums = {1,1,2};
    int k = 1;
    auto actual = s.countSubarrays(nums, k);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3209Test, Test3)
{
    Solution s;
    vector<int> nums = {1,2,3};
    int k = 2;
    auto actual = s.countSubarrays(nums, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}

}


