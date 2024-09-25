#include <gtest/gtest.h>
#include <unordered_set>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode ans(0, head);
        ListNode *p = &ans;
        unordered_set<int> ns;
        for (auto n : nums) ns.insert(n);
        while (p->next) {
            if (ns.contains(p->next->val)) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return ans.next;
    }
};

class PTest3217 : public testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(PTest3217, Test1) {
    Solution s;
    vector<int> nums = {1,2,3};
    ListNode* head = ListNode::createListNode({1,2,3,4,5});
    auto act = s.modifiedList(nums, head);
    auto actual = act->getData();
    decltype(actual) expect = {4,5};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3217, Test2) {
    Solution s;
    vector<int> nums = {1};
    ListNode* head = ListNode::createListNode({1,2,1,2,1,2});
    auto act = s.modifiedList(nums, head);
    auto actual = act->getData();
    decltype(actual) expect = {2,2,2};
    EXPECT_EQ(expect, actual);
}
TEST_F(PTest3217, Test3) {
    Solution s;
    vector<int> nums = {5};
    ListNode* head = ListNode::createListNode({1,2,3,4});
    auto act = s.modifiedList(nums, head);
    auto actual = act->getData();
    decltype(actual) expect = {1,2,3,4};
    EXPECT_EQ(expect, actual);
}
}


