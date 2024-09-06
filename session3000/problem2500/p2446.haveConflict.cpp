#include <gtest/gtest.h>

using namespace std;

namespace {

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start1 = getTime(event1[0]);
        int end1 = getTime(event1[1]);
        int start2 = getTime(event2[0]);
        int end2 = getTime(event2[1]);

        return start1 <= end2 && start2 <= end1;
    }
    int getTime(const string& event) {
        int hour = 10 * (event[0] - '0') + (event[1] - '0');
        int minute = 10 * (event[3] - '0') + (event[4] - '0');
        return hour * 60 + minute;
    }
};

class P2446Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P2446Test, TestMain)
{
    vector<string> event1 = { "01:15","02:00" };
    vector<string> event2 = { "02:00","03:00" };
    Solution s;
    auto actual = s.haveConflict(event1, event2);
    decltype(actual) expect = true;
    EXPECT_EQ(expect, actual);
}
}

