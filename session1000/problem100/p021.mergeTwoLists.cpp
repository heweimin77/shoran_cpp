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

class P021Test : public testing::Test
{
public:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(P021Test, Test1)
{
    Solution s;
    auto l1 = ListNode::createListNode({1,2,4});
    auto l2 = ListNode::createListNode({1,3,4});
    auto act = s.mergeTwoLists(l1, l2);
    vector<int> actual = act->getData();
    decltype(actual) expect = {1,1,2,3,4,4};
    EXPECT_EQ(expect, actual);
}

}


