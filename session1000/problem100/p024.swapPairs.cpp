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
    ListNode* swapPairs(ListNode* head) {
        ListNode ans(0, head);
        for (ListNode *p = &ans; p->next && p->next->next; p = p->next->next) {
            ListNode *q = p->next;
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = q;
        }
        return ans.next;
    }
};

class P024Test : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P024Test, Test1) {
    Solution s;
    auto head = ListNode::createListNode({1,2,3,4});
    auto act = s.swapPairs(head);
    auto actual = act->getData();
    decltype(actual) expect = {2,1,4,3};
    EXPECT_EQ(expect, actual);
}
TEST_F(P024Test, Test2) {
    Solution s;
    auto head = ListNode::createListNode({});
    auto act = s.swapPairs(head);
    auto actual = act->getData();
    decltype(actual) expect = {};
    EXPECT_EQ(expect, actual);
}
TEST_F(P024Test, Test3) {
    Solution s;
    auto head = ListNode::createListNode({1});
    auto act = s.swapPairs(head);
    auto actual = act->getData();
    decltype(actual) expect = {1};
    EXPECT_EQ(expect, actual);
}
}


