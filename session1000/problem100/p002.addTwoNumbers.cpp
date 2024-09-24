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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ans(0, l1);
        l1 = &ans;
        int flag = 0;
        while (l1->next && l2) {
            l1->next->val += l2->val + flag;
            if (l1->next->val >= 10) {
                l1->next->val -= 10;
                flag = 1;
            } else {
                flag = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) {
            l1->next = l2;
        }
        while (l1->next) {
            l1->next->val += flag;
            if (l1->next->val >= 10) {
                l1->next->val -= 10;
                flag = 1;
            } else {
                flag = 0;
            }
            l1 = l1->next;
        }
        if (flag) {
            l1->next = new ListNode(flag);
        }
        return ans.next;
    }
};

class PTest : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest, Test1) {
    Solution s;
    auto l1 = ListNode::createListNode({2,4,3});
    auto l2 = ListNode::createListNode({5,6,4});
    auto act = s.addTwoNumbers(l1, l2);
    auto actual = act->getData();
    decltype(actual) expect = {7,0,8};
    EXPECT_EQ(expect, actual);
}

}


