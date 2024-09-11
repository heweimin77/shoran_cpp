#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    string convertDateToBinary(const string &date) {
        auto convert = [&](int r) {
            string s;
            while (r > 0) {
                s += '0' + (r & 1);
                r >>= 1;
            }
            std::reverse(s.begin(), s.end());
            return s;
        };

        string ans;
        int r = 0;
        for (auto x : date) {
            if ('0' <= x && x <= '9') {
                r *= 10;
                r += x - '0';
            } else {
                ans += convert(r);
                r = 0;
                ans += x;
            }
        }
        ans += convert(r);
        return ans;
    }
};
class P3180Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3180Test, Test1)
{
    Solution s;
    string date = "2080-02-29";
    auto actual = s.convertDateToBinary(date);
    decltype(actual) expect = "100000100000-10-11101";
    EXPECT_EQ(expect, actual);
}
TEST_F(P3180Test, Test2)
{
    Solution s;
    string date = "1900-01-01";
    auto actual = s.convertDateToBinary(date);
    decltype(actual) expect = "11101101100-1-1";
    EXPECT_EQ(expect, actual);
}
}


