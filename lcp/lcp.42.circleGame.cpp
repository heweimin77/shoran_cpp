#include <gtest/gtest.h>
#include <unordered_set>

using namespace std;

namespace {

class Solution {
#define MAKE_POS(x, y) (((unsigned long long)(x) << 32) | (unsigned long long)(y))
public:
    int circleGame(vector<vector<int>> &toys, vector<vector<int>> &circles, int r)
    {
        unordered_set<unsigned long long> visited;
        for (auto &c : circles) {
            visited.insert(MAKE_POS(c[0], c[1]));
        }
        int result = 0;
        for (auto &t : toys) {
            if (t[2] > r) continue;
            int expect = r - t[2];
            bool ok = false;
            for (int dx = 0; dx <= expect && !ok; ++dx) {
                for (int dy = 0; dy <= expect && !ok; ++dy) {
                    if (dx * dx + dy * dy > expect * expect) break;
                    unsigned long long ps[] = {
                        MAKE_POS(t[0] + dx, t[1] + dy),
                        MAKE_POS(t[0] + dx, t[1] - dy),
                        MAKE_POS(t[0] - dx, t[1] + dy),
                        MAKE_POS(t[0] - dx, t[1] - dy)
                    };
                    for (auto &p : ps) {
                        if (visited.count(p)) {
                            ok = true;
                            break;
                        }
                    }
                }
            }
            if (ok) ++result;
        }

        return result;
    }
};

class Lcp42Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(Lcp42Test, TestMain)
{
    vector<vector<int>> toys = {{3, 3, 1}, {3, 2, 1}};
    vector<vector<int>> circles = {{4, 3}};
    Solution s;
    auto actual = s.circleGame(toys, circles, 2);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}

}
