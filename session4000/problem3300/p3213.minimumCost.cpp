#include <gtest/gtest.h>
#include <unordered_set>
#include "DictTree.h"
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
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = target.length();
        const int MOD = 1'070'777'777;
        const int BASE = 26;
        StringHash sh(BASE, MOD);
        unordered_map<int, unordered_map<int, int>> lenwords;
        for (int i = 0; i < words.size(); ++i) {
            auto &w = words[i];
            auto &lenword = lenwords[w.size()];
            auto hash = sh.hash(w, 0, w.size());
            auto it = lenword.find(hash);
            if (it == lenword.end()) {
                lenword.insert({hash, costs[i]});
            } else {
                it->second = min(it->second, costs[i]);
            }
        }

        vector<int> prehash = sh.get_prehash(target);
        vector<int> answers(n + 1, INT_MAX);
        answers[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (auto &[len, hashcost]: lenwords) {
                if (i >= len && answers[i - len] != INT_MAX) {
                    auto hash = sh.get_hash(prehash, i - len, i);
                    if (hashcost.contains(hash)) {
                        answers[i] = min(answers[i], answers[i - len] + hashcost[hash]);
                    }
                }
            }
        }

        return answers[n] == INT_MAX ? -1 : answers[n];
    }

    int minimumCost2(string target, vector<string>& words, vector<int>& costs) {
        int n = target.length();

        // 多项式字符串哈希（方便计算子串哈希值）
        // 哈希函数 hash(s) = s[0] * base^(n-1) + s[1] * base^(n-2) + ... + s[n-2] * base + s[n-1]
        const int MOD = 1'070'777'777;
        const int BASE = 26;
        vector<int> pow_base(n + 1); // pow_base[i] = base^i
        vector<int> pre_hash(n + 1); // 前缀哈希值 pre_hash[i] = hash(s[:i])
        pow_base[0] = 1;
        for (int i = 0; i < n; i++) {
            pow_base[i + 1] = (long long) pow_base[i] * BASE % MOD;
            pre_hash[i + 1] = ((long long) pre_hash[i] * BASE + target[i] - 'a') % MOD; // 秦九韶算法计算多项式哈希
        }

        // 计算 target[l] 到 target[r-1] 的哈希值
        auto sub_hash = [&](int l, int r) {
            return ((pre_hash[r] - (long long) pre_hash[l] * pow_base[r - l]) % MOD + MOD) % MOD;
        };

        map<int, unordered_map<int, int>> min_cost; // 长度 -> 哈希值 -> 最小成本
        for (int i = 0; i < words.size(); i++) {
            long long h = 0;
            for (char b : words[i]) {
                h = (h * BASE + b - 'a') % MOD;
            }
            int m = words[i].length();
            if (!min_cost[m].contains(h)) {
                min_cost[m][h] = costs[i];
            } else {
                min_cost[m][h] = min(min_cost[m][h], costs[i]);
            }
        }

        vector<int> f(n + 1, INT_MAX / 2);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (auto& [len, mc] : min_cost) {
                if (len > i) {
                    break;
                }
                auto it = mc.find(sub_hash(i - len, i));
                if (it != mc.end()) {
                    f[i] = min(f[i], f[i - len] + it->second);
                }
            }
        }
        return f[n] == INT_MAX / 2 ? -1 : f[n];
    }
    int minimumCost750of808(string target, vector<string>& words, vector<int>& costs) {
        size_t xn = 0;
        for (auto &w : words) xn = max(xn, w.size());
        StringHash sh(26, 9973);
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


