#include <gtest/gtest.h>

using namespace std;

namespace {

    class Solution {
    public:
        int minMaxDifference(int num) {
            int r = 0;
            int bases[16] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
            char data[16];
            int cnt = 0;
            while (num > 0) {
                data[cnt++] = num % 10;
                num /= 10;
            }
            char x = data[cnt - 1];
            for (int i = 0; i < cnt; ++i) {
                if (data[i] == x) {
                    r += x * bases[i];
                }
            }
            x = 9;
            for (int i = cnt - 1; i >= 0; --i) {
                if (data[i] != 9) {
                    x = data[i];
                    break;
                }
            }
            if (x != 9) {
                for (int i = 0; i < cnt; ++i) {
                    if (data[i] == x) {
                        r += (9 - x) * bases[i];
                    }
                }
            }
            return r;
        }
    };

    class P2566Test :public testing::Test
    {
    public:
        virtual void SetUp()
        {
        }
        virtual void TearDown()
        {
        }
    };


    TEST_F(P2566Test, Test1)
    {
        Solution s;
        auto actual = s.minMaxDifference(11891);
        decltype(actual) expect = 99009;
        EXPECT_EQ(expect, actual);
    }
}

