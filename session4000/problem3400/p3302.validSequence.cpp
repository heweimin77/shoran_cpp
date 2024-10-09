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
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> indexes[26];
        for (int i = 0; i < m; ++i) {
            indexes[word1[i]-'a'].push_back(i);
        }
        vector<int> lastindex(n, -1);
        int x = m;
        for (int j = n -1; j >= 0; --j) {
            vector<int> &index = indexes[word2[j]-'a'];
            int xi = lower_bound(index.begin(), index.end(), x) - index.begin();
            if (xi == 0) break;
            x = lastindex[j] = index[xi-1];
        }

        vector<int> ans(n);
        int j = 0;
        for (int i = 0; i < m; ++i) {
            if (word1[i] == word2[j] || j == n - 1) {
                ans[j++] = i;
                if (j == n) return ans;
            } else {
                if (lastindex[j+1] > i) {
                    ans[j] = i;
                    for (int k = j + 1; k < n; ++k) {
                        auto &index = indexes[word2[k] - 'a'];
                        int xi = upper_bound(index.begin(), index.end(), ans[k-1]) - index.begin();
                        ans[k] = index[xi];
                    }
                    return ans;
                }
            }
        }
        return {};
    }
};

class PTest3302 : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3302, Test1) {
    Solution s;
    auto actual = s.validSequence("vbcca", "abc");
    decltype(actual) expect = {0,1,2};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3302, Test2) {
    Solution s;
    auto actual = s.validSequence("bacdc", "abc");
    decltype(actual) expect = {1,2,4};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3302, Test3) {
    Solution s;
    auto actual = s.validSequence("aaaaaa", "aaabc");
    decltype(actual) expect = {};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3302, Test4) {
    Solution s;
    auto actual = s.validSequence("abc", "ab");
    decltype(actual) expect = {0, 1};
    EXPECT_EQ(expect, actual);
}
}


