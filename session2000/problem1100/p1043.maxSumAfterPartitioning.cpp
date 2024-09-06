#include <gtest/gtest.h>
#include <climits>

using namespace std;

namespace {

class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        vector<int> results(arr.size());
        int i = 0;
        int ma = INT_MIN;
        for (; i < k; ++i) {
            ma = max(ma, arr[i]);
            results[i] = ma * (i + 1);
        }

        for (; i < results.size(); ++i) {
            int r = arr[i] + results[i - 1];
            int ma = arr[i];
            for (int j = i - 1; j > i - k; --j) {
                ma = max(ma, arr[j]);
                r = max(r, ma * (i - j + 1) + results[j - 1]);
            }
            results[i] = r;
        }
        return results.back();
    }
};

class P1043Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P1043Test, Test1)
{
    vector<int> arr = { 1,15,7,9,2,5,10 };
    Solution s;
    auto actual = s.maxSumAfterPartitioning(arr, 3);
    decltype(actual) expect = 84;
    EXPECT_EQ(expect, actual);
}

}
