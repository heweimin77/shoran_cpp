#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        constexpr int MOD = 1e9 + 7;
        int d = abs(startPos - endPos);
        if (d > k) return 0;
        d = k - d;
        if (d & 1) return 0;
        d >>= 1;
        
        vector<int> results(d + 1);
        vector<int> nexts(d + 1);
        results[0] = nexts[0] = 1;
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= i && j <= d; ++j) {
                nexts[j] = (results[j] + results[j - 1]) % MOD;
                //cout << nexts[j] << " ";
            }
            results.swap(nexts);
            //cout << endl;
        }
        return results[d];
    }
};

class P2400Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2400Test, Test1)
{
    Solution s;
    auto actual = s.numberOfWays(989, 1000, 99);
    decltype(actual) expect = 934081896;
    EXPECT_EQ(expect, actual);
}

}
