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
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> visit;
        for (auto x : nums) {
            if (visit.contains(x)) {
                ans.push_back(x);
            } else {
                visit.insert(x);
            }
        }
        return ans;
    }
};

class PTest3289 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3289, Test1) {
    Solution s;
    vector<int> nums = {0,1,1,0};
    auto actual = s.getSneakyNumbers(nums);
    std::sort(actual.begin(), actual.end());
    decltype(actual) expect = {0, 1};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3289, Test2) {
    Solution s;
    vector<int> nums = {0,3,2,1,3,2};
    auto actual = s.getSneakyNumbers(nums);
    std::sort(actual.begin(), actual.end());
    decltype(actual) expect = {2, 3};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3289, Test3) {
    Solution s;
    vector<int> nums = {7,1,5,4,3,4,6,0,9,5,8,2};
    auto actual = s.getSneakyNumbers(nums);
    std::sort(actual.begin(), actual.end());
    decltype(actual) expect = {4,5};
    EXPECT_EQ(expect, actual);
}
}


