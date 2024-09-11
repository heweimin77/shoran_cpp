#include <gtest/gtest.h>

using namespace std;


namespace {

class Solution {
public:
    int minimumPartition(string s, int k)
    {
        int n = s.size();
        if (k < 10) {
            char cc = '0' + k;
            for (auto c : s) {
                if (c > cc) return -1;
            }
            return n;
        }
        string x = to_string(k);
        int result = 0;
        int i = 0;
        for (i = 0; i < n; ++result) {
            int j = i + x.size();
            if (j <= n) {
                if (lexicographical_compare(x.begin(), x.end(), s.begin() + i, s.begin() + j)) {
                    --j;
                }
            }
            i = j;
        }

        return result;
    }
};

class P2522Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2522Test, Test1)
{
    vector<int> nums = { 2,4,3,7,10,6 };
    Solution s;
    auto actual = s.minimumPartition("165462", 5);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}

}

