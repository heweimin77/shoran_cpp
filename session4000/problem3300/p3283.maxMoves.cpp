#include <gtest/gtest.h>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;

namespace {

class Solution {
    static constexpr int dirs[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        int dis[n][50][50];
        memset(dis, -1, sizeof(dis));
        for (int i = 0; i < n; i++) {
            int px = positions[i][0], py = positions[i][1];
            dis[i][px][py] = 0;
            vector<pair<int, int>> q = {{px, py}};
            for (int step = 1; !q.empty(); step++) {
                vector<pair<int, int>> tmp;
                for (auto& [qx, qy] : q) {
                    for (auto& dir : dirs) {
                        int x = qx + dir[0], y = qy + dir[1];
                        if (0 <= x && x < 50 && 0 <= y && y < 50 && dis[i][x][y] < 0) {
                            dis[i][x][y] = step;
                            tmp.emplace_back(x, y);
                        }
                    }
                }
                q = move(tmp);
            }
        }

        positions.push_back({kx, ky});
        int distances[n][16];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                distances[i][j] = dis[i][positions[j][0]][positions[j][1]];
            }
        }

        vector<vector<int>> cache(n + 1, vector<int>(1 << n ));
        function<int(int, int, bool)> jump = [&](int flag, int now, bool alice) {
            if (flag == 0) return 0;
            if (cache[now][flag] != 0) return cache[now][flag];
            if (alice) {
                int r = 0;
                for (int i = 0, mask = 1; mask <= flag; ++i, mask <<= 1) {
                    if (mask & flag) {
                        r = max(r, distances[i][now] + jump(flag & ~mask, i, !alice));
                    }
                }
                cache[now][flag] = r;
            } else {
                if (cache[now][flag] != 0) return cache[now][flag];
                int r = INT32_MAX;
                for (int i = 0, mask = 1; mask <= flag; ++i, mask <<= 1) {
                    if (mask & flag) {
                        r = min(r, distances[i][now] + jump(flag & ~mask, i, !alice));
                    }
                }
                cache[now][flag] = r;
            }
            return cache[now][flag];
        };

        return jump((1 << n) - 1, n, true);
    }
};

class SolutionOK2 {
    static constexpr int dirs[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        int dis[n][50][50];
        memset(dis, -1, sizeof(dis));
        // 计算马到兵的步数，等价于计算兵到其余格子的步数
        for (int i = 0; i < n; i++) {
            int px = positions[i][0], py = positions[i][1];
            dis[i][px][py] = 0;
            vector<pair<int, int>> q = {{px, py}};
            for (int step = 1; !q.empty(); step++) {
                vector<pair<int, int>> tmp;
                for (auto& [qx, qy] : q) {
                    for (auto& dir : dirs) {
                        int x = qx + dir[0], y = qy + dir[1];
                        if (0 <= x && x < 50 && 0 <= y && y < 50 && dis[i][x][y] < 0) {
                            dis[i][x][y] = step;
                            tmp.emplace_back(x, y);
                        }
                    }
                }
                q = move(tmp);
            }
        }

        positions.push_back({kx, ky});
        int distances[n][16];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                distances[i][j] = dis[i][positions[j][0]][positions[j][1]];
            }
        }

        //unordered_map<int,int> alicecache, bobcache;
        vector<vector<int>> cache(n + 1, vector<int>(1 << n ));
        function<int(int, int)> alice, bob;
        alice = [&](int flag, int now) {
            if (flag == 0) return 0;
            if (cache[now][flag] != 0) return cache[now][flag];
            int r = 0;
            for (int i = 0, mask = 1; mask <= flag; ++i, mask <<= 1) {
                if (mask & flag) {
                    r = max(r, distances[i][now] + bob(flag & ~mask, i));
                }
            }
            cache[now][flag] = r;
            return r;
        };
        bob = [&](int flag, int now) {
            if (flag == 0) return 0;
            if (cache[now][flag] != 0) return cache[now][flag];
            int r = INT32_MAX;
            for (int i = 0, mask = 1; mask <= flag; ++i, mask <<= 1) {
                if (mask & flag) {
                    r = min(r, distances[i][now] + alice(flag & ~mask, i));
                }
            }
            cache[now][flag] = r;
            return r;
        };

        return alice((1 << n)-1, n);
    }
};

class SolutionOK {
    static constexpr int dirs[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        int dis[n][50][50];
        memset(dis, -1, sizeof(dis));
        // 计算马到兵的步数，等价于计算兵到其余格子的步数
        for (int i = 0; i < n; i++) {
            int px = positions[i][0], py = positions[i][1];
            dis[i][px][py] = 0;
            vector<pair<int, int>> q = {{px, py}};
            for (int step = 1; !q.empty(); step++) {
                vector<pair<int, int>> tmp;
                for (auto& [qx, qy] : q) {
                    for (auto& dir : dirs) {
                        int x = qx + dir[0], y = qy + dir[1];
                        if (0 <= x && x < 50 && 0 <= y && y < 50 && dis[i][x][y] < 0) {
                            dis[i][x][y] = step;
                            tmp.emplace_back(x, y);
                        }
                    }
                }
                q = move(tmp);
            }
        }

        positions.push_back({kx, ky});
        vector<vector<int>> memo(n + 1, vector<int>(1 << n, -1)); // -1 表示没有计算过
        int u = (1 << n) - 1;
        function<int(int,int, bool)> dfs = [&](int i, int mask, bool alice) -> int {
            if (mask == 0) {
                return 0;
            }
            int& res = memo[i][mask]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            int x = positions[i][0], y = positions[i][1];
            if (alice) { // Alice 操作
                for (int j = 0; j < n; j++) {
                    if (mask >> j & 1) {
                        res = max(res, dfs(j, mask ^ (1 << j), !alice) + dis[j][x][y]);
                    }
                }
            } else { // Bob 操作
                res = INT_MAX;
                for (int j = 0; j < n; j++) {
                    if (mask >> j & 1) {
                        res = min(res, dfs(j, mask ^ (1 << j), !alice) + dis[j][x][y]);
                    }
                }
            }
            return res;
        };
        return dfs(n, u, true);
    }
};

class Solution557of692 {
#define MAKE_KEY(p)  ((p[0] << 8) | (p[1]))
#define MAKE_KEY2(x, y) ((x) << 16 | (y))

    static constexpr int MAX = 50;
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.push_back({kx, ky});
        int n = positions.size();
        unordered_map<int,int> indexes;
        for (int i = 0; i < n; ++i) {
            indexes[MAKE_KEY(positions[i])] = i;
        }
        vector<vector<int>> dds = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        auto get_distance = [&](vector<int>& ps) {
            vector<int> ds(n);
            queue<vector<int>> q;
            unordered_set<int> visited;
            q.push({ps[0], ps[1], 0});
            visited.insert(MAKE_KEY(ps));
            ds[indexes[MAKE_KEY(ps)]] = 0;
            int xcnt = n - 1;
            while (xcnt > 0 && !q.empty()) {
                auto now = q.front();
                q.pop();
                for (auto &dd : dds) {
                    vector<int> next = {now[0] + dd[0], now[1] + dd[1], now[2] + 1};
                    if (next[0] < 0 || next[0] >= MAX) continue;
                    if (next[1] < 0 || next[1] >= MAX) continue;
                    int nkey = MAKE_KEY(next);
                    if (visited.count(nkey) > 0) continue;
                    visited.insert(nkey);
                    q.push(next);
                    auto it = indexes.find(nkey);
                    if (it != indexes.end()) {
                        --xcnt;
                        ds[it->second] = next[2];
                    }
                }
            }
            return ds;
        };

        vector<vector<int>> distances;
        for (auto &ps : positions) {
            distances.push_back(get_distance(ps));
        }

        //unordered_map<int,int> alicecache, bobcache;
        vector<vector<int>> cache(n, vector<int>(1 << (n - 1)));
        function<int(int, int)> alice, bob;
        alice = [&](int flag, int now) {
            if (flag == 0) return 0;
            if (cache[now][flag] != 0) return cache[now][flag];
            int r = 0;
            for (int i = 0, mask = 1; mask <= flag; ++i, mask <<= 1) {
                if (mask & flag) {
                    r = max(r, distances[now][i] + bob(flag & ~mask, i));
                }
            }
            cache[now][flag] = r;
            return r;
        };
        bob = [&](int flag, int now) {
            if (flag == 0) return 0;
            if (cache[now][flag] != 0) return cache[now][flag];
            int r = INT32_MAX;
            for (int i = 0, mask = 1; mask <= flag; ++i, mask <<= 1) {
                if (mask & flag) {
                    r = min(r, distances[now][i] + alice(flag & ~mask, i));
                }
            }
            cache[now][flag] = r;
            return r;
        };

        return alice((1 << (n-1))-1, n - 1);
    }
};

class Solution630of692 {
#define MAKE_KEY(p)  ((p[0] << 8) | (p[1]))
#define MAKE_KEY2(x, y) ((x) << 16 | (y))

    static constexpr int MAX = 50;
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.push_back({kx, ky});
        int n = positions.size() - 1;
        unordered_map<int,int> indexes;
        for (int i = 0; i <= n; ++i) {
            indexes[MAKE_KEY(positions[i])] = i;
        }
        vector<vector<int>> dds = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        auto get_distance = [&](vector<int>& ps) {
            vector<int> ds(n + 1);
            queue<vector<int>> q;
            unordered_set<int> visited;
            q.push({ps[0], ps[1], 0});
            visited.insert(MAKE_KEY(ps));
            ds[indexes[MAKE_KEY(ps)]] = 0;
            int xcnt = n;
            while (xcnt > 0 && !q.empty()) {
                auto now = q.front();
                q.pop();
                for (auto &dd : dds) {
                    vector<int> next = {now[0] + dd[0], now[1] + dd[1], now[2] + 1};
                    if (next[0] < 0 || next[0] >= MAX) continue;
                    if (next[1] < 0 || next[1] >= MAX) continue;
                    int nkey = MAKE_KEY(next);
                    if (visited.count(nkey) > 0) continue;
                    visited.insert(nkey);
                    q.push(next);
                    auto it = indexes.find(nkey);
                    if (it != indexes.end()) {
                        --xcnt;
                        ds[it->second] = next[2];
                    }
                }
            }
            return ds;
        };

        vector<vector<int>> distances;
        for (auto &ps : positions) {
            distances.push_back(get_distance(ps));
        }

        int FINISH = 1 << n;
        vector<vector<int>> answers(n, vector<int>(FINISH, -1));
        unordered_set<int> nows;
        for (int i = 0; i < n; ++i) {
            answers[i][1 << i] = 0;
            nows.insert(MAKE_KEY2(i, 1 << i));
        }
        bool alice = (n & 1);
        while (!nows.empty()) {
            if (alice) {
                unordered_set<int> nexts;
                for (int now : nows) {
                    int nn = now >> 16, flag = now & 0xFFFF;
                    for (int j = 0; j < n ; ++j) {
                        int mask = 1 << j;
                        if (mask & flag) continue;
                        int nfalg = mask | flag;
                        if (answers[j][nfalg] == -1) {
                            answers[j][nfalg] = answers[nn][flag] + distances[nn][j];
                        } else {
                            answers[j][nfalg] = max(answers[j][nfalg], answers[nn][flag] + distances[nn][j]);
                        }
                        nexts.insert(MAKE_KEY2(j, nfalg));
                    }
                }
                nows = std::move(nexts);
            } else {
                // bobs
                unordered_set<int> nexts;
                for (int now : nows) {
                    int nn = now >> 16, flag = now & 0xFFFF;
                    for (int j = 0; j < n; ++j) {
                        int mask = 1 << j;
                        if (mask & flag) continue;
                        int nfalg = mask | flag;
                        if (answers[j][nfalg] == -1) {
                            answers[j][nfalg] = answers[nn][flag] + distances[nn][j];
                        } else {
                            answers[j][nfalg] = min(answers[j][nfalg], answers[nn][flag] + distances[nn][j]);
                        }
                        nexts.insert(MAKE_KEY2(j, nfalg));
                    }
                }

                nows = std::move(nexts);
            }
            alice = !alice;
        }
        int answer = 0;
        for (int j = 0; j < n; ++j) {
            answer = max(answer, answers[j][FINISH-1] + distances[j][n]);
        }
        return answer;
    }
};

class Solution652of692 {
#define MAKE_KEY(p)  ((p[0] << 8) | (p[1]))
#define MAKE_KEY2(x, y) ((x) << 16 | (y))

static constexpr int MAX = 50;
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.push_back({kx, ky});
        int n = positions.size();
        unordered_map<int,int> indexes;
        for (int i = 0; i < n; ++i) {
            indexes[MAKE_KEY(positions[i])] = i;
        }
        vector<vector<int>> dds = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        auto get_distance = [&](vector<int>& ps) {
            vector<int> ds(n);
            queue<vector<int>> q;
            unordered_set<int> visited;
            q.push({ps[0], ps[1], 0});
            visited.insert(MAKE_KEY(ps));
            ds[indexes[MAKE_KEY(ps)]] = 0;
            int xcnt = n - 1;
            while (xcnt > 0 && !q.empty()) {
                auto now = q.front();
                q.pop();
                for (auto &dd : dds) {
                    vector<int> next = {now[0] + dd[0], now[1] + dd[1], now[2] + 1};
                    if (next[0] < 0 || next[0] >= MAX) continue;
                    if (next[1] < 0 || next[1] >= MAX) continue;
                    int nkey = MAKE_KEY(next);
                    if (visited.count(nkey) > 0) continue;
                    visited.insert(nkey);
                    q.push(next);
                    auto it = indexes.find(nkey);
                    if (it != indexes.end()) {
                        --xcnt;
                        ds[it->second] = next[2];
                    }
                }
            }
            return ds;
        };

        vector<vector<int>> distances;
        for (auto &ps : positions) {
            distances.push_back(get_distance(ps));
        }

        unordered_map<int,int> alicecache, bobcache;
        function<int(int, int)> alice, bob;
        alice = [&](int flag, int now) {
            if (flag == 0) return 0;
            int key = MAKE_KEY2(flag, now);
            if (alicecache.find(key) != alicecache.end()) return alicecache[key];
            int r = 0;
            for (int i = 0, mask = 1; mask <= flag; ++i, mask <<= 1) {
                if (mask & flag) {
                    r = max(r, distances[now][i] + bob(flag & ~mask, i));
                }
            }
            alicecache[key] = r;
            return r;
        };
        bob = [&](int flag, int now) {
            if (flag == 0) return 0;
            int key = MAKE_KEY2(flag, now);
            if (bobcache.find(key) != bobcache.end()) return bobcache[key];
            int r = INT32_MAX;
            for (int i = 0, mask = 1; mask <= flag; ++i, mask <<= 1) {
                if (mask & flag) {
                    r = min(r, distances[now][i] + alice(flag & ~mask, i));
                }
            }
            bobcache[key] = r;
            return r;
        };

        return alice((1 << (n-1))-1, n - 1);
    }
};

class P3283Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P3283Test, Test1)
{
    Solution s;
    int kx = 1, ky = 1;
    vector<vector<int>> positions = {{0,0}};
    auto actual = s.maxMoves(kx, ky, positions);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3283Test, Test2)
{
    Solution s;
    int kx = 0, ky = 2;
    vector<vector<int>> positions = {{1,1},{2,2},{3,3}};
    auto actual = s.maxMoves(kx, ky, positions);
    decltype(actual) expect = 8;
    EXPECT_EQ(expect, actual);
}
TEST_F(P3283Test, Test3)
{
    Solution s;
    int kx = 0, ky = 0;
    vector<vector<int>> positions = {{1,2},{2,4}};
    auto actual = s.maxMoves(kx, ky, positions);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
}


