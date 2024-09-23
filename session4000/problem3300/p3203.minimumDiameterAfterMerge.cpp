#include <gtest/gtest.h>

using namespace std;

namespace {
class AutoRun {
public:
    AutoRun() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
} autorun;
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> r1 = get_max(edges1);
        vector<int> r2 = get_max(edges2);
        int ans = max(r1[0], r2[0]);
        return max(ans, 1 + r1[1] + r2[1]);
    }

    vector<int> get_max(vector<vector<int>>& edges) {
        if (edges.empty()) return vector<int>({0, 0});
        int n = edges.size() + 1;
        vector<vector<int>> adjs(n);
        for (auto &e : edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }
        int distances[n + 1];
        function<void(int,int)> cal_distance = [&](int now, int parent) {
            int r = 0;
            for (int child : adjs[now]) {
                if (child == parent) continue;
                cal_distance(child, now);
                r = max(r, distances[child] + 1);
            }
            distances[now] = r;
        };
        cal_distance(0, -1);
        distances[n] = -1;

        int r1 = distances[0], r2 = distances[0];
        int now = 0;
        while (true) {
            int mnext1 = n, mnext2 = n;
            for (int child : adjs[now]) {
                if (distances[child] > distances[mnext1]) {
                    mnext2 = mnext1;
                    mnext1 = child;
                }  else if (distances[child] > distances[mnext2]) {
                    mnext2 = child;
                }
            }
            r1 = max(r1, distances[mnext1] + distances[mnext2] + 2);
            distances[now] = distances[mnext2] + 1;
            distances[mnext1] = max(distances[mnext1], distances[now] + 1);
            if (distances[mnext1] >= r2) break;
            now = mnext1;
            r2 = distances[now];
        }
        return vector<int>({r1, r2});
    }
};

class Solution721of723 {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> r1 = get_max(edges1);
        vector<int> r2 = get_max(edges2);
        int ans = max(r1[1], r2[1]);
        ans = max(ans, 1 + r1[0] + r2[0]);
        return ans;
    }

    vector<int> get_max(vector<vector<int>>& edges) {
        function<int(unordered_map<int, vector<int>> &, int, int, int)> get_distance = [&](unordered_map<int, vector<int>> &adjs, int now, int parent, int distance) {
            int r = distance;
            for (int child : adjs[now]) {
                if (child == parent) continue;
                r = max(r, get_distance(adjs, child, now, distance + 1));
            }
            return r;
        };
        auto get_max = [&](vector<vector<int>>& edges) ->int {
            if (edges.empty()) return 0;
            unordered_map<int, vector<int>> adjs;
            for (auto &e : edges) {
                adjs[e[0]].push_back(e[1]);
                adjs[e[1]].push_back(e[0]);
            }
            int ans = INT32_MAX;
            for (auto &x : adjs) {
                ans = min(ans, get_distance(adjs, x.first, -1, 0));
            }
            return ans;
        };
        auto get_max2 = [&](vector<vector<int>>& edges) ->int {
            unordered_map<int, vector<int>> adjs;
            for (auto &e : edges) {
                adjs[e[0]].push_back(e[1]);
                adjs[e[1]].push_back(e[0]);
            }
            int ans = 0;
            for (auto &x : adjs) {
                ans = max(ans, get_distance(adjs, x.first, -1, 0));
            }
            return ans;
        };

        if (edges.empty()) return vector<int>({0, 0});
        int n = edges.size() + 1;
        vector<vector<int>> adjs(n);
        for (auto &e : edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }
        vector<int> distance(n, INT32_MAX);
        function<int(int,int)> cal_distance = [&](int now, int parent)->int {
            int r = 0;
            for (int child : adjs[now]) {
                if (child == parent) continue;
                r = max(r, cal_distance(child, now));
            }
            distance[now] = r + 1;
            return r + 1;
        };
        cal_distance(0, -1);

        int r1 = distance[0], r2 = distance[0];
        function<void(int,int)> traverse = [&](int now, int parent) {
            int rmax1 = 0, rmax2 = 0;
            for (int child : adjs[now]) {
                int r = distance[child];
                if (r > rmax1) {
                    rmax2 = rmax1;
                    rmax1 = r;
                } else if (r > rmax2) {
                    rmax2 = r;
                }
            }
            r1 = min(r1, distance[now]);
            r2 = max(r2, distance[now]);
            for (int child : adjs[now]) {
                if (child == parent) continue;
                int rc = distance[child];
                if (rc == rmax1) {
                    distance[now] = rmax2 + 1;
                } else {
                    distance[now] = rmax1 + 1;
                }
                distance[child] = max(distance[child], distance[now] + 1);
                traverse(child, now);
                distance[child] = rc;
            }
            distance[now] = rmax1 + 1;
        };
        traverse(0, -1);
        return vector<int>({r1-1, r2-1});
    }
};
class Solution709of723 {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        function<int(unordered_map<int, vector<int>> &, int, int, int)> get_distance = [&](unordered_map<int, vector<int>> &adjs, int now, int parent, int distance) {
            int r = distance;
            for (int child : adjs[now]) {
                if (child == parent) continue;
                r = max(r, get_distance(adjs, child, now, distance + 1));
            }
            return r;
        };

        auto get_max = [&](vector<vector<int>>& edges) ->int {
            if (edges.empty()) return 0;
            unordered_map<int, vector<int>> adjs;
            for (auto &e : edges) {
                adjs[e[0]].push_back(e[1]);
                adjs[e[1]].push_back(e[0]);
            }
            int ans = INT32_MAX;
            for (auto &x : adjs) {
                ans = min(ans, get_distance(adjs, x.first, -1, 0));
            }
            return ans;
        };
        auto get_max2 = [&](vector<vector<int>>& edges) ->int {
            unordered_map<int, vector<int>> adjs;
            for (auto &e : edges) {
                adjs[e[0]].push_back(e[1]);
                adjs[e[1]].push_back(e[0]);
            }
            int ans = 0;
            for (auto &x : adjs) {
                ans = max(ans, get_distance(adjs, x.first, -1, 0));
            }
            return ans;
        };
        int ans = max(get_max2(edges1), get_max2(edges2));
        ans = max(ans, 1 + get_max(edges1) + get_max(edges2));
        return ans;
    }
};

class P3203Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3203Test, Test1)
{
    Solution s;
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3}};
    vector<vector<int>> edges2 = {{0,1}};
    auto actual = s.minimumDiameterAfterMerge(edges1, edges2);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3203Test, Test2)
{
    Solution s;
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    auto actual = s.minimumDiameterAfterMerge(edges1, edges2);
    decltype(actual) expect = 5;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3203Test, Test3)
{
    Solution s;
    vector<vector<int>> edges1 = {};
    vector<vector<int>> edges2 = {};
    auto actual = s.minimumDiameterAfterMerge(edges1, edges2);
    decltype(actual) expect = 1;
    EXPECT_EQ(expect, actual);
}
}


