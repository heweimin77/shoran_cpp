#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

namespace {

    class Solution {
    public:
        int minOperations(int n) {
            int r = 1;
            for (int i = 0; i < 20; ++i) {
                data[i] = r;
                results[r] = 1;
                r <<= 1;
            }
            return getMin(n);
        }
        int getMin(int n) {
            auto it = results.find(n);
            if (it != results.end()) {
                return it->second;
            }
            int* x = upper_bound(data, data + 20, n);
            return results[n] = 1 + min(getMin(n - (*x >> 1)), getMin(*x - n));
        }
    private:
        unordered_map<int, int> results;
        int data[20];
    };

    class P2571Test :public testing::Test
    {
    public:
        virtual void SetUp()
        {
        }
        virtual void TearDown()
        {
        }
    };


    TEST_F(P2571Test, Test1)
    {
        vector<int> para = { 1,4,7,8,5 };
        Solution s;
        auto actual = s.minOperations(39);
        decltype(actual) expect = 3;
        EXPECT_EQ(expect, actual);
    }
}

