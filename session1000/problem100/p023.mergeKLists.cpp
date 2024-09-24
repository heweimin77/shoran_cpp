#include <gtest/gtest.h>
#include "ListNode.h"

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1) {
            if (lists.size() & 1) {
                lists.push_back(nullptr);
            }
            int j = 0;
            for (int i = 0; i < lists.size(); i += 2) {
                lists[j++] = mergeTwoLists(lists[i], lists[i+1]);
            }
            lists.resize(lists.size()/2);
        }
        return lists[0];
    }
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode *answer = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            answer = mergeTwoLists(answer, lists[i]);
        }
        return answer;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode ans;
        ListNode *p = &ans;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = (list1) ? list1 : list2;
        return ans.next;
    }
};

class P023Test : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P023Test, Test1) {
    Solution s;
    vector<vector<int>> data = {{1,4,5},{1,3,4},{2,6}};
    vector<ListNode*> lists;
    for (auto & d : data) {
        lists.push_back(ListNode::createListNode(d));
    }
    auto acts = s.mergeKLists(lists);
    auto actual = acts->getData();
    decltype(actual) expect = {1,1,2,3,4,4,5,6};
    EXPECT_EQ(expect, actual);
}
TEST_F(P023Test, Test2) {
    Solution s;
    vector<vector<int>> data = {};
    vector<ListNode*> lists;
    for (auto & d : data) {
        lists.push_back(ListNode::createListNode(d));
    }
    auto acts = s.mergeKLists(lists);
    auto actual = acts->getData();
    decltype(actual) expect = {};
    EXPECT_EQ(expect, actual);
}
TEST_F(P023Test, Test3) {
    Solution s;
    vector<vector<int>> data = {{}};
    vector<ListNode*> lists;
    for (auto & d : data) {
        lists.push_back(ListNode::createListNode(d));
    }
    auto acts = s.mergeKLists(lists);
    auto actual = acts->getData();
    decltype(actual) expect = {};
    EXPECT_EQ(expect, actual);
}
}


