#include <gtest/gtest.h>
#include <numeric>

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
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        for (int i = 0; i < n; ++i) health[i] = (health[i] + power - 1) / power;
        vector<int> indexes(n);
        for (int i = 0; i < n; ++i) indexes[i] = i;
        sort(indexes.begin(), indexes.end(), [&](int l, int r) {
           return health[l] * damage[r] < health[r] * damage[l];
        });
        long long ans = 0;
        long long total = accumulate(damage.begin(), damage.end(), 0LL);
        for (int i : indexes) {
            ans += total * health[i];
            total -= damage[i];
        }
        return ans;
    }
};

class PTest3273 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3273, Test1) {
    Solution s;
    int power = 4;
    vector<int> damage = {1,2,3,4};
    vector<int> health = {4,5,6,8};
    auto actual = s.minDamage(power, damage, health);
    decltype(actual) expect = 39;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3273, Test2) {
    Solution s;
    int power = 1;
    vector<int> damage = {1,1,1,1};
    vector<int> health = {1,2,3,4};
    auto actual = s.minDamage(power, damage, health);
    decltype(actual) expect = 20;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3273, Test3) {
    Solution s;
    int power = 8;
    vector<int> damage = {40};
    vector<int> health = {59};
    auto actual = s.minDamage(power, damage, health);
    decltype(actual) expect = 320;
    EXPECT_EQ(expect, actual);
}
}


