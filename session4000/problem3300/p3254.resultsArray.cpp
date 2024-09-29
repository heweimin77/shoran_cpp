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
    vector<int> resultsArray(vector<int>& nums, int k) {
        int x = 1;
        for (int i = 1; i < k; ++i) {
            if (nums[i] == nums[i-1]+1) ++x;
            else x = 1;
        }
        vector<int> answer(1, x == k ? nums[k-1] : -1);
        for (int i = k; i < nums.size(); ++i) {
            if (x == k) --x;
            if (nums[i] == nums[i-1]+1) ++x;
            else x = 1;
            answer.push_back(x == k ? nums[i] : -1);
        }
        return answer;
    }
};

class PTest3254 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3254, Test1) {
    Solution s;
    vector<int> nums = {1,2,3,4,3,2,5};
    int k = 3;
    auto actual = s.resultsArray(nums, k);
    decltype(actual) expect = {3,4,-1,-1,-1};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3254, Test2) {
    Solution s;
    vector<int> nums = {2,2,2,2,2};
    int k = 4;
    auto actual = s.resultsArray(nums, k);
    decltype(actual) expect = {-1,-1};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3254, Test3) {
    Solution s;
    vector<int> nums = {3,2,3,2,3,2};
    int k = 2;
    auto actual = s.resultsArray(nums, k);
    decltype(actual) expect = {-1,3,-1,3,-1};
    EXPECT_EQ(expect, actual);
}
}


