#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

namespace {

class Solution {
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        if (space == 1) return *min_element(nums.begin(), nums.end());
        unordered_map<int, pair<int, int>> results;
        for (auto n : nums) {
            auto x = n % space;
            auto it = results.find(x);
            if (it == results.end()) {
                results.insert({ x, {1, n} });
            } else {
                it->second.first++;
                it->second.second = min(it->second.second, n);
            }
        }
        int result = 0;
        int count = 0;
        for (auto &r : results) {
            if (r.second.first > count) {
                count = r.second.first;
                result = r.second.second;
            } else if (r.second.first == count && r.second.second < result) {
                result = r.second.second;
            }
        }
        return result;
    }
};

class P2453Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2453Test, Test1)
{
    vector<int> nums = { 3,7,8,1,1,5 };
    Solution s;
    auto actual = s.destroyTargets(nums, 2);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}

}
