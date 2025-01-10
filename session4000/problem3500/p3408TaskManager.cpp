#include <gtest/gtest.h>

using namespace std;

namespace {
static auto autorun = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();
class TaskManager {
    using Task = std::array<int, 3>;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            ptasks.insert({t[2], t[1], t[0]});
            taskInfos[t[1]] = {t[2], t[0]};
        }
    }

    void add(int userId, int taskId, int priority) {
        ptasks.insert({priority, taskId, userId});
        taskInfos[taskId] = {priority, userId};
    }

    void edit(int taskId, int newPriority) {
        auto &info = taskInfos[taskId];
        Task t{info.first, taskId, info.second};
        ptasks.erase(ptasks.find(t));
        taskInfos[taskId] = {newPriority, t[2]};
        t[0] = newPriority;
        ptasks.insert(t);
    }

    void rmv(int taskId) {
        auto &info = taskInfos[taskId];
        Task t{info.first, taskId, info.second};
        ptasks.erase(ptasks.find(t));
        taskInfos.erase(taskInfos.find(taskId));
    }

    int execTop() {
        if (ptasks.empty()) return -1;
        Task t = *ptasks.rbegin();
        rmv(t[1]);
        return t[2];
    }

private:
    std::set<Task> ptasks;
    unordered_map<int, pair<int,int>> taskInfos;
};

class PTest3408 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3408, Test1) {
    vector<vector<int>> tasks = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager taskManager(tasks); // 分别给用户 1 ，2 和 3 初始化一个任务。
    taskManager.add(4, 104, 5); // 给用户 4 添加优先级为 5 的任务 104 。
    taskManager.edit(102, 8); // 更新任务 102 的优先级为 8 。
    EXPECT_EQ(3, taskManager.execTop()); // 返回 3 。执行用户 3 的任务 103 。
    taskManager.rmv(101); // 将系统中的任务 101 删除。
    taskManager.add(5, 105, 15); // 给用户 5 添加优先级为 15 的任务 105 。
    EXPECT_EQ(5, taskManager.execTop()); // 返回 5 。执行用户 5 的任务 105 。
}
}


