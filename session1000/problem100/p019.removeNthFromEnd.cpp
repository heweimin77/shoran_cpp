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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        function<int(ListNode *)> traverse = [&](ListNode *node) {
            if (node == nullptr) return 0;
            int level = traverse(node->next);
            if (level == n) {
                node->next = node->next->next;
            }
            return level + 1;
        };
        ListNode *root = new ListNode(0, head);
        traverse(root);
        return root->next;
    }
};

class P019Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P019Test, Test1)
{
    Solution s;
    ListNode *head = ListNode::createListNode({1, 2, 3, 4, 5});
    int n = 2;
    auto actual = s.removeNthFromEnd(head, n);
    vector<int> avalues = actual->getData();
    decltype(avalues) expect = {1,2,3,5};
    EXPECT_EQ(expect, avalues);
}
TEST_F(P019Test, Test2)
{
    Solution s;
    ListNode *head = ListNode::createListNode({1});
    int n = 1;
    auto actual = s.removeNthFromEnd(head, n);
    vector<int> avalues = actual ? actual->getData() : vector<int>();
    decltype(avalues) expect = {};
    EXPECT_EQ(expect, avalues);
}
TEST_F(P019Test, Tes3)
{
    Solution s;
    ListNode *head = ListNode::createListNode({1, 2});
    int n = 1;
    auto actual = s.removeNthFromEnd(head, n);
    vector<int> avalues = actual->getData();
    decltype(avalues) expect = {1};
    EXPECT_EQ(expect, avalues);
}
}


