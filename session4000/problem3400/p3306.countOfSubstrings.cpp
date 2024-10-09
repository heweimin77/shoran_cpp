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
    long long countOfSubstrings(string word, int k) {
        vector<vector<int>> ws;
        int j = 0;
        unordered_map<char, int> vowels = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        ws.push_back({});
        for (int i = 0; i < word.size(); ++i) {
            auto it = vowels.find(word[i]);
            if (it == vowels.end()) {
                ws.push_back({});
                j = i + 1;
            } else {
                ws.back().push_back(it->second);
            }
        }
        vector<array<int,5>> sums;
        if (k > 0) {
            array<int,5> counts;
            sums.push_back(counts);
            for (auto w : ws) {
                for (auto i : w) {
                    ++counts[i];
                }
                sums.push_back(counts);
            }
        }

        auto getcount0 = [&](const vector<int> &w) {
            int cnts[5] = {-1, -1, -1, -1, -1};
            int cnt = 5;
            long long ans = 0, j = 0;
            for (auto x : w) {
                if (++cnts[x] == 0) --cnt;
                for (; cnt == 0; ++j) {
                    if (--cnts[w[j]] < 0) ++cnt;
                }
                ans += j;
            }
            return ans;
        };

        auto getcount = [&](const vector<int> & left, const vector<int> & right, int first, int last) {
            int cnts[5];
            int cnt = 0;
            for (int i = 0; i < 5; ++i) {
                cnts[i] = sums[last][i] - sums[first][i] - 1;
                if (cnts[i] < 0) ++cnt;
            }

            int j = 0;
            for (; j < left.size() && cnt == 0; ++j) {
                if (--cnts[left[j]] < 0) ++cnt;
            }
            long long ans = j;
            if (cnt == 0) ++ans;
            for (auto x : right) {
                if (++cnts[x] == 0) --cnt;
                for (; j < left.size() && cnt == 0; ++j) {
                    if (--cnts[left[j]] < 0) ++cnt;
                }
                ans += j;
                if (cnt == 0) ++ans;
            }
            return ans;
        };

        long long ans = 0;
        if (k == 0) {
            for (auto &w : ws) {
                ans += getcount0(w);
            }

        } else {
            for (int i = 0; i < (int)ws.size() - k; ++i) {
                ans += getcount(ws[i], ws[i+k], i, i + k);
            }
        }
        return ans;
    }
};

class PTest3306 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3306, Test1) {
    Solution s;
    auto actual = s.countOfSubstrings("aeioqq", 1);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3306, Test2) {
    Solution s;
    auto actual = s.countOfSubstrings("aeiou", 0);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3306, Test3) {
    Solution s;
    auto actual = s.countOfSubstrings("ieaouqqieaouqq", 1);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3306, Test4) {
    Solution s;
    auto actual = s.countOfSubstrings("iqeaouqi", 2);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3306, Test5) {
    Solution s;
    auto actual = s.countOfSubstrings("eoeiaua", 2);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3306, Test6) {
    Solution s;
    auto actual = s.countOfSubstrings("aaeuoiouee", 0);
    decltype(actual) expect = 10;
    EXPECT_EQ(expect, actual);
}
}


