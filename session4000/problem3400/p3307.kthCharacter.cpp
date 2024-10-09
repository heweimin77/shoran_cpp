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
    char kthCharacter(long long k, vector<int>& operations) {
        long long base = 1;
        vector<long long> bases = {base};
        while (base <= k) {
            base += base;
            bases.push_back(base);
        }
        function<int(long long)> get_opnums = [&](long long n) {
            if (n == 0) return 0;
            auto it = upper_bound(bases.begin(), bases.end(), n);
            --it;
            return get_opnums(n - *it) + operations[it - bases.begin()];
        };

        return 'a' + get_opnums(k - 1) % 26;
    }
};

class PTest3307 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3307, Test1) {
    Solution s;
    long long k = 5;
    vector<int> operations = {0,0,0};
    auto actual = s.kthCharacter(k, operations);
    decltype(actual) expect = 'a';
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3307, Test2) {
    Solution s;
    long long k = 10;
    vector<int> operations = {0,1,0,1};
    auto actual = s.kthCharacter(k, operations);
    decltype(actual) expect = 'b';
    EXPECT_EQ(expect, actual);
}
}


