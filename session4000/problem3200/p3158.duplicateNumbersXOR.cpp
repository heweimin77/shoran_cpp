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
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> visit;
        int ans = 0;
        for (auto n : nums) {
            if (visit.contains(n)) {
                ans ^= n;
            } else {
                visit.insert(n);
            }
        }
        return ans;
    }
};

class PTest3158 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3158, Test1) {
    Solution s;
    vector<int> nums = {1,2,1,3};
    auto actual = s.duplicateNumbersXOR(nums);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3158, Test2) {
    Solution s;
    vector<int> nums = {1,2,3};
    auto actual = s.duplicateNumbersXOR(nums);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3158, Test3) {
    Solution s;
    vector<int> nums = {1,2,2,1};
    auto actual = s.duplicateNumbersXOR(nums);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
}


