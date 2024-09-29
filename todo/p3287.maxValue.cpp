#include <gtest/gtest.h>
#include <unordered_set>

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
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        auto get_nums = [&](vector<int> &ns){
            vector<vector<int>> answers;
            vector<unordered_set<int>> rs(k);
            for (auto x : ns) {
                for (int i = k - 1; i > 0; --i) {
                    for (auto &nr : rs[i-1]) {
                        rs[i].insert(nr | x);
                    }
                }
                rs[0].insert(x);
                answers.push_back(vector<int>(rs.back().begin(), rs.back().end()));
            }
            return answers;
        };

        auto left = get_nums(nums);
        reverse(nums.begin(), nums.end());
        auto righ = get_nums(nums);
        reverse(righ.begin(), righ.end());

        int ans = INT_MIN;
        for (int i = 0; i < n-1; ++i) {
            auto &ls = left[i];
            auto &rs = righ[i+1];
            for (auto lv : ls)
                for (auto rv : rs)
                    ans = max(ans, lv ^ rv);
        }
        return ans;
    }
};

class PTest3287 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3287, Test1) {
    Solution s;
    vector<int> nums = {2,6,7};
    int k = 1;
    auto actual = s.maxValue(nums, k);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3287, Test2) {
    Solution s;
    vector<int> nums = {4,2,5,6,7};
    int k = 2;
    auto actual = s.maxValue(nums, k);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
}


