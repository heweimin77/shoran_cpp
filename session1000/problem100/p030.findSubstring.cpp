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
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> indexes;
        vector<int> counts;
        for (auto &w : words) {
            if (indexes.find(w) == indexes.end()) {
                indexes[w] = indexes.size();
                counts.push_back(1);
            } else {
                ++counts[indexes[w]];
            }
        }
        int n = s.size(), k = words[0].size(), m = words.size();
        if (n < k) return {};
        vector<int> matched(n - k + 1, -1);
        for (int i = 0; i < matched.size(); ++i) {
            auto it = indexes.find(s.substr(i, k));
            if (it != indexes.end()) {
                matched[i] = it->second;
            }
        }

        vector<int> ans = {};
        for (int i = 0; i < k; ++i) {
            if (i + k * m > s.size()) break;
            auto cnts = counts;
            int cnt = cnts.size();
            for (int j = i; j < i + (m - 1) * k; j += k) {
                if (matched[j] >= 0) {
                    if (--cnts[matched[j]] == 0) --cnt;
                }
            }
            for (int j = i + (m - 1) * k, jj = i; j < matched.size(); j += k, jj += k) {
                if (matched[j] >= 0) {
                    if (--cnts[matched[j]] == 0) --cnt;
                }
                if (cnt == 0) ans.push_back(jj);
                if (matched[jj] >= 0) {
                    if (++cnts[matched[jj]] == 1)  ++cnt;
                }
            }
        }
        return ans;
    }
};

class P030Test : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P030Test, Test1) {
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    auto actual = solution.findSubstring(s, words);
    decltype(actual) expect = {0, 9};
    EXPECT_EQ(expect, actual);
}
TEST_F(P030Test, Test2) {
    Solution solution;
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","word"};
    auto actual = solution.findSubstring(s, words);
    decltype(actual) expect = {};
    EXPECT_EQ(expect, actual);
}
TEST_F(P030Test, Test3) {
    Solution solution;
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    auto actual = solution.findSubstring(s, words);
    decltype(actual) expect = {6,9,12};
    EXPECT_EQ(expect, actual);
}
TEST_F(P030Test, Test4) {
    Solution solution;
    string s = "b";
    vector<string> words = {"bbb","bbb"};
    auto actual = solution.findSubstring(s, words);
    decltype(actual) expect = {};
    EXPECT_EQ(expect, actual);
}
}


