#include <gtest/gtest.h>
#include <unordered_set>

using namespace std;

namespace {

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int result = 0;
        int n = favorite.size();
        vector<vector<int>> children(n);
        for (int i = 0; i < n; ++i) {
            children[favorite[i]].push_back(i);
        }
        vector<bool> visited(n);

        auto getLevel = [&](int i, int ex) {
            vector<int> q = {i};
            int level = 0;
            while (!q.empty()) {
                level += 1;
                vector<int> nq;
                for (int qq : q) {
                    if (!children[qq].empty())
                        for (int child : children[qq]) {
                            if (child == ex) continue;
                            visited[child] = true;
                            nq.push_back(child);
                        }
                }
                q = std::move(nq);
            }
            return level - 1;
        };

        auto  traverse = [&](int i) {
            int j = i;
            while (not visited[j]) {
                visited[j] = true;
                j = favorite[j];
            }
            unordered_set<int> circle;
            circle.insert(j);
            int k = favorite[j];
            while (k != j) {
                circle.insert(k);
                k = favorite[k];
            }
            if (circle.size() == 2) {
                result += 2;
                for (int i : circle) {
                    result +=  getLevel(favorite[i], i);
                }
                return result;
            } else {
                int r = circle.size();
                for (int i : circle) {
                    getLevel(favorite[i], i);
                }
                return r;
            }
        };

        int r = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int rr = traverse(i);
            r = max(r, rr);
        }
        return max(result, r);
    }
};

class Solution2 {
public:
    int maximumInvitations(vector<int>& favorite) {
        result = 0;
        int n = favorite.size();
        vector<vector<int>> children(n);
        for (int i = 0; i < n; ++i) {
            children[favorite[i]].push_back(i);
        }
        vector<bool> visited(n);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int rr = traverse(favorite, children, visited, i);
            r = max(r, rr);
        }
        return max(result, r);
    }
    int traverse(vector<int>& favorite, vector<vector<int>> &children, vector<bool> &visited, int i) {
        int j = i;
        while (not visited[j]) {
            visited[j] = true;
            j = favorite[j];
        }
        unordered_set<int> circle;
        circle.insert(j);
        int k = favorite[j];
        while (k != j) {
            circle.insert(k);
            k = favorite[k];
        }
        if (circle.size() == 2) {
            result += 2;
            for (int i : circle) {
                result +=  getLevel(children, visited, favorite[i], i);
            }
            return result;
        } else {
            int r = circle.size();
            for (int i : circle) {
                getLevel(children, visited, favorite[i], i);
            }
            return r;
        }
    }
    int getLevel(vector<vector<int>> &children, vector<bool> &visited, int i, int ex) {
        vector<int> q = {i};
        int level = 0;
        while (!q.empty()) {
            level += 1;
            vector<int> nq;
            for (int qq : q) {
                if (!children[qq].empty())
                    for (int child : children[qq]) {
                        if (child == ex) continue;
                        visited[child] = true;
                        nq.push_back(child);
                    }
            }
            q = std::move(nq);
        }
        return level - 1;
    }

private:
    int result;
};

class P2127Test :public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};


TEST_F(P2127Test, Test1)
{
    vector<int> favorite = { 2,2,1,2 };
    Solution s;
    auto actual = s.maximumInvitations(favorite);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2127Test, Test2)
{
    vector<int> favorite = { 1, 2, 0 };
    Solution s;
    auto actual = s.maximumInvitations(favorite);
    decltype(actual) expect = 3;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2127Test, Test3)
{
    vector<int> favorite = { 3,0,1,4,1};
    Solution s;
    auto actual = s.maximumInvitations(favorite);
    decltype(actual) expect = 4;
    EXPECT_EQ(expect, actual);
}
TEST_F(P2127Test, Test4)
{
    vector<int> favorite = { 1,0,0,2,1,4,7,8,9,6,7,10,8};
    Solution s;
    auto actual = s.maximumInvitations(favorite);
    decltype(actual) expect = 6;
    EXPECT_EQ(expect, actual);
}
}
