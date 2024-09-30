#include <gtest/gtest.h>
#include "DictTree.h"
#include <unordered_set>
#include "StringHash.h"

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
    int minValidStrings(vector<string>& words, string target) {
        int BASE = 26, MOD = 1e9 + 7;
        //int BASE = 100, MOD = 1e8;
        StringHash sh(BASE, MOD);
        std::vector<int> prehash = sh.get_prehash(target);

        int max_len = 0;
        for (auto &w : words) max_len = max(max_len, (int)w.size());
        vector<unordered_set<int>> sets(max_len);
        for (auto &w : words) {
            long long h = 0;
            for (int j = 0; j < w.size(); ++j) {
                h = (h * BASE + w[j] - 'a') % MOD;
                sets[j].insert(h);
            }
        }

        int now = 0, limit = 1, nlimit = 1, ans = 0, n = target.size();
        while (now < limit) {
            ++ans;
            while (now < limit) {
                int low = 1, high = min(n - now, max_len) + 1;
                while (low < high) {
                    int mid = (low + high) / 2;
                    int hash = sh.get_hash(prehash, now, now + mid);
                    if (sets[mid-1].contains(hash)) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                }
                nlimit = max(nlimit, now + low);
                if (nlimit > n) return ans;
                ++now;
            }
            limit = nlimit;
        }
        return -1;
    }
};

class PTest3292 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3292, Test1) {
    Solution s;
    vector<string> words = {"abc","aaaaa","bcdef"};
    string target = "aabcdabc";
    auto actual = s.minValidStrings(words, target);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3292, Test2) {
    Solution s;
    vector<string> words = {"abababab","ab"};
    string target = "ababaababa";
    auto actual = s.minValidStrings(words, target);
    decltype(actual) expect = 2;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3292, Test3) {
    Solution s;
    vector<string> words = {"abcdef"};
    string target = "xyz";
    auto actual = s.minValidStrings(words, target);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
}


