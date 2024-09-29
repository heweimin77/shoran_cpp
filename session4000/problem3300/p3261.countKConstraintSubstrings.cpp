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
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int count0 = 0, count1 = 0;
        int n = s.size(), j = 0;
        vector<int> right(n);
        for (int i = 0; i < n; ++i) {
            while (j < n and (count0 <= k or count1 <= k)) {
                if (s[j] == '0') count0 += 1;
                else count1 += 1;
                ++j;
            }
            right[i] += j;
            if (count0 > k && count1 > k) --right[i];
            if (s[i] == '0') --count0;
            else --count1;
        }

        vector<long long> sums(n);
        sums[0] = right[0];
        for (int i = 1; i <n; ++i)
            sums[i] = sums[i-1] + right[i] - i;
        auto get_queries = [&](long long l, long long r) {
            int x = upper_bound(right.begin(), right.end(), r) - right.begin();
            if (x <= l)
                return (r - l + 1) * (r + 2 - l) / 2;
            else
                return (r - x + 1) * (r + 2 - x) / 2 + sums[x-1] - (l > 0 ? sums[l-1] : 0);
        };

        vector<long long> answers;
        for (auto &q : queries)
            answers.push_back(get_queries(q[0], q[1]));
        return answers;
    }
};

class PTest3261 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3261, Test1) {
    Solution s;
    string ss = "0001111";
    int k = 2;
    vector<vector<int>>queries = {{0, 6}};
    auto actual = s.countKConstraintSubstrings(ss, k, queries);
    decltype(actual) expect = {26};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3261, Test2) {
    Solution s;
    string ss = "010101";
    int k = 1;
    vector<vector<int>>queries = {{0,5},{1,4},{2,3}};
    auto actual = s.countKConstraintSubstrings(ss, k, queries);
    decltype(actual) expect = {15,9,3};
    EXPECT_EQ(expect, actual);
}
}


