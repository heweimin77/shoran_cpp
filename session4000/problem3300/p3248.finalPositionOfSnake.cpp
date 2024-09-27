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
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for (auto &s : commands) {
            switch (s[0]) {
                case 'U': --y; break;
                case 'D': ++y; break;
                case 'L': --x; break;
                case 'R': ++x; break;
            }
        }
        return x  + y * n;
    }
};

class PTest3248 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3248, Test1) {
    Solution s;
    int n = 2;
    vector<string> commands = {"RIGHT","DOWN"};
    auto actual = s.finalPositionOfSnake(n, commands);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3248, Test2) {
    Solution s;
    int n = 3;
    vector<string> commands = {"DOWN","RIGHT","UP"};
    auto actual = s.finalPositionOfSnake(n, commands);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}


