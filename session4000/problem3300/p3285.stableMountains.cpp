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
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for (int i = 1; i < height.size(); ++i) {
            if (height[i-1] > threshold) ans.push_back(i);
        }
        return ans;
    }
};

class PTest3285 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3285, Test1) {
    Solution s;
    vector<int> height = {1,2,3,4,5};
    int threshold = 2;
    auto actual = s.stableMountains(height, threshold);
    decltype(actual) expect = {3,4};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3285, Test2) {
    Solution s;
    vector<int> height = {10,1,10,1,10};
    int threshold = 3;
    auto actual = s.stableMountains(height, threshold);
    decltype(actual) expect = {1,3};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3285, Test3) {
    Solution s;
    vector<int> height = {10,1,10,1,10};
    int threshold = 10;
    auto actual = s.stableMountains(height, threshold);
    decltype(actual) expect = {};
    EXPECT_EQ(expect, actual);
}
}


