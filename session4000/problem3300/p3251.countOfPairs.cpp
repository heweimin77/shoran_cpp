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
        int n = *max_element(nums.begin(), nums.end());
        int buffer1[n + 1], buffer2[n+1];
        int last = nums[0];
        int *answers = buffer1, *nexts = buffer2;
        for (int i = 0; i <= n; ++i) answers[i] = i <= last ? 1 : 0;
        for (int i = 1; i < nums.size(); ++i) {
            int now = nums[i];
            for (int j = 0; j < n; ++j) answers[j+1] = (answers[j] + answers[j+1]) % MOD;

            fill(nexts, nexts + n + 1, 0);
            for (int y = 0; y <= now; ++y) {
                int limit = min(y, last + y - now);
                if (limit >= 0) nexts[y] = answers[limit];
            }
            last = now;
            swap(answers, nexts);
        }
        return accumulate(answers, answers + n + 1, 0LL) % MOD;
    }
    int countOfPairs2(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = *max_element(nums.begin(), nums.end());
        int last = nums[0];
        vector<int> answers(n + 1);
        for (int i = 0; i <= n; ++i) answers[i] = i <= last ? 1 : 0;
        for (int i = 1; i < nums.size(); ++i) {
            int now = nums[i];
            for (int j = 0; j < n; ++j) answers[j+1] = (answers[j] + answers[j+1]) % MOD;

            vector<int> nexts(n + 1);
            for (int y = 0; y <= now; ++y) {
                int limit = min(y, last + y - now);
                if (limit >= 0) nexts[y] = answers[limit];
            }
            last = now;
            answers = std::move(nexts);
        }
        return accumulate(answers.begin(), answers.end(), 0LL) % MOD;
    }
};

class PTest3251 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3251, Test1) {
    Solution s;
    vector<int> nums = {2,3,2};
    auto actual = s.countOfPairs(nums);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3251, Test2) {
    Solution s;
    vector<int> nums = {5,5,5,5};
    auto actual = s.countOfPairs(nums);
    decltype(actual) expect = 126;
    EXPECT_EQ(expect, actual);
}
}


