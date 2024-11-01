#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

namespace {
static auto autorun = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();
class Solution {
#define MAKE_KEY(x,y) (((long long)x << 32) | (y))
#define GET_X(key) ((key) >> 32)
#define GET_Y(key) ((key) & 0xFFFFFFFF)
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        unordered_map<long long, int> results;
        results[MAKE_KEY(0L, 0xFFFFFFFF)] = 0;
        auto addnexts = [](unordered_map<long long, int> &nexts, int x, int y, int value) {
            long long key = MAKE_KEY(x, y);
            auto it = nexts.find(key);
            if (it == nexts.end()) {
                nexts.insert({key, value});
            } else {
                it->second = min(it->second, value);
            }
        };
        int lastn = 0;
        for (auto n : nums) {
            unordered_map<long long, int> nexts;
            for (auto &[key, value]: results) {
                long long x = GET_X(key), y = GET_Y(key);
                int ny = y & n;
                if ((ny & andValues[x]) == andValues[x]) {
                    addnexts(nexts, x, ny, value);
                }
                if (y == andValues[x] && x + 1 < andValues.size()) {
                    addnexts(nexts, x + 1, n, value + lastn);
                }
            }
            results = std::move(nexts);
            lastn = n;
        }
        long long key = MAKE_KEY(andValues.size()-1, andValues.back());
        auto it = results.find(key);
        return it == results.end() ? -1 : it->second + nums.back();
    }
};

class PTest3117 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3117, Test1) {
    Solution s;
    vector<int> nums = {1,4,3,3,2};
    vector<int> andValues = {0,3,3,2};
    auto actual = s.minimumValueSum(nums, andValues);
    decltype(actual) expect = 12;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3117, Test2) {
    Solution s;
    vector<int> nums = {2,3,5,7,7,7,5};
    vector<int> andValues = {0,7,5};
    auto actual = s.minimumValueSum(nums, andValues);
    decltype(actual) expect = 17;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3117, Test3) {
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> andValues = {2};
    auto actual = s.minimumValueSum(nums, andValues);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
}


