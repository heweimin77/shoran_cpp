#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (auto n : nums) ++counts[n];
        vector<int> group;
        for (auto cnt : counts) group.push_back(cnt.second);
        sort(group.begin(), group.end());
        for (int i = 1; ; ++i) {
            vector<int> xs;
            int x = group[0] / i;
            xs.push_back(x);
            if (group[0] % i == 0) {
                xs.push_back(x - 1);
            }

            for (auto x : xs) {
                int result = 0;
                bool ok = true;
                for (auto g : group) {
                    // x , x + 1
                    if (g % x > g / x) {
                        ok = false;
                        break;
                    }
                    if (g % (x + 1) == 0) {
                        result += g / (x + 1);
                    } else {
                        result += g / (x + 1) + 1;
                    }
                }
                if (ok) {
                    return result;
                }
            }
        }

    }
};

class P2910Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2910Test, Test1)
{
    vector<int> nums = { 3,2,3,2,3 };
    Solution s;
    auto actual = s.minGroupsForValidAssignment(nums);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2910Test, TestMain)
{
    vector<int> nums = { 1,1,1,1,2,2,2,1,2,1,1 };
    Solution s;
    auto actual = s.minGroupsForValidAssignment(nums);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}

}
