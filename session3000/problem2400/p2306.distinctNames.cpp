#include <gtest/gtest.h>
#include <unordered_set>

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
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> groups[26];
        for (auto &idea: ideas) {
            groups[idea[0] - 'a'].insert(idea.substr(1));
        }
        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (groups[i].empty()) continue;
            for (int j = i + 1; j < 26; ++j) {
                if (groups[j].empty()) continue;
                int cnt = 0;
                for (auto &x : groups[j]) {
                    if (groups[i].count(x) > 0) {
                        ++cnt;
                    }
                }
                ans += (long long)(groups[i].size() - cnt) * (groups[j].size() - cnt);
            }
        }
        return ans << 1;
    }

    long long distinctNames2(vector<string>& ideas) {
        unordered_set<string> ideaset(ideas.begin(), ideas.end());
        int valid_index[26] = {0};
        for (auto &idea : ideas) {
            valid_index[idea[0]-'a'] = 1;
        }
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (valid_index[i]) valid_index[count++] = i;
        }
        vector<vector<int>> indexes;
        for (auto idea: ideas) {
            indexes.push_back({});
            vector<int> &indexs = indexes.back();
            for (int i = 0; i < count; ++i) {
                idea[0] = 'a' + valid_index[i];
                if (ideaset.count(idea) == 0) {
                    indexs.push_back(valid_index[i]);
                }
            }
        }

        int results[26][26];
        memset(results, 0, sizeof(results));
        for (int i = 0; i < ideas.size(); ++i) {
            int ii = ideas[i][0] - 'a';
            for (int index : indexes[i]) {
                ++results[ii][index];
            }
        }
        long long ans = 0;
        for (int i = 0; i < ideas.size(); ++i) {
            int ii = ideas[i][0] - 'a';
            for (int index : indexes[i]) {
                ans += results[index][ii];
            }
        }
        return ans;
    }
};

class P2306Test : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P2306Test, Test1) {
    Solution s;
    vector<string> ideas = {"coffee","donuts","time","toffee"};
    auto actual = s.distinctNames(ideas);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2306Test, Test2) {
    Solution s;
    vector<string> ideas = {"lack","back"};
    auto actual = s.distinctNames(ideas);
    decltype(actual) expect = 0;
    EXPECT_EQ(expect, actual);
}
}


