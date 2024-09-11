#include <gtest/gtest.h>
#include <unordered_set>

using namespace std;


namespace {

class Solution {
public:
    int distinctPrimeFactors(vector<int> &nums)
    {
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        unordered_set<int> pfactors;
        for (auto n : nums) {
            for (int *p = primes; p < primes + sizeof(primes) / sizeof(int) && n > *p; ++p) {
                if (n % *p == 0) {
                    pfactors.insert(*p);
                    while (n % *p == 0) n /= *p;
                }
            }
            if (n > 1) {
                pfactors.insert(n);
            }
        }
        return pfactors.size();

    }
};

class P2521Test :public testing::Test {
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2521Test, Test1)
{
    vector<int> nums = { 2,4,3,7,10,6 };
    Solution s;
    auto actual = s.distinctPrimeFactors(nums);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}

}

