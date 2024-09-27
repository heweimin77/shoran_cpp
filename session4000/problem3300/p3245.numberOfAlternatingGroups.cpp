#include <gtest/gtest.h>
#include "TreeArray.h"

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
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();

        // 树状数组模板开始

        // tree1 用来维护小于等于 s 的 l_i 有几个
        // tree2 用来维护小于等于 s 的 l_i 的总和
        TreeArray ta1(n), ta2(n);

        // k = 1 表示往结束点 set 里加入新结束点 pos
        // k = -1 表示从结束点 set 里删除结束点 pos
        // L 和 R 是 pos 左边和右边最近的其它结束点
        auto update = [&](int L, int R, int pos, int k) {
            int old = (R - L + n) % n;
            if (old == 0) old = n;
            ta1.add(old, -k); ta2.add(old, -k * old);

            int len = (pos - L + n) % n;
            if (len == 0) len = n;
            ta1.add(len, k); ta2.add(len, k * len);
            len = (R - pos + n) % n;
            if (len == 0) len = n;
            ta1.add(len, k); ta2.add(len, k * len);
        };

        set<int> st;

        // 往结束点 set 里加入新结束点 pos
        auto ins = [&](int pos) {
            if (st.empty()) {
                st.insert(pos);
                ta1.add(n, 1); ta2.add(n, n);
            } else {
                auto it = st.insert(pos).first;
                // 找到左右两个最近的其它结束点
                int L = (it == st.begin() ? *prev(st.end()) : *prev(it));
                int R = (next(it) == st.end() ? *(st.begin()) : *next(it));
                update(L, R, pos, 1);
            }
        };

        // 从结束点 set 里删除结束点 pos
        auto del = [&](int pos) {
            if (st.size() == 1) {
                st.erase(st.find(pos));
                ta1.add(n, -1); ta2.add( n, -n);
            } else {
                auto it = st.erase(st.find(pos));
                // 找到左右两个最近的其它结束点
                int L = (it == st.begin() ? *prev(st.end()) : *prev(it));
                int R = (it == st.end() ? *(st.begin()) : *it);
                update(L, R, pos, -1);
            }
        };

        for (int i = 0; i < n; i++) if (colors[i] == colors[(i + 1) % n]) ins(i);

        vector<int> ans;
        for (auto &qry : queries) {
            if (qry[0] == 1) {
                if (st.empty()) ans.push_back(n);
                else {
                    // 因为树状数组维护的是小于等于 s 的总和
                    // 要求大于等于 s 的总和，可以转为“所有元素之和，减去小于等于 s - 1 的总和”
                    int sm = ta2.query( n) - ta2.query( qry[1] - 1);
                    int cnt = ta1.query( n) - ta1.query(qry[1] - 1);
                    ans.push_back(sm - cnt * qry[1] + cnt);
                }
            } else {
                // 修改 idx 的颜色，只影响 idx - 1 和 idx 是否成为结束点
                int idx = qry[1], col = qry[2];
                int prv = (idx - 1 + n) % n, nxt = (idx + 1) % n;
                // 回撤旧情况
                if (colors[prv] == colors[idx]) del(prv);
                if (colors[idx] == colors[nxt]) del(idx);
                // 计算新情况
                colors[idx] = col;
                if (colors[prv] == colors[idx]) ins(prv);
                if (colors[idx] == colors[nxt]) ins(idx);
            }
        }
        return ans;
    }
};
class Solution2 {
public:
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();

        // 树状数组模板开始

        // tree1 用来维护小于等于 s 的 l_i 有几个
        // tree2 用来维护小于等于 s 的 l_i 的总和
        int tree1[n + 1], tree2[n + 1];
        memset(tree1, 0, sizeof(tree1)); memset(tree2, 0, sizeof(tree2));

        auto lb = [&](int x) { return x & (-x); };

        auto add = [&](int *tree, int pos, int val) {
            for (; pos <= n; pos += lb(pos)) tree[pos] += val;
        };

        auto query = [&](int *tree, int pos) {
            int ret = 0;
            for (; pos; pos -= lb(pos)) ret += tree[pos];
            return ret;
        };

        // 树状数组模板结束

        // k = 1 表示往结束点 set 里加入新结束点 pos
        // k = -1 表示从结束点 set 里删除结束点 pos
        // L 和 R 是 pos 左边和右边最近的其它结束点
        auto update = [&](int L, int R, int pos, int k) {
            int old = (R - L + n) % n;
            if (old == 0) old = n;
            add(tree1, old, -k); add(tree2, old, -k * old);

            int len = (pos - L + n) % n;
            if (len == 0) len = n;
            add(tree1, len, k); add(tree2, len, k * len);
            len = (R - pos + n) % n;
            if (len == 0) len = n;
            add(tree1, len, k); add(tree2, len, k * len);
        };

        set<int> st;

        // 往结束点 set 里加入新结束点 pos
        auto ins = [&](int pos) {
            if (st.empty()) {
                st.insert(pos);
                add(tree1, n, 1); add(tree2, n, n);
            } else {
                auto it = st.insert(pos).first;
                // 找到左右两个最近的其它结束点
                int L = (it == st.begin() ? *prev(st.end()) : *prev(it));
                int R = (next(it) == st.end() ? *(st.begin()) : *next(it));
                update(L, R, pos, 1);
            }
        };

        // 从结束点 set 里删除结束点 pos
        auto del = [&](int pos) {
            if (st.size() == 1) {
                st.erase(st.find(pos));
                add(tree1, n, -1); add(tree2, n, -n);
            } else {
                auto it = st.erase(st.find(pos));
                // 找到左右两个最近的其它结束点
                int L = (it == st.begin() ? *prev(st.end()) : *prev(it));
                int R = (it == st.end() ? *(st.begin()) : *it);
                update(L, R, pos, -1);
            }
        };

        for (int i = 0; i < n; i++) if (colors[i] == colors[(i + 1) % n]) ins(i);

        vector<int> ans;
        for (auto &qry : queries) {
            if (qry[0] == 1) {
                if (st.empty()) ans.push_back(n);
                else {
                    // 因为树状数组维护的是小于等于 s 的总和
                    // 要求大于等于 s 的总和，可以转为“所有元素之和，减去小于等于 s - 1 的总和”
                    int sm = query(tree2, n) - query(tree2, qry[1] - 1);
                    int cnt = query(tree1, n) - query(tree1, qry[1] - 1);
                    ans.push_back(sm - cnt * qry[1] + cnt);
                }
            } else {
                // 修改 idx 的颜色，只影响 idx - 1 和 idx 是否成为结束点
                int idx = qry[1], col = qry[2];
                int prv = (idx - 1 + n) % n, nxt = (idx + 1) % n;
                // 回撤旧情况
                if (colors[prv] == colors[idx]) del(prv);
                if (colors[idx] == colors[nxt]) del(idx);
                // 计算新情况
                colors[idx] = col;
                if (colors[prv] == colors[idx]) ins(prv);
                if (colors[idx] == colors[nxt]) ins(idx);
            }
        }
        return ans;
    }
};

class PTest3245 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3245, Test1) {
    Solution s;
    vector<int> colors = {0,1,1,0,1};
    vector<vector<int>> queries = {{2,1,0},{1,4}};
    auto actual = s.numberOfAlternatingGroups(colors, queries);
    decltype(actual) expect = {2};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3245, Test2) {
    Solution s;
    vector<int> colors = {0,0,1,0,1,1};
    vector<vector<int>> queries = {{1,3},{2,3,0},{1,5}};
    auto actual = s.numberOfAlternatingGroups(colors, queries);
    decltype(actual) expect = {2,0};
    EXPECT_EQ(expect, actual);
}
}


