#include <gtest/gtest.h>
#include <unordered_set>
#include "DictTree.h"

using namespace std;

namespace {
static auto autorun = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class StringHash {
public:
    using ValueType = long long;
    StringHash(int b, int n, int m) : bbase(n) {
        base = b;
        mod = m;
        int x = 1;
        for (int i = 0; i < bbase.size(); ++i) {
            bbase[i] = x;
            x *= base;
            x %= mod;
        }
    }
    ValueType hash(const std::string &w, int start, int end) {
        int ans = 0;
        for (int i = start; i < end; ++i) {
            ans *= base;
            ans += w[i] - 'a';
            ans %= mod;
        }
        return ans;
    }
    ValueType rehash(long long hash, char add, char del, int n) {
        int a = add - 'a', d = del - 'a';
        hash -= d * bbase[n-1];
        hash *= base;
        hash += a;
        hash %= mod;
        if (hash < 0) hash += mod;
        return hash;
    }

private:
    ValueType base;
    ValueType mod;
    vector<ValueType> bbase;
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        size_t xn = 0;
        for (auto &w : words) xn = max(xn, w.size());
        StringHash sh(26, xn, (int)(10e9 + 7));
        unordered_map<int, unordered_map<long long, int>> lenwords;
        for (int i = 0; i < words.size(); ++i) {
            auto &w = words[i];
            auto &lenword = lenwords[w.size()];
            int hash = sh.hash(w, 0, w.size());
            auto it = lenword.find(hash);
            if (it == lenword.end()) {
                lenword.insert({hash, costs[i]});
            } else {
                it->second = min(it->second, costs[i]);
            }
        }

        int n = target.size();
        vector<vector<pair<int,int>>> nexts(n);
        for (auto &x : lenwords) {
            int len = x.first;
            if (len > target.size()) continue;
            auto hash = sh.hash(target, 0, len);
            auto &wset = lenwords[len];
            auto it = wset.find(hash);
            if (it != wset.end()) {
                nexts[0].push_back({len, it->second});
            }
            for (int i = 0; i + len < n; ++i) {
                hash = sh.rehash(hash, target[i+len], target[i], len);
                auto it = wset.find(hash);
                if (it != wset.end()) {
                    nexts[i+1].push_back({len, it->second});
                }
            }
        }

        vector<int> answers(n + 1, INT_MAX);
        answers[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (answers[i] == INT_MAX) continue;
            for (auto &ns : nexts[i]) {
                int ni = i + ns.first;
                answers[ni] = min(answers[ni], answers[i] + ns.second);
            }
        }
        return answers[n] == INT_MAX ? -1 : answers[n];
    }
    int minimumCost750of808(string target, vector<string>& words, vector<int>& costs) {
        size_t xn = 0;
        for (auto &w : words) xn = max(xn, w.size());
        StringHash sh(26, xn, 9973);
        unordered_map<int, unordered_map<int, unordered_set<string>>> lenwords;
        unordered_map<string, int>  wordcosts;
        for (int i = 0; i < words.size(); ++i) {
            auto &w = words[i];
            int hash = sh.hash(w, 0, w.size());
            lenwords[w.size()][hash].insert(w);
            auto it = wordcosts.find(w);
            if (it == wordcosts.end()) {
                wordcosts[w] = costs[i];
            } else {
                it->second = min(it->second, costs[i]);
            }
        }

        int n = target.size();
        vector<vector<pair<int,int>>> nexts(n);
        for (auto &x : lenwords) {
            int len = x.first;
            if (len > target.size()) continue;
            int hash = sh.hash(target, 0, len);
            unordered_map<int, unordered_set<string>> &wset = lenwords[len];
            auto it = wset.find(hash);
            if (it != wset.end()) {
                string w = target.substr(0, len);
                if (it->second.contains(w)) {
                    nexts[0].push_back({len, wordcosts[w]});
                }
            }
            for (int i = 0; i + len < n; ++i) {
                hash = sh.rehash(hash, target[i+len], target[i], len);
                auto it = wset.find(hash);
                if (it != wset.end()) {
                    string w = target.substr(i+1, len);
                    if (it->second.contains(w)) {
                        nexts[i+1].push_back({len, wordcosts[w]});
                    }
                }
            }
        }

        vector<int> answers(n + 1, INT_MAX);
        answers[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (answers[i] == INT_MAX) continue;
            for (auto &ns : nexts[i]) {
                int ni = i + ns.first;
                answers[ni] = min(answers[ni], answers[i] + ns.second);
            }
        }
        return answers[n] == INT_MAX ? -1 : answers[n];
    }
};

class Solution803of808 {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        DictTree dtree;
        for (int i = 0; i < words.size(); ++i) dtree.add(words[i], costs[i]);

        int n = target.size();
        vector<int> answers(n + 1, -1);
        answers[0] = 0;
        for (int i = 0; i <= n; ++i) {
            if (answers[i] == -1) continue;
            vector<pair<int,int>> nexts = dtree.match(target.begin() + i, target.end());
            for (auto& nv : nexts) {
                int next = nv.first + i;
                if (answers[next] == -1) {
                    answers[next] = answers[i] + nv.second;
                } else {
                    answers[next] = min(answers[i] + nv.second, answers[next]);
                }
            }
        }
        return answers[n];
    }
};
class Solution713of808 {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = target.size();
        vector<int> answers(n + 1, -1);
        answers[0] = 0;
        for (int i = 0; i <= n; ++i) {
            if (answers[i] == -1) continue;
            for (int j = 0; j < words.size(); ++j) {
                auto &w = words[j];
                if (n - i >= w.size() && equal(w.begin(), w.end(), target.begin() + i)) {
                    int next = i + w.size();
                    if (answers[next] == -1) {
                        answers[next] = answers[i] + costs[j];
                    } else {
                        answers[next] = min(answers[i] + costs[j], answers[next]);
                    }
                }
            }
        }
        return answers[n];
    }
};

class PTest3213 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3213, Test1) {
    Solution s;
    string target = "abcdef";
    vector<string> words = {"abdef","abc","d","def","ef"};
    vector<int> costs = {100,1,1,10,5};
    auto actual = s.minimumCost(target, words, costs);
    decltype(actual) expect = 7;
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3213, Test2) {
    Solution s;
    string target = "aaaa";
    vector<string> words = {"z","zz","zzz"};
    vector<int> costs = {1,10,100};
    auto actual = s.minimumCost(target, words, costs);
    decltype(actual) expect = -1;
    EXPECT_EQ(expect, actual);
}
}


