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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode ans(0, head);
        ListNode *p = &ans;
        while (p) {
            ListNode *q = p->next;
            int i = 0;
            for (; i < k && q; ++i, q = q->next);
            if (i < k) break;
            auto np = p->next;
            auto x = p->next;
            for (i = 0; i < k; ++i) {
                auto nx = x->next;
                x->next = p->next;
                p->next = x;
                x = nx;
            }
            p = np;
            np->next = q;
        }
        return ans.next;
    }
};
class P025Test : public testing::Test {
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(P025Test, Test1) {
    Solution s;
    auto head = ListNode::createListNode({1,2,3,4,5});
    auto act = s.reverseKGroup(head, 2);
    auto actual = act->getData();
    decltype(actual) expect = {2,1,4,3,5};
    EXPECT_EQ(expect, actual);
}
TEST_F(P025Test, Test2) {
    Solution s;
    auto head = ListNode::createListNode({1,2,3,4,5});
    auto act = s.reverseKGroup(head, 3);
    auto actual = act->getData();
    decltype(actual) expect = {3,2,1,4,5};
    EXPECT_EQ(expect, actual);
}

}


